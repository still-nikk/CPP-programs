#include <iostream>
#include <stack>
using namespace std;



int main()
{
    stack<int> s1;
    stack<int> s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    // cout << "Printing the elements of first stack: "<<endl;
    // for(int i = 0; i < s1.size();i++)
    // {
    //     cout << s1.top() <<endl;
    //     s1.pop();
    // }
    // s1.push(1);
    // s1.push(2);
    // s1.push(3);
    // s1.push(4);
    // s1.push(5);
    for(int i = 0; i<s1.size(); i++)
    {
        int val;
        val = s1.top();
        s2.push(val);
        s1.pop();
    }
    // cout << "Printing the elements of second stack: "<<endl;
    // for(int i = 0; i < s2.size();i++)
    // {
    //     cout << s2.top() <<endl;
    //     s2.pop();
    // }
    cout << s2.top() <<endl; 
    return 0;
}