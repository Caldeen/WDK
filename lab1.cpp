
// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <bitset>
using namespace std;


bitset<32> S_Box(bitset<48> input,int tab [4][16]) {
	int sum=0;
	int pos = 0;
	int sum2 = 0;
	bitset<32> out;
	bitset<4> temp;
	for (int i = 0;i < 8;i++) {
		sum = 2*input[6*i] + input[(6*i+5)];
		sum2 = 8*input[6 * i + 1] + 4*input[6 * i + 2]+2*input[6 * i + 3] + input[6 * i + 4];
		temp = (bitset<4>)tab[sum][sum2];
		cout << "Temp: " << temp << endl;
		for (int n = 0;n < 4;n++)
			out[pos + n]= temp[3-n];
		pos += 4;
	}

	return out;
}
bitset<32> Perm_P(bitset<32> input, int tab[4][8]) {
	bitset<32> temp = input;
	int pos = 0;
	for(int i=0;i<4;i++)
		for (int j = 0;j < 8;j++) {
			temp[pos] = input[tab[i][j]];
			pos++;
		}
	return temp;
}
int main()
{
	bitset<48> key(string("100101001010010100101001010010100101001011111101"));
	int tab[4][16] = { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
		14,11,2,12 ,4 ,7,13 ,1,5 ,0,15,10,3,9,8,6,
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 };
	
	for(int i=0;i<48;i++)
	cout << key[i]<<" ";

	cout << endl;
	for (int i = 0;i < 4;i++) {
		for (int y = 0;y < 16;y++)
			cout << tab[i][y] << " ";
		cout << endl;
	}
	bitset<32> output = S_Box(key, tab);
	for (int i = 0;i <32;i++)
		cout << output[i] << " ";
	getchar();
	return 0;
}

