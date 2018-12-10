
// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <math.h>
using namespace std;
string encode(string in, int a,int b) {
	string sout;
	for (int i = 0;i < (int)in.length();i++) {
		if (in[i] != ' ') {
			sout += (a*((int)in[i] - 97) + b) % 26 + 97;
		}
		else
			sout += ' ';
			
	}
	return sout;
}
string decode(string in, int a,int b) {
	string sout ;
	int c,z=1;
	while (z*a % 26 != 1)
		z++;
	for ( int i = 0;i < (int)in.length();i++) {
		if (in[i] != ' ') {
			sout += (z*((int)in[i] - 97) -z*b) % 26 + 97;
		}
		else
			sout += ' ';
	}
	cout << z << endl;


	return sout;
}
int main()
{
	int a,b;
	string sinput;
	string soutput;
	cout << "podaj pare liczb a i b" << endl;
	cin >> a;
	cin >> b;

	cout << "podaj input\n";
	cin.ignore();
	getline(cin, sinput);
	soutput = encode(sinput, a,b);

	cout << endl << soutput << endl;
	

	cout << endl <<  decode(soutput, a,b);;
	while (getchar() != 'x')
	{

	}

	return 0;
}

