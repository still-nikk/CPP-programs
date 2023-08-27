#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows in the upper half: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j = 1 ; j<=2*n ; j++){
            if(j<=i || j>((2*n)-i)){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    for(int k =0;k<n;k++){
        for(int l = 1;l<=2*n;l++){
            if(l<=(n-k) || l>(n+k)){
            cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}