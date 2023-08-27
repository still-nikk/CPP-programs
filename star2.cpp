#include<iostream>
using namespace std;

int main(){
    int x;
    int count = 1;
    cout<<"Enter the number of rows: ";
    cin>>x;
    for(int i=x; i>0; i--){
        for(int y = x; y>0; y--){
            if(y>count){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        count++;
        cout<<endl;
    }
    return 0;
}