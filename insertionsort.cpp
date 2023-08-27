#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[], int size){
    for(int i = 1; i<size; i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j] > current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
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
    insertionsort(arr,n);
    cout<<"Sorted array in ascending order is: "<<endl;
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}




// #include<bits/stdc++.h>
// using namespace std;

// void swap(int *x,int *y){
//     int *temp;
//     *temp = *x;
//     *x = *y;
//     *y = *temp;
// }

// int main(){
//     int n;
//     cout<<"Enter the number of elements in your array: "<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements: "<<endl;
//     for(int k=0;k<n;k++){
//         cin>>arr[k];
//     }
//     int i;
//     int key;
//     int j;
//     for(i=1;i<=n;i++){
//         key = arr[i];
//         for(j=(i-1);j>=0;j--){
//             if(arr[j]>key){
//                 swap(&arr[j+1],&arr[j]);
//             }
//         }
//     }
//     cout<<"Sorted array : "<<endl;
//     for(int l=0;l<n;l++){
//         cout<<arr[l]<<endl;
//     }
//     return 0;
// }