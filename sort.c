#include<stdio.h>
#include "sort.h"
void shift_element(int *arr, int i) {
	int flag;
	for(flag = i; i > arr && (i-1) > flag; i--) {
		i--;
	}
	i = flag;
}
void insertion_sort(int *arr, int len) {
	int i, *last = arr + len;
	for(i = arr + 1; i < last; i++)
		if(arr[i] < arr[i-1])
			shift_element(arr, i);
}
void print_array(int *data, int n) {
	int i;
	for(i = 0; i<n; i++) {
		printf("%d ", *data);
		data++;
	}
	printf("\n");
}