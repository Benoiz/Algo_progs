#define __USE_MINGW_ANSI_STDIO 1
#define MAXITEMS 100000
#define MAXNUM 1000
#define LINE 81

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

//sort functions
int my_sort(int digits[], int inputCount, int argc, char** argv);
int* bubbleSort(int digits[], int inputCount, int arrLen);
int* insertionSort(int digits[], int inputCount);
int* selectionSort(int digits[], int inputCount, int start);
void quickSort(int* left, int* right);
//util functions
int cmp_integer(const void *val1, const void *val2);
long long GetUSecTime();
int iarrlen(int* iArr);