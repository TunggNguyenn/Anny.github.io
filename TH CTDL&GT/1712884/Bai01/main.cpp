#include "TuDien.h"


void Menu()
{
	cout << "\n\n";
	cout << "\t\t\tNhap 0: Thoat.\n";
	cout << "\t\t\t     1: Nhap Tu Dien thong qua ban phim.\n";
	cout << "\t\t\t     2: Nhap Tu Dien thong qua file.\n";
	cout << "\t\t\t     3: Xuat toan bo noi dung Tu Dien.\n";
	cout << "\t\t\t     4: Tim nghia tu dien thong qua nhap tu ban phim.\n";
	cout << "\t\t\tInput: ";
}

void Menu1()
{
	cout << "\n\n";
	cout << "\t\tNhap 0: Thoat.\n";
	cout << "\t\t     1: Xuat du lieu ra man hinh.\n";
	cout << "\t\t     2: Xuat du lieu ra file.\n";
	cout << "\t\tInput: ";
}

int main()
{
	TuDien tuDien;
	ifstream  ifopen;
	
	int i;
	do
	{
		Menu();
		cin >> i;

		if (i == 1)
		{
			tuDien.nhapTuDien(cin, cout);
			tuDien.sapXep();
		}
		else if (i == 2)
		{
			char ifTuDien[25];
			cout << "Nhap ten file Tu Dien: ";
			cin >> ifTuDien;
			ifopen.open(ifTuDien, ios::in);
			if (ifopen.fail())
			{
				cout << "File hien thanh khong ton tai. Vui long nhap lai File.!!\n";
			}
			else
			{
				ofstream ofopen1;
				ofopen1.open("RecycleBin.txt", ios::out);

				tuDien.nhapTuDien(ifopen, ofopen1);
				tuDien.sapXep();
			}
		}
		else if (i == 3)
		{
			if (tuDien.layNumberWord() > 0)
			{
				int y;
				do
				{
					Menu1();
					cin >> y;
					if (y == 1)
					{
						cout << "Xuat toan bo noi dung tu dien.\n";
						tuDien.xuatTuDien(cout);
					}
					else if (y == 2)
					{
						char file[25];
						cout << "Nhap ten file can xuat ra: ";
						cin >> file;
						ofstream ofopen;
						ofopen.open(file, ios::out);
						tuDien.xuatTuDien(ofopen);
					}
				} while (y != 0);
			}
			else
			{
				cout << "Hien tai tu dien chua co thong tin. vui long nhap vao tu ban phim hoac lay tu File.\n";
			}

		}
		else if (i == 4)
		{
			if (tuDien.layNumberWord() > 0)
			{
				tuDien.tim();
			}
			else
			{
				cout << "Hien tai tu dien chua co thong tin. vui long nhap vao tu ban phim hoac lay tu File.\n";
			}
		}
	} while (i != 0);


	ifopen.close();
	system("pause");
	return 0;
}