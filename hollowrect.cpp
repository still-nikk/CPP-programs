#include<iostream>
using namespace std;

int main(){
    int x,y;
    cout<<"Enter the number of rows and  columns: ";
    cin>>x>>y;
    for(int i=0;i<x;i++){
        if(i==0 || i==x-1){
            for(int j=0;j<y;j++){
                    cout<<"* ";
                }
        }
        else{
            for(int k=0;k<y;k++){
                if(k==0 || k==y-1){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}