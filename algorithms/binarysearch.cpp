#include<bits/stdc++.h>
using namespace std;

int iterativebs(int arr[], int l, int h, int key){
    while (l<=h)
    {
        int m = (l+h)/2;
        if(arr[m]==key)
        {
            return m+1;
        }
        if(arr[m]<key){
            l = m+1;
        }
        if(arr[m]>key){
            h = m-1;
        }
    }
    return -1;
}

int recursivebs(int arr[],int l,int h, int key){
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m] == key){
            return m+1;
        }
        else if(arr[m]> key){
            return recursivebs(arr,l,m-1,key);
        }
        else if(arr[m]<key){
            return recursivebs(arr,m+1,h,key);
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of your array: ";
    cin>>n;
    int elem[n];
    cout<<"Enter the sorted elements of your array: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>elem[i];
    }
    int min = 0;
    int max = n-1;
    int x;
    cout<<"Enter the key element to search: "<<endl;
    cin>>x;
    int position = iterativebs(elem,min,max,x);
    if(position==-1){
        cout<<"The element was not found"<<endl;
    }
    else{
    cout<<"The element was found at "<<position <<" position"<<endl;
    }
    int position2= recursivebs(elem,min,max,x);
    if(position2 == -1 ){
        cout<<"The element was not found"<<endl;
    }
    else{
    cout<<"The element was found at "<<position2 <<" position"<<endl;
    }
    return 0;
}