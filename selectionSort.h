#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

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

#endif /* SELECTIONSORT_H_ */
