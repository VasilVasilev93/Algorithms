#include <iostream>

using namespace std;


void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int max(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void merge_helper(int *arr, int left, int right, int *copyArr)
{

    if(right == left + 1)
    {
        return;
    }
    else
    {
        int i = 0;
        int length = right - left;
        int midpoint_distance = length/2;
 
        int l = left, r = left + midpoint_distance;


        merge_helper(arr, left, left + midpoint_distance, copyArr);
        merge_helper(arr, left + midpoint_distance, right, copyArr);


        for(i = 0; i < length; i++)
        {
            if(l < left + midpoint_distance && 
                    (r == right || max(arr[l], arr[r]) == arr[r]))
            {
                copyArr[i] = arr[l];
                l++;
            }
            else
            {
                copyArr[i] = arr[r];
                r++;
            }
        }

        for(i = left; i < right; i++)
        {
            arr[i] = copyArr[i - left];
        }
    }
}

int mergesort(int *arr, int size)
{
    int *copyArr = new int[size];
    if(copyArr != NULL)
    {
        merge_helper(arr, 0, size, copyArr);
        delete [] copyArr;
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{

	int arr[10] = { 5, 1, 9, 4, 7, 2, 3, 5, 6, 8 };

	mergesort(arr, 10);

	print(arr, 10);

	system("pause");

	return 0;
}