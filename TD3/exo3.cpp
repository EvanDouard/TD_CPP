#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
using namespace std;


bool isPalindromeStack(const string& input) {
    stack<char> charStack;
    for (char c : input) {
        if (isalnum(c)) {
            charStack.push(tolower(c));
        }
    }

    for (char c : input) {
        if (isalnum(c)) {
            if (charStack.top() != tolower(c)) {
                return false;
            }
            charStack.pop();
        }
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << "Is 'racecar' a palindrome (Stack)? " << isPalindromeStack("racecar") << endl;
    cout << "Is 'hello' a palindrome (Stack)? " << isPalindromeStack("hello") << endl;
    cout << "Is 'A man, a plan, a canal: Panama' a palindrome (Stack)? " 
         << isPalindromeStack("A man, a plan, a canal: Panama") << endl;
    return 0;
}
