#include<iostream>
using namespace std;

int main(){
    int x;
    cout<<"Enter the number of rows: ";
    cin>>x;
    for(int i=x;i>0;i--){
        for(int j = i;j>0;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}