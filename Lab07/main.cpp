// ------------- include header file you will use ------------- //
#include <iostream>
#include <string>

// ------------------------------------------------------------ //

using namespace std;

void Replace(string& str, const string& sub, const string& mod) 
{
	string tmp(str);
	size_t found;
	found = str.find(sub);
	while(found != string::npos) // ! Remeber, else will get error
	{
		str.replace(str.find(sub), sub.length(), mod);
		found = str.find(sub);   // ! Remeber, else will get error
	}
}

int main()
{
	int mode;
	bool end = false;
	string str;
	string text[5], graph[5];
	text[0] = "(happy)";	   graph[0] = "^w^";
	text[1] = "(heart)";	   graph[1] = "<3";
	text[2] = "(confused)";	   graph[2] = "?_?";
	text[3] = "(kiss)";	       graph[3] = "-3-";
	text[4] = "(speechless)";  graph[4] = "= =";
	size_t found;

	// ------------- Coding in here ------------- //
	while (true)
	{
		cout << "Please enter the mode: ";
		cin >> mode;
		if (mode == -1)
		{
			cout << "Program ends" << endl;
			break;
		}

		cout << "Input: ";
		cin.ignore(100, '\n');
		getline(cin, str);
		
		if (mode == 0)
		{
			Replace(str, text[0], graph[0]);
			Replace(str, text[1], graph[1]);
			Replace(str, text[2], graph[2]);
			Replace(str, text[3], graph[3]);
			Replace(str, text[4], graph[4]);
		}

		if (mode == 1)
		{
			Replace(str, graph[0], text[0]);
			Replace(str, graph[1], text[1]);
			Replace(str, graph[2], text[2]);
			Replace(str, graph[3], text[3]);
			Replace(str, graph[4], text[4]);
		}

		cout << "Output: " << str << endl;
		cout << "------------------------------------------";
		cout << endl;
	}

	return 0;
}
