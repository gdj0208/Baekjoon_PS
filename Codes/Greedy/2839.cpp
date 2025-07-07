#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int getBags(int n);

int main() {
	int n;
	cin >> n;
	printf("%d", getBags(n));
}

int getBags(int n)
{
	for (int i = n / 5; i >= 0; i--) {
		for (int j = n / 3; j >= 0; j--) {
			if(n - (5*i + 3*j) == 0){ 
				//printf("number : %d\n", n);
				//printf("5 : %d\n", i);
				//printf("3 : %d\n", j);
				return i + j;
			}
		}
	}
	return -1;
}