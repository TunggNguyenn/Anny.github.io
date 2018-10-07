#ifndef __TUDIEN_H__
#define __TUDIEN_H__
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;


class TuDien
{
private:
	int NumberWord;
	char* *Name;
	char* *Meaning;
public:
	TuDien();
	~TuDien();


	int layNumberWord();
	void nhapTuDien(istream &inDevice, ostream &outDevice);
	void xuatTuDien(ostream &outDevice);
	void sapXep();
	void tim();
};


#endif // !__TUDIEN_H__