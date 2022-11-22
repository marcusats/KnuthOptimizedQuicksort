#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

int Partition(int a[], int low, int high)
{
	int pivot = a[high];
	int lIndex = low;

	for (int i = low; i < high; i++)
	{
		if (a[i] < pivot)
		{
			int temp = a[i];
			a[i] = a[lIndex];
			a[lIndex] = temp;
			lIndex++;
		}
	}
	int temp = a[high];
	a[high] = a[lIndex];
	a[lIndex] = temp;

	return lIndex;
}

int Partition_r(int a[], int low, int high)
{

	srand(0);
	int random = low + rand() % (high - low);

	int temp = a[random];
	a[random] = a[high];
	a[high] = temp;

	return Partition(a, low, high);
}

void Quicksort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivotLoc = Partition_r(a, low, high);
		Quicksort(a, low, pivotLoc - 1);
		Quicksort(a, pivotLoc + 1, high);
	}
}

void Display(int a[], int n)
{
	int i = 0;
	while (i < n)
	{
		cout << "arr[" << i << "]"
			 << ": " << a[i] << " " << endl;
		i++;
	}
	cout << endl;
}

void generate_random_numbers(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int random = 1 + (rand() % 1000000000);
		arr[i] = random;
	}
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void shuffle(int array[], int size)
{

	for (int i = 0; i < size; ++i)
	{
		int j = rand() % size;
		swap(&array[i], &array[j]);
	}
}

int main()
{

	int arr_one[] = {10, 11, 12, 100, 1000, 1000000, 10000000, 100000000};
	int size_one = sizeof(arr_one) / sizeof(int);

	Quicksort(arr_one, 0, size_one - 1);
	Display(arr_one, size_one);

	int arr_two[] = {100000000, 10000000, 1000000, 1000, 100, 12, 11, 10};
	int size_two = sizeof(arr_two) / sizeof(int);

	Quicksort(arr_two, 0, size_two - 1);
	Display(arr_two, size_two);

	int arr_three[] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
	int size_three = sizeof(arr_three) / sizeof(int);

	Quicksort(arr_three, 0, size_three - 1);
	Display(arr_three, size_three);

	//===============================================
	srand((unsigned)time(NULL));

	int size = 20;
	int arr_four[size];
	generate_random_numbers(arr_four, size);
	shuffle(arr_four, size);
	Quicksort(arr_four, 0, size - 1);
	Display(arr_four, size);

	return 0;
}