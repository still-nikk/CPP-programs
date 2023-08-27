#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter your number: ";
    cin>>n;
    int sum = 0;
    while(n>0){
        int rem = n%10;
        sum = sum*10 + rem;
        n/=10;
    }
    cout<<sum;
    return 0;
}