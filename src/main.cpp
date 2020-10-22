#include <iostream>

void swap (int* a, int* b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

int* selectionSort(int argumentArr[], int size)
{
	int* arr = argumentArr;
	int maxI;
	//sort
	for(int i = 0 ; i < (size - 1) ; i++ )
	{
		maxI = i;
		for(int j = i+1 ; j < size ; j++ )
		{
			if(arr[j] < arr[maxI])
			{
				maxI = j;
			}
			swap(&arr[j], &arr[maxI]);
		}
	}

	for(int i = 0 ; i < size ; i++)
	{
		std::cout << arr[i] << "\t";
	}

	return arr;
}

bool sortingTest(int* countingSorted, int* selectionSorted, int length)
{
	for (int i = 0; i < length; ++i) {
		if (countingSorted[i] != selectionSorted[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {

	return 0;
}
