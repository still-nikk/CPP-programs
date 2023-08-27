#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int size){
    for(int i = 0; i< size; i++){
        for(int j = i+1;j<=size;j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of your array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i = 0; i<n;i++){
        cout<<"Enter the "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    selectionsort(arr,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}