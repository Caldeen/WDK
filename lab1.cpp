
// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#define R1CBIT 8
#define R2CBIT 10
#define R3CBIT 10
using namespace std;
class Rejestr {
public:
	int R1[19];
	int R2[22];
	int R3[23];
	int key[64];

	Rejestr(int tab1[], int tab2[], int tab3[]) {
		for (int i = 0;i < 19;i++)
			R1[i] = tab1[i];
		for (int i = 0;i < 22;i++)
			R2[i] = tab2[i];
		for (int i = 0;i < 23;i++)
			R3[i] = tab3[i];

	}
	int MajorityRule()
	{
		if (R1 [R1CBIT] == R2[R2CBIT])
			return R1[R1CBIT];
		if (R2[R2CBIT] == R3[R3CBIT])
			return R2[R2CBIT];
		if (R1[R1CBIT] == R3[R3CBIT])
			return R3[R3CBIT];
		return 0;
	}
	void Shift1()
	{
		int xor1 = R1[18] ^ R1[17] ^ R1[16] ^ R1[13];
		for (int i = 18; i >0; i--)
		{
			R1[i] = R1[i - 1];
		}
		R1[0] = xor1;
	}
	void Shift2()
	{
		int xor2 = R2[21] ^ R2[20] ;
		for (int i = 21; i >0; i--)
		{
			R2[i] = R2[i - 1];
		}
		R2[0] = xor2;
	}
	void Shift3()
	{
		int xor3 = R3[22] ^ R3[21] ^ R3[20] ^ R3[7];
		for (int i = 22; i >0; i--)
		{
			R3[i] = R3[i - 1];
		}
		R3[0] = xor3;
	}
	void Print() {
		cout << "\nR1: " << endl;
		for (int i = 18;i >0;i--)
			cout << R1[i] << " ";
		cout << "\nR2: " << endl;
		for (int i = 21;i >0;i--)
			cout << R2[i] << " ";
		cout << "\nR3: " << endl;
		for (int i = 22;i >0;i--)
			cout << R3[i] << " ";
	}
	void setkey(int a,int x)
	{
		key[a] = x;
	}

};
int main(){
	int tab1[19] = { 1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1 };
	int tab2[22] = { 1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0 };
	int tab3[23]={ 1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1 };
	Rejestr Rej(tab1, tab2,tab3 );
	Rej.Print();
	cout<<"Shifting: "<<endl<<endl;
	for (int i = 0;i < 16;i++) {
		Rej.setkey(i, Rej.R1[18] ^ Rej.R2[21] ^ Rej.R3[22]);
		int clock = Rej.MajorityRule();
		if (clock == Rej.R1[R1CBIT])
			Rej.Shift1();
		if (clock == Rej.R2[R2CBIT])
			Rej.Shift2();
		if (clock == Rej.R3[R3CBIT])
			Rej.Shift3();
		Rej.Print();
		getchar();
	}


	
	return 0;
}

