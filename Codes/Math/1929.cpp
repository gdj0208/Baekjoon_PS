#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

bool check(int n);
void printPrimeNum(int min, int max);

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	printPrimeNum(n1, n2);
}

bool check(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void printPrimeNum(int min, int max)
{
	for (int i = min; i <= max; i++) {
		if (check(i)) printf("%d\n", i);
	}
}
