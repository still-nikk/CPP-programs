#include<iostream>
#include<vector>
using namespace std;

//works almost like an array just that its is a dynamic array
// basic syntax:
// vector<type> name(size,initilasation element);

int main()
{
    vector<int> a;
    cout << "Capacity: " << a.capacity() << endl;           //.caapcity() 
    cout << "Size: " << a.size() << endl;                   //.size()
    a.push_back(1);
    cout << "Capacity: " << a.capacity() << endl;
    cout << "Size: " << a.size() << endl;
    a.push_back(2);
    cout << "Capacity: " << a.capacity() << endl;
    cout << "Size: " << a.size() << endl;
    a.push_back(3);
    cout << "Capacity: " << a.capacity() << endl;
    cout << "Size: " << a.size() << endl;

    cout << "Element at 2 index: " << a.at(2) << endl;      // .at()
    cout << "First element: " << a.front() << endl;         // .front()
    cout << "Last element: " << a.back() << endl;           // .back()
    
    for(int i:a)                    //Range based for loop
    {
        cout << i << " " ;
    }
    cout << endl;

    a.pop_back();                                           // .pop_back()
    cout << "Last element: " << a.back() << endl;
    a.shrink_to_fit();                                      // .shrink_to_fit()
    cout << "Capacity: " << a.capacity() << endl;
    cout << "Size: " << a.size() << endl;

    vector<int> v(5,1);                                     // initializes a vector of size 5 with all elements as 1
    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> w(a);                                       //copies the vector as it is           
    for(int i : w)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Capacity: " << w.capacity() << endl;
    cout << "Size: " << w.size() << endl;

    a.clear();
    cout << "Capacity: " << a.capacity() << endl;
    cout << "Size: " << a.size() << endl;
    return 0;
}