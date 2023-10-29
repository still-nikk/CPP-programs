#include<iostream>
#include<array>
using namespace std;

//basic syntax
// array<type,size> name = {element1, element2, element3};

int main()
{
    array<int,4> a = {1,2,3,4};
    int size = a.size();        //.size() function defines the size
    for(int i = 0 ; i< size ; i++)
    {
        cout << a.at(i) << " ";         //.at(i) function gives the ith element
    }
    cout << "First element is: " << a.front() << endl;          //.front() prints the first element
    cout << "Last element is : " << a.end() << endl;           //.end() prints the last element
    cout << "Is the array empty?: " << a.empty() << endl;       //.empty() is a boolean function which gives the value true/1 if the array is empty
    return 0;
}