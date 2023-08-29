#include<bits/stdc++.h>
using namespace std;

class studentgrade{
    public:
    string name;
    long long int prn;
    float pp;
    float ds;
    float co;
    float sam;
    float dmgt;
    
    void printgrade(){
        float sum;
        sum = pp + ds + co + sam + dmgt;
        float per = sum / 5;
        cout<<"Name: "<<name<<"                 PRN: "<<prn<<endl;
        cout<<"Overall Percentage: "<<per<<"%"<<endl;
        cout<<"Grade: ";
        if(per < 40){
            cout<<"F"<<endl;
        }
        else if(per >= 40 && per < 60){
            cout<<"D"<<endl;
        }
        else if(per >= 60 && per < 70){
            cout<<"C"<<endl;
        }
        else if(per >= 70 && per < 80){
            cout<<"B"<<endl;
        }
        else if(per >= 80 && per < 90){
            cout<<"A"<<endl;
        }
        else if(per >= 90 && per < 100){
            cout<<"O"<<endl;
        }
    }
};

int main(){
    studentgrade a;
    cout<<"Name: ";
    cin >> a.name;
    cout<<"PRN: ";
    cin >> a.prn;
    cout<<endl<<"Enter marks for every subject: "<<endl;
    cout<<"Subject                       Marks"<<endl;
    cout<<"PP:                           ";
    cin >> a.pp;
    cout<<"DS:                           ";
    cin >> a.ds;
    cout<<"CO:                           ";
    cin >> a.co;
    cout<<"SAM:                          ";
    cin >> a.sam;
    cout<<"DMGT:                         ";
    cin >> a.dmgt;
    a.printgrade();
    return 0;
}