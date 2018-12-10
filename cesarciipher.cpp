
// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
using namespace std;
string encode(string in, int k) {
	string sout = in;
	for (int i = 0;i < (int)in.length();i++) {
		if(in[i]!=' ')
		sout[i] = ((int)in[i] - 97 + k) % 26 + 97;
	}
	return sout;
}
string decode(string in, int k) {
	string sout = in;
	int c;
	for (int i = 0;i < (int)in.length();i++) {
		if (in[i] != ' ') {
			c = (int)in[i] - 97 - k;
			if (c >= 0)
				sout[i] = ((int)in[i] - 97 - k) % 26 + 97;
			else
				sout[i] = c + 123;
		}
	}



	return sout;
}
int main()
{
	int k;
	string sinput;
	string soutput;
	cout << "podaj k" << endl;
	cin>>k;
	
	cout << "podaj input\n";
	cin.ignore();
	getline(cin, sinput);
	soutput = encode(sinput, k);

	cout << endl << soutput << endl;

	soutput = decode(soutput, k);

	cout << endl << soutput;
	while (getchar() != 'x')
	{

	}

	return 0;
}

