#include<bits/stdc++.h>
using namespace std;

int iterativeLS(int arr[],int key,int size){
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return i+1;
            break;
        }
    }
    return -1;
}

int recursivels(int arr[],int index, int size, int key){
    if(index > size){
        return -1;
    }
    else if(arr[index]==key){
        return index+1;
    }
    else{
        recursivels(arr,index+1,size,key);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of your array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the element to search: "<<endl;
    cin>>key;
    // int j;
    // for(j = 0;j<n;j++){
    //     if(arr[j]==key){
    //         break;
    //     }
    // }
    // if(j == (n-1)){
    //     cout<<"The element was not found!"<<endl;
    // }
    // else{
    //     cout<<key<<" was found at "<<j+1<<endl;
    // }

    int flag;
    flag = iterativeLS(arr,key,n);
    if(flag == -1)
    {
        cout<<"The element was not found!"<<endl;
    }
    else
    {
        cout<<key<<" was found at "<<flag<<endl;
    }
    int flag1;
    flag1 = recursivels(arr,0,n,key);
    if(flag1 == -1)
    {
        cout<<"The element was not found!"<<endl;
    }
    else
    {
        cout<<key<<" was found at "<<flag1<<endl;
    }
    return 0;
}