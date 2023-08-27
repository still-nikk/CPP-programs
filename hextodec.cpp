#include<bits/stdc++.h>
using namespace std;

int hextodec(string h){
    int ans = 0;
    int x = 1;
    int s = h.size();
    for(int i =s-1; i>=0; i--){
        if(h[i] >= '0' && h[i] <= '9'){
            ans += x*(h[i] - '0');
        }
        else if(h[i] >= 'A' && h[i] <= 'F'){
            ans += x*(h[i] - 'A' + 10);
        }
        x *= 16;
    }
    return ans;
}

int main(){
    string hex;
    cout<<"Enter the Hexadecimal number: ";
    cin>>hex;
    int dec = hextodec(hex);
    cout<<dec<<endl;
    return 0;
}