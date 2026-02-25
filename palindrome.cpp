#include<iostream>
#include<stack>
#include<string>
using namespace std;

/** Pseudocode:
Function isPalindrome(argInput)
	Make empty stack

	For each character in argInput
	PUSH a character onto the stack

	For each character in argInput
	POP a character from stack
	If the popped character != current character
	Return false

	Return true

**/

bool isPalindrome(string argInput);

int main() {
	string userString;

	cout << "Enter a string";
	getline(cin, userString);

	if (isPalindrome(userString)) {
		cout << "This word is a palindrome" << endl;
	}
	cout << "This word is NOT a palindrome" << endl;

	return 0;
}

bool isPalindrome(string argInput) {
	stack<char>c;

	for (int i = 0; i < argInput.size(); i++) {
		c.push(argInput[i]);
	}

	for (int i = 0; i < argInput.size(); i++) {
		if (argInput[i] != c.top()) {
			return false;
		}
		c.pop();
	}
	return true;
}
