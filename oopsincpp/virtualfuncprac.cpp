#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
    string name ;
    int age;
    virtual void getdata(){
        cin >>name>>age ;
    }
    virtual void putdata(){
        cout<<name<<' '<<age<<' ';
    }
};

class Professor:public Person{
    public:
    int publication , cur_id ;
    static int id ;
    Professor(){
        cur_id = id++ ;
    }
    virtual void getdata(){
        Person::getdata(); 
        cin>>publication ;
    }
    virtual void putdata(){
        Person::putdata();
        cout<<publication<<' '<<cur_id<<endl ;
    }
};

class Student:public Person{
    public:
    int marks[6] ,cur_id ,sum = 0;
    static int id ;
    Student(){
        cur_id = id++ ;
    }
    virtual void getdata(){
        Person::getdata() ;
        for(int i = 0;i < 6 ;i++){
            cin>>marks[i] ;
            sum+=marks[i] ;
        }
    }
    virtual void putdata(){
        Person::putdata() ;
        cout<<sum<<' '<<cur_id<<endl;
    }
};
int Professor::id = 1;
int Student::id = 1;

int main() {
    int n ;
    cin>>n ;
    
    for(int i = 0;i<n; i++){
        int type = 0 ;
        cin>>type ;
        if(type == 1){
            Professor p ;
            p.getdata() ;
            p.putdata() ;
        }
        else if(type == 2){
            Student S ;
            S.getdata();
            S.putdata() ;
        } 
    }
    return 0;
}