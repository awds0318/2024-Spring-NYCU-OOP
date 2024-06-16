#include <iostream>
#include <string>

using namespace std;

int main(){
	int mode;
	bool end = false;
	string str;
	string text[5], graph[5];
	text[0] = "(happy)";		graph[0] = "^w^";
	text[1] = "(heart)";		graph[1] = "<3";
	text[2] = "(confused)";		graph[2] = "?_?";
	text[3] = "(kiss)";			graph[3] = "-3-";
	text[4] = "(speechless)";	graph[4] = "= =";
	size_t found;

	while(true){
		cout << "Please enter the mode: ";
		cin >> mode;

		if(mode == -1){
			cout << "Program ends" << endl;
			break;
		}
		else{
			cout << "Input: ";
			cin.ignore(100, '\n');
			getline(cin, str);
			
			for(int i = 0; i < 5; i++){
				if(mode)
					found = str.find(graph[i]);
				else
					found = str.find(text[i]);
				while(found != string::npos){
						if(mode){
							str.replace(found, graph[i].length(), text[i]);
							found = str.find(graph[i], found);
						}
						else{
							str.replace(found, text[i].length(), graph[i]);
							found = str.find(text[i], found);
						}	
					}
				}
			}

		cout << "Output: " << str << endl;
		cout << "--------------------------------------" << endl;
	}
		
	return 0;
}
