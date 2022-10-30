//Merge Sort//
#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++) // loop used for copying the data
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
		/*for merging the temporary arrays*/
	i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) { //copying rest elememnts if they supposed to be there
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) { //copying rest elememnts if they supposed to be there
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size) /*Function for printing an array*/
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d\t", A[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 84, 12, 36, 5, 77 };
	int arr_siz = sizeof(arr) / sizeof(arr[0]);
	printf("Given array: \n");
	printArray(arr, arr_siz);
	mergeSort(arr, 0, arr_siz - 1);
	printf("\nSorted array:\n");
	printArray(arr, arr_siz);
	return 0;
}
