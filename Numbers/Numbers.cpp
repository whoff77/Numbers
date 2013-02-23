#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;

void runCase();
void fastExp();

clock_t tStart;
int cases = 0;
long double threeSqrtFive = 0;

//ifstream infile("smallIn.in");
//ofstream outfile("smallOut.out");
ifstream infile("largeIn.in");
ofstream outfile("largeOut.out");

int main() {

	cout.precision(10);
	outfile.precision(10);
	tStart = clock();
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
	long long a=3, b=1, number;
	infile >> number;
	for (int i=2; i<=number; i++) {
		long long newA, newB;
		newA = 3*a + 5*b;
		newB = 3*b + a;
		a = newA % 1000;
		b = newB % 1000;
	}
	long long answer = (2*a - 1) % 1000;
	outfile << setw( 3 ) << setfill( '0' ) << answer << endl;
	cout << setw( 3 ) << setfill( '0' ) << answer << endl;
}