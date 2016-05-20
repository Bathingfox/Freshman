#include <stdio.h>

void HeapAdjust(int array[], int i, int nlength){
	int nChild;
	int nTemp;
	for(; 2 * i + 1 < nlength; i = nChild){
		nChild = 2 * i + 1;
		if(nChild < nlength - 1 && array[nChild + 1] > array[nChild]) 
			++nChild;

		if(array[i] < array[nChild]){
			nTemp = array[i];
			array[i] = array[nChild];
			array[nChild] = nTemp;
		}
		else
			break;
	}
}

void HeapSort(int array[], int length){
	int i;
	int j;
	for(i = length/2 - 1; i >= 0; --i){
		HeapAdjust(array, i, length);
		for (j = 0; j < length; ++j)
			printf("%d ", array[j]);
		printf("\n");
	}
	for(i = length - 1; i >= 0; --i){
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		HeapAdjust(array, 0, i);
		for (j = 0; j < length; ++j)
			printf("%d ", array[j]);
		 printf("\n");

	}
}

int main(){
	int i;
	int num[] = {4, 5, 1, 0, 6, 7, 3, 2, 9, 8};
	HeapSort(num, sizeof(num)/sizeof(int));
	for (i = 0; i< sizeof(num)/sizeof(int); ++i)
		printf("%d ", num[i]);
	printf("\n");
	return 0;
}
