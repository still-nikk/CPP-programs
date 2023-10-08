#include<bits/stdc++.h>
using namespace std;

void bubblesortdescend(int arr[],int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size -1; j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubblesortascend(int arr[],int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of your array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Descending order: "<<endl;
    bubblesortdescend(arr,n);
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<endl;
    }

    cout<<endl<<"Ascending Order: "<<endl;
    bubblesortascend(arr,n);
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}


// #include <iostream>
// using namespace std;



// void bubbleSort(int arr[], int n){
//     for(int i = 0; i < n - 1; i++){
//         for(int j = 0; j < n - i - 1; j++){
//             if(arr[j] < arr[j + 1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter the number of elements in the list: ";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter "<<n<<" elements:"<<endl;
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     bubbleSort(arr, n);
//     cout<<"Sorted list using bubble sort: ";
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
//     return 0;
// }
