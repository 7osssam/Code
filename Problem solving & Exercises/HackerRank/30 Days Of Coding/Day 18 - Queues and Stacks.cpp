#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
    // Write your code here
    std::stack<char> mystack;
    std::queue<char> myqueue;

public:
    void pushCharacter(char ch)
    {
        mystack.push(ch);
    }

    void enqueueCharacter(char ch)
    {
        myqueue.push(ch);
    }

    char popCharacter()
    {
        char top = mystack.top();
        mystack.pop();
        return top;
    }

    char dequeueCharacter()
    {
        char front = myqueue.front();
        myqueue.pop();
        return front;
    }
};

int main()
{
    // read the string s.
    string s;
    getline(cin, s);

    // create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++)
    {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (obj.popCharacter() != obj.dequeueCharacter())
        {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome)
    {
        cout << "The word, " << s << ", is a palindrome.";
    }
    else
    {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}