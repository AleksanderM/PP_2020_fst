#include <iostream>
using namespace std;

//TODO counting sort
int* countingSort(int* arr, int &size) {return arr;};
//TODO selection sort
int* selectionSort(int* arr, int &size) {return arr;};

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
