#include"Sort.h"
#include<stdio.h>



void TextSort() {
	/*int a[] = { 48,62,35,77,55,14,35 };
	int size = sizeof(a) / sizeof(a[0]);
	SelectSort(a, size);
	SortPrinf(a, size);*/

	int ar[] = { 83,40,63,13,84,35,96,57,39,79,61,15 };
	int size2 = sizeof(ar) / sizeof(ar[0]);
	QuickSort1(ar, 0, size2-1);
	//SortPrinf(ar, size2);
}



int main() {
	TextSort();
	return 0;
}