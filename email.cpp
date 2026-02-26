#include<iostream>
#include<string>
#include<list>
#include<stdexcept>
using namespace std;

bool isEmailValid(string);

int main() {
	string userInput;
	char userChoice;
	
	do {
		cout << "Enter an email: ";
		getline(cin, userInput);

		try {
			cout << isEmailValid(userInput) << endl;

		}
		catch (exception err) {
			cout << err.what() << endl;
		}

		cout << "Would you like to enter another email";
		cin >> userChoice;
	}while (userChoice == 'y' || userChoice == 'Y');

	return 0;
}
bool isEmailValid(string arg) {
	int n = arg.find('@');
	list<string> validEmailExtensions = { "@gmail.com", "@aol.com", "@cos.edu", "@giant.cos.edu" };
	list<string>::iterator cur;

	if (n == string::npos) {
		throw exception("No @ detected");
	}
	for (cur = validEmailExtensions.begin(); cur != validEmailExtensions.end(); cur++) {
		if (arg.substr(n) == *cur) {
			cout << "You're golden" << endl;
			return true;
		}
	}
	return false;

}
