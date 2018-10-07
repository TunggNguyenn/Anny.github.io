#include "TuDien.h"

/*Nhap Name*/
void nhapName(istream &inDevice, char *&Name)
{
	char ch;
	int n = 0;
	char *temp = NULL;
	while (inDevice.get(ch))
	{
		if (ch != '\n')
		{
			n++;
			temp = (char*)realloc(Name, n * sizeof(char));
			temp[n - 1] = ch;
			Name = temp;
		}
		else
		{
			n++;
			temp = (char*)realloc(Name, n * sizeof(char));
			temp[n - 1] = '\0';
			Name = temp;
			return;
		}
	}
}




/*Nhap Meaning*/
void nhapMeaning(istream &inDevice, char *&Meaning)
{
	char ch;
	int n = 0;
	char *temp = NULL;
	while (inDevice.get(ch) || !inDevice.eof())
	{
		if (ch != '\n')
		{
			n++;
			temp = (char*)realloc(Meaning, n * sizeof(char));
			temp[n - 1] = ch;
			Meaning = temp;
		}
		else if (ch == '\n')
		{
			n++;
			temp = (char*)realloc(Meaning, n * sizeof(char));
			temp[n - 1] = '\0';
			Meaning = temp;
			return;
		}
	}
	n++;
	temp = (char*)realloc(Meaning, n * sizeof(char));
	temp[n - 1] = '\0';
	Meaning = temp;
}



/*Ham hoan doi 2 chuoi string*/
void Swap(char word1[], char word2[])
{
	int length = strlen(word1);
	char *temp = (char*)calloc(length, sizeof(char));
	strcpy(temp, word1);
	strcpy(word1, word2);
	strcpy(word2, temp);
}


/*Thuat toan quick sort sap xep tren bien con tro chuoi ky tu char* */
void strQuickSort(char *Name[], char *Meaning[], int l, int r)
{
	int length = strlen(Name[(l + r) / 2]);
	char *key = NULL;
	key = (char*)calloc(length, sizeof(char));

	strcpy(key, Name[(l + r) / 2]);

	int i = l;
	int j = r;
	do
	{
		while (strcmp(Name[i], key) < 0)
		{
			i++;
		}
		while (strcmp(Name[j], key) > 0)
		{
			j--;
		}

		if (i <= j)
		{
			Swap(Name[i], Name[j]);
			Swap(Meaning[i], Meaning[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (l < j)
	{
		strQuickSort(Name, Meaning, l, j);
	}
	if (r > i)
	{
		strQuickSort(Name, Meaning, i, r);
	}

}

/*Thuat toan BinarySearch tim kiem tren bien con tro chuoi ky tu char* */
char* strBinarySearch(char **Name, char **Meaning, int NumberWord, char *word)
{
	int l = 0, r = NumberWord - 1;
	int mid;
	do
	{
		mid = (int)(l + r) / 2;
		if (strcmp(Name[mid], word) == 0)
		{
			return Meaning[mid];
		}
		else if (strcmp(Name[mid], word) > 0)
		{
			r = mid - 1;
		}
		else 
		{
			l = mid + 1;
		}
	} while (l <= r);

	return "Tu ban can tim khong co trong tu dien.!!";
}

TuDien::TuDien()
{
	this->NumberWord = 0;
	this->Name = NULL;
	this->Meaning = NULL;
}


TuDien::~TuDien()
{
	if (this->NumberWord > 0)
	{
		for (int i = 0; i < this->NumberWord; i++)
		{
			delete[] this->Name[i];
			delete[] this->Meaning[i];
		}
		delete[] this->Name;
		delete[] this->Meaning;
	}
}

/*Lay NumberWord*/
int TuDien::layNumberWord()
{
	return this->NumberWord;
}

/*Nhap tu dien*/
void TuDien::nhapTuDien(istream &inDevice, ostream &outDevice)
{
	outDevice << "Nhap so luong tu dien: ";
	inDevice >> this->NumberWord;
	this->Name = (char**)calloc(this->NumberWord, this->NumberWord * sizeof(char*));
	this->Meaning = (char**)calloc(this->NumberWord, this->NumberWord * sizeof(char*));
	outDevice << "Nhap noi dung tu dien.\n";
	inDevice.ignore(2000, '\n');
	for (int i = 0; i < this->NumberWord; i++)
	{
		outDevice << "Tu: ";
		nhapName(inDevice, Name[i]);
		outDevice << "Nghia: ";
		nhapMeaning(inDevice, Meaning[i]);

	}

}

/*Xuat tu dien*/
void TuDien::xuatTuDien(ostream &outDevice)
{
	outDevice << setw(20) << left;
	outDevice << "Tu/Word: ";
	outDevice << setw(80) << left;
	outDevice << "Nghia/Meaning: " << endl;
	for (int i = 0; i < this->NumberWord; i++)
	{
		outDevice << setw(20) << left;
		outDevice << this->Name[i];
		outDevice << setw(80) << left;
		outDevice << this->Meaning[i] << endl;
	}
}


/*Ham sap xep*/
void TuDien::sapXep()
{
	strQuickSort(this->Name, this->Meaning, 0, this->NumberWord - 1);
}


/*Ham tim kiem*/
void TuDien::tim()
{
	char *word = NULL;
	cout << "Nhap tu ban can tim: ";
	char ch;
	int n = 0;
	char *temp = NULL;
	cin.ignore(2000, '\n');
	while (cin.get(ch))
	{
		if (ch != '\n')
		{
			n++;
			temp = (char*)realloc(word, n * sizeof(char));
			temp[n - 1] = ch;
			word = temp;
		}
		else
		{
			n++;
			temp = (char*)realloc(word, n * sizeof(char));
			temp[n - 1] = '\0';
			word = temp;
			break;
		}
	}
	char *result = strBinarySearch(this->Name, this->Meaning, this->NumberWord, word);
	cout << "Nghia/Meaning: " << result << endl;
}
