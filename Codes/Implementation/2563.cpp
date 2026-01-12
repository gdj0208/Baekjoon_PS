/*
#include "Main.h"

#include <iostream>
#include <math.h>
#include <Windows.h>
*/
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define boardLen 100
#define paperLen 10


typedef struct {
	int x, y;
}Paper;

int main(void)
{
	int arr[boardLen][boardLen] = { 0 };
	Paper* paper;

	int paperNum;
	int count;

	scanf("%d", &paperNum);

	paper = (Paper*)calloc(paperNum, sizeof(Paper));

	for (int i = 0; i < paperNum; i++) {
		scanf("%d %d", &paper[i].x, &paper[i].y);

		for (int j = 0; j < paperLen; j++) {
			for (int k = 0; k < paperLen; k++) {
				arr[paper[i].y + j][paper[i].x + k] = 1;
			}
		}
	}

	count = 0;
	for (int i = 0; i < boardLen; i++) {
		for (int j = 0; j < boardLen; j++) {
			if (arr[i][j] == 1) { count++; }
		}
	}

	printf("%d\n", count);

}


