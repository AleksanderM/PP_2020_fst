#include <iostream>
using namespace std;
void swap(int* a, int* b)
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
	for (int i = 0; i < (size - 1); i++)
	{
		maxI = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[maxI])
			{
				maxI = j;
			}
			swap(&arr[j], &arr[maxI]);
		}
	}
	return arr;
}
//TODO counting sort
int* countingSort(int* arr, int &size) {return arr;};

bool sortingTest(int* arrToSort, int size)
{
	int* countingSorted = countingSort(arrToSort, size);
	int* selectionSorted = selectionSort(arrToSort, size);

	for (int i = 0; i < size; ++i) {
		if (countingSorted[i] != selectionSorted[i]) {
			return false;
		}
	}

	return true;
}

int main() {

	return 0;
}
