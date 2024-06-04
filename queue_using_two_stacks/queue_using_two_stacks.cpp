#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;

class TwoStacks
{
    private:
        std::stack<int> inStack, outStack;
        
        void moveToOutStack()
        {
            auto s = inStack.size();
            for(int i = 0; i < s; i++)
            {
                auto tmp = inStack.top();
                outStack.push(tmp);
                inStack.pop();
            }
        }
    public:
        
        void debug()
        {
            cout << "inStack: \n";
            auto copy = inStack;
            for(int i = 0; i < inStack.size();i++)
            {
                cout << copy.top() << " ";
                copy.pop();
            }
            cout << "\n";
            copy = outStack;
            cout << "outStack: \n";
            for(int i = 0; i < outStack.size();i++)
            {
                cout << copy.top() << " ";
                copy.pop();
                
            }
            cout << "\n";
        }
        
        void push(int x)
        {
            inStack.push(x);
        }
        
        void pop()
        {
            if(outStack.size() == 0 && inStack.size() > 0)
            {
                moveToOutStack();
            }
            
            if(outStack.size() > 0)
            {
                outStack.pop();
            }
        }
        
        int top()
        {
             if(outStack.size() == 0 && inStack.size() > 0)
            {
                moveToOutStack();
            }
            if(outStack.size() > 0)
            {
                return outStack.top();
            }
            
            else 
            {
                return 0;
            }
        }
};



int main() {
    TwoStacks twoStacks;
    string t_temp;
    getline(cin, t_temp);
    int n_of_queries = stoi(t_temp);
    for( int i = 0; i < n_of_queries; i++)
    {
        getline(cin, t_temp);
        stringstream ss(t_temp);
        string commandS;
        getline(ss,commandS,' ');
        auto command = stoi(commandS);
        switch (command) {
            case 1: 
            {
                getline(ss,commandS,' ');
                twoStacks.push(stoi(commandS));
                break;
            }
            case 2:
            {
                twoStacks.pop();
                break;
            }
            case 3:
            {
                cout << to_string(twoStacks.top()) << "\n";
                break;
            }
        }
        // twoStacks.debug();
    }
    return 0;
}
