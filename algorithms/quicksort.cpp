#include <bits/stdc++.h>
using namespace std;

int selection;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int divide(int arr[], int low, int high){
    if(selection == 1){
        int pivot = arr[low];
        int i = low + 1;
            for (int j = low + 1; j <= high; ++j){
                if (arr[j] < pivot){
                    swap(arr[i], arr[j]);
                    ++i;
                }
            }
        swap(arr[low], arr[i - 1]);
        return i - 1;
    }

    else if(selection == 2){
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
    }
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pivotIndex = divide(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout<<"Select Pivot element"<<endl<<"1.First element"<<endl<<"2.Last element"<<endl;
    cin>>selection;
    
    quickSort(arr, 0, n - 1);
    cout << "Sorted array:\n";
    for (int i = 0; i < n; ++i){
        cout<<arr[i]<<" ";
    }
    return 0;
}