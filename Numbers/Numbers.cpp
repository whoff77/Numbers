#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;

void runCase();

clock_t tStart;
int cases = 0;
long double threeSqrtFive = 0;

ifstream infile("smallIn.in");
ofstream outfile("smallOut.out");
//ifstream infile("largeIn.in");
//ofstream outfile("largeOut.out");

int main() {

	cout.precision(10);
	outfile.precision(10);
	tStart = clock();
	threeSqrtFive = (long double)3 + sqrt((long double)5);
	cout << threeSqrtFive << endl;
	infile >> cases;
	cout << "cases: " << cases << endl;
	for (int i = 1; i <= cases; i++) {
		outfile << "Case #" << i << ": ";
		cout << "Case #" << i << endl;
		runCase();
		printf("%.2fs\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	}
	infile.close();
	outfile.close();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cin.get();
	return 0;
}

void runCase() {
	int number;
	infile >> number;
	long double power = pow(threeSqrtFive,number);
	long double answer2 = fmod(power,(long double)1000);
	int answer = answer2;
	outfile << setw( 3 ) << setfill( '0' ) << answer << endl;
	cout << setw( 3 ) << setfill( '0' ) << answer << endl;
}