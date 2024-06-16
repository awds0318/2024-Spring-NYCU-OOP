#include <iostream>
using namespace std;

struct Data {
	int value;
	char letter;
	bool is_let;
};

class stack {
	public:
	stack () ;
	void push (Data) ;
	Data pop () ;
	bool empty () ;

	private:
	Data array[1000];
	int index;
};

stack::stack () : index(0) {}
void stack::push (Data data) { array[index++] = data; }
Data stack::pop () { return array[--index];}
bool stack::empty () {return index == 0;}

int main (){
	Data data;
	int op;
	stack stack1;
	while (true) {
		cout << "choose the operation:" << endl;
		cin >> op ;
		if (op == 0){
			cout << "push a number:" << endl;
			cin >> data.value;
			data.is_let = false;
			stack1.push(data);
		}
		else if (op == 1){
			cout << "push a letter:" << endl;
			cin >> data.letter;
			data.is_let = true;
			stack1.push(data);
		}
		else{
			cout << "pop stack:" << endl;
			if(stack1.empty()){
				cout << "the stack is empty" << endl;
			}
			else{
				data = stack1.pop();
				if(data.is_let){
					cout << data.letter << endl;
				}
				else{
					cout << data.value << endl;
				}
			}
		}
	}
	return 0;
}