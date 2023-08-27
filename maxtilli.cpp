#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i = 1;i<n;i++){
        if(arr[i]<arr[i-1]){
            arr[i] = arr[i-1];
        }
    }
    cout<<"max till i: "<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}