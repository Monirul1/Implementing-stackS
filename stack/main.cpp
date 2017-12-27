#include <iostream>
#include <stack>
using namespace std;

struct MyStack
{
    stack<int> s;
    int minEle;
    
    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty\n";
        else
            cout <<"Minimum Element in the stack is: "
            << minEle << "\n";
    }
    
    void top()
    {
        if (s.empty())
        {
            cout << "Stack is empty ";
            return;
        }
        
        int t = s.top();
        
        cout << "Top Most Element is: ";
    
        if (t < minEle)
            cout << minEle;
        cout << t;
    }
    
    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        
        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
        
        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        }
        
        else
            cout << t << "\n";
    }
    
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout <<  "Number Inserted: " << x << "\n";
            return;
        }
        
        if (x < minEle)
        {
            s.push(2*x - minEle);
            minEle = x;
        }
        
        else
            s.push(x);
        
        cout <<  "Number Inserted: " << x << "\n";
    }
};

int main()
{
    MyStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    s.getMin();
    s.pop();
    s.pop();
    s.getMin();
    
    return 0;
}

/* ----SAMPLE RUN----
 Number Inserted: -2
 Number Inserted: 0
 Number Inserted: -3
 Minimum Element in the stack is: -3
 Top Most Element Removed: -3
 Top Most Element Removed: 0
 Minimum Element in the stack is: -2
 Program ended with exit code: 0
 */

