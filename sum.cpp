#include<iostream>

using namespace std;

int main(){
    int n,i;
    int sum = 0;
    cout<<"Enter the number upto which you want the sum of: ";
    cin>>n;
    for(i=0;i<=n;i++){
        sum = sum + i;
    }
    cout<<"The sum is "<<sum;
        return 0;
}