#include<iostream>
using namespace std;
int main(){
    int selection;
    cout<<"Menu:"<<endl<<"Select the language you want to translate HELLO into:"<<endl<<"1.Hindi"<<endl<<"2.Spanish"<<endl<<"3.French"<<endl<<"4.Italian"<<endl<<"5.Exit"<<endl;
    cin>>selection;
    switch(selection){
        case 1:
        cout<<"Namaste"<<endl;
        break;
        case 2:
        cout<<"Hola"<<endl;
        break;
        case 3:
        cout<<"Bonjour"<<endl;
        break;
        case 4:
        cout<<"Ciao"<<endl;
        break;
        case 5:
        break;
        default:
        cout<<"Wrong Selection!";
    }
    return 0;
}