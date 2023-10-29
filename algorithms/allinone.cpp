/*
Algorithm        Time Complexities:(best,worst)
linear search     1     n
binary search     1     logn
bubble sort       n     n^2  
selection sort    n^2   n^2
insertions sort   n     n^2
merge sort        nlogn nlogn
quick sort        nlogn n^2
*/

#include<iostream>
#include<string>
#include<array>
using namespace std;

void linearsearch(array<int,10>a,int key)
{
    int count = 0;
    for(int i:a)
    {   
        if(i==key)
        {
            count++;
        }
    }
    if(count == 0)
    {
        cout << key << " was not found" << endl;
    }
    else
    {
        cout << key << " was found " << count << " times." << endl;
    }
}

void binarysearch(array<int,6>a,int key,int l, int h)
{
    int m = (l + h)/2 ;
    while(l<=h)
    {if(key == a[m])
    {
        cout << key << " was found at "  << m +1 << " position."<< endl;
        return ;
    }
    else if(key < a[m])
    {
        return binarysearch(a,key,l,m-1);
    }
    else if(key > a[m])
    {
        return binarysearch(a,key,m+1,h);
    }
    }
    cout << key <<" was not found in the array." <<endl;
}

void swap(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[],int size)
{
    cout << "Unsorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size -1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // swap(&arr[j], &arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionsort(int arr[],int size)
{
    cout << "Unsorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;
    for(int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i-1;
        while(arr[j] > current && j>=0)
        {   
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    cout << "Sorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

void selectionsort(int arr[], int size)
{
    cout << "Unsorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < size -1; i++)
    {
        for(int j = i+1; j<size; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int l,int mid,int h)
{
    int n1 = mid -l +1;
    int n2 = h -mid;

    int a[n1];
    int b[n2];

    for(int i = 0; i< n1 ; i++)
    {
        a[i] = arr[l+i];
    }
    for(int i = 0; i< n2 ; i++)
    {
        b[i] = arr[mid+i+1];
    }

    int i= 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            i++; k++;
        }
        else
        {
            arr[k] = b[j];
            j++; k++;
        }
    }

    while(i<n1)
    {
        arr[k] = a[i];
        i++; k++;
    }
    while(j<n2)
    {
        arr[k] = b[j];
        j++; k++;
    }

}

void mergesort(int arr[],int l, int h)
{
    if(l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);

        merge(arr,l,mid,h);
    }
}

void quicksort(int arr[],int l, int h)
{
    int pivot, i, j, temp;
    if(l<h)
    {
        pivot = l;
        i = l;
        j = h;
        while(i<j)
        {
            while(arr[i] <= arr[pivot] && i <=h)
            {
                i++;
            }
            while(arr[j] > arr[pivot] && j >= l)
            {
                j--;
            }
            if(i<j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,h);
    }
}

int main()
{
    array<int,10> a = {1,4,6,72,6,8,4,9,0,12};
    array<int,6> b = {1,2,3,4,5,6};
    int arr[] = {2,6,3,4,5,1};
    // linearsearch(a,6);
    // binarysearch(b,4,0,5);
    cout << "Unsorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // bubblesort(arr,6);
    // selectionsort(arr,6);
    // insertionsort(arr,6);
    // mergesort(arr,0,5);
    quicksort(arr,0,5);
    cout << "Sorted array: ";
    for(int i = 0; i < 6 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}