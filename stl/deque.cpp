#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(0);
    for(int i:d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Size: " << d.size() << endl;
    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;
    cout << "Empty or not: " << d.empty() << endl;
    // d.pop_back();
    // for(int i:d)
    // {
    //     cout << i << " ";
    // }
    // d.pop_front();
    // for(int i:d)
    // {
    //     cout << i << " ";
    // }
    cout << "Before Erase: " ;
    for(int i:d)
    {
        cout << i << " ";
    }
    d.erase(d.begin(), d.end());
    cout << endl;
    cout << "After Erase: ";
    for(int i:d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Size: " << d.size() << endl;
    return 0;
}