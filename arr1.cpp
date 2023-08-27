#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the size of the array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i< n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout<<max<<"  "<<min<<endl;
    return 0;
}