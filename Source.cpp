// Lab_08_1.cpp 
// < Базарник Максим > 
// Лабораторна робота № 8.1 
// Варіант 1

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int Count(char* s)
{
	char* t = s;
	int k = 0;
	int pos = 0;

	while ((t = strpbrk(t, "no")) != NULL)
	{
		if ((t[pos] == 'n' && t[pos + 1] == 'o') || (t[pos] == 'o' && t[pos + 1] == 'n')) {
			k++;
		}
		t++;
	}

	return k;
}

char* Change(char* s)
{
	char* r = s;
	int pos = 0;
	char* t = new char[256];

	while ((s = strpbrk(s + pos, "no")) != NULL)
	{
		pos = 0;
		if (s[pos] == 'n' && s[pos + 1] == 'o') 
		{
			strcpy(t, s + 2);
			s[0] = '\0';
			strcat(s, "***");
			strcat(s, t);
		}
		else
			pos++;
	}

	return r;
}

int main()
{
	char str[128];

	cout << "Enter string : ";
	cin.getline(str, 128);

	cout << "String contained " << Count(str) << " groups of 'no' or 'on'" << endl;

	char* dest1 = new char[128];

	dest1 = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest1 << endl;

	return 0;
}
