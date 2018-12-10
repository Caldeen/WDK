// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
using namespace std;
string encode(string in, string k) {
	string sout = in;
	int key_i = 0;
	for (int i = 0;i < (int)in.length();i++) {
		cout << (int)in[i];
		cout << " ";
		if (in[i] != ' ') {
			if (key_i == (int)k.length())
				key_i = 0;
			sout[i] = ((int)in[i] - 97 + (int)k[key_i] - 97) % 26 + 97;
			key_i++;
		}

	}
	cout << endl << in.length() << endl;
	return sout;
}
string decode(string in, string k) {
	string sout = in;
	int c;
	int key_i = 0;
	for (int i = 0;i < (int)in.length();i++) {
		cout << (int)in[i];
		cout << " ";
		if (in[i] != ' ') {
			if (key_i == (int)k.length())
				key_i = 0;
			c = (int)in[i] - (int)k[key_i];
			if (c>0)
				sout[i] = ((int)in[i] - (int)k[key_i]) % 26 + 97;
			else
				sout[i] = c + 123;

			key_i++;
		}
	}



	return sout;
}
int main()
{
	string key;
	string sinput;
	string soutput;
	cout << "podaj key" << endl;
	getline(cin, key);
	cout << "podaj input\n";
	getline(cin, sinput);
	soutput = encode(sinput, key);

	cout << endl << soutput << endl;

	soutput = decode(soutput, key);

	cout << endl << soutput;
	while (getchar() != 'x')
	{

	}

	return 0;
}

