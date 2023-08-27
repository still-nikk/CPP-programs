#include<bits/stdc++.h>
using namespace std;

float ctof(float x){
    float result;
    result = (x*(1.8))+32;
    return result;
}

float ftoc(float x){
    float result = (x-32)*(0.56);
    return result;
}

int main(){
    float temp;
    int sel;
    cout<<"Menu: "<<endl<<"1. Celcius to Farhenheit"<<endl<<"2. Farhenheit to Celcius"<<endl;
    cin>>sel;
    switch(sel){
        case 1:
        {
        cout<<"Enter the temperature in degree celcius: ";
        cin>>temp;
        float far = ctof(temp);
        cout<<"The temperature in degree farhenheit is: "<<far;
        break;
        }
        case 2:
        {
        cout<<"Enter the temperature in degree Farhenheit: ";
        cin>>temp;
        float cel = ftoc(temp);
        cout<<"The temperature in degree Celcius is: "<<cel;
        break;
        }
    }
    return 0;
}