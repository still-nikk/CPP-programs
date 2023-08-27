#include<iostream>
using namespace std;

int main(){
    cout<<"Mention the dimensions of the rectangle you want to display(eg. row,column): ";
    int x,y;
    cin >> x >> y;
    for(int i =0;i<x;i++){
        for(int j = 0;j<y;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}