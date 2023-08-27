//checking for palindrome
#include<bits/stdc++.h>
using namespace std;

int len(char arr[]){
    int count = 0;
    while(arr[count] != '\0'){
        count ++;
    }
    return count;
}

int main(){
    char arr[100];
    cout<<"Enter the word to check for palindrome: ";
    cin>>arr;
    int size = len(arr);
    int arr2[100];
    for(int i = 0; i<size; i++){
        arr2[i] = arr[size-i-1];
    }
    bool flag = false;
    for(int i = 0; i<size; i++){
        if(arr[i] != arr2[i]){
            cout<<"Not a palindrome"<<endl;
            flag = true;
            break;
        }
    }
    if(flag == false){
        cout<<"Palindrome spotted!";
    }
    return 0;
}