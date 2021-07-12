#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void print_array(long int * arr, unsigned int len) {
	printf("[");
	for(int i = 0; i < len - 1; i++) {
		printf("%ld,", arr[i]);
	}
	printf("%ld]\n", arr[len - 1]);
}

bool is_sorted(long int * arr, unsigned int len) {
	for(int i = 0; i < len - 1; i++) {
		if(arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void bogosort(long int * arr, unsigned int len) {
	srand(time(NULL));
	
	unsigned int index_one = 0;
	unsigned int index_two = 0;
	
	while(!is_sorted(arr, len)) {
	
		index_one = rand() % len;
		index_two = rand() % len;	
		
		long int temp = arr[index_one];
		arr[index_one] = arr[index_two];
		arr[index_two] = temp;
	}
	
	
}

int main(void) {
	unsigned const int count = 12;
	
	long int arr[count]; 
	FILE * file = fopen("input.txt", "r");
	
	for(int i = 0; i < count; i++)	{
	fscanf(file,"%10ld", &arr[i]);
	}
	
	puts("Unsorted array:");
	print_array(arr, count);
	
	bogosort(arr, count);
	
	puts("Sorted array:");
	print_array(arr, count);
	
	fclose(file);
	
	
	return 0;
}