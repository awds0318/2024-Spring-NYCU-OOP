#include <iostream>
using namespace std;

struct Data {
	int value;
	char letter;
	bool is_letter;
};

class stack {
	public:
	stack (){};
	void push (Data);
	Data pop ();
	bool empty ();

	private:
	// ======write your code======
	Data array[8]; // 0~7
	int index{0};
	// ===========================
};

// define function in stack
// ======write your code======
void stack::push(Data push_data)
{
	array[index].is_letter = push_data.is_letter;
	if(push_data.is_letter == 0)
		array[index].value = push_data.value;
	else 
		array[index].letter = push_data.letter;

	index += 1;
}

Data stack::pop()
{	
	Data a;
	a = array[index-1];
	index -= 1; 

	return a;
}

bool stack::empty()
{
	if(index == 0)
		return 1;
	else 
		return 0;
}
// ===========================

int main(){
	// ======write your code======
	// ===========================
	Data data;
	stack stack1;
	int operation;
	while (true)
	{
		cout << "choose the operation:" << endl;
		cin >> operation;
		if (operation == 0)
		{
			cout << "push a number:" << endl;
			cin >> data.value;
			data.is_letter = 0;
			stack1.push(data);
		}
		else if (operation == 1)
		{
			cout << "push a letter:" << endl;
			cin >> data.letter;
			data.is_letter = 1;
			stack1.push(data);
		}
		else // if (operation == 2)
		{
			Data pop_data;
			cout << "pop stack:" << endl;
			
			if(stack1.empty() == 1)
			{
				cout << "the stack is empty" << endl;
				break;
			}
			else
			{
				pop_data = stack1.pop();

				if(pop_data.is_letter == 0)
				{
					cout << pop_data.value << endl;
				}
				else //  if (pop_data.is_letter == 1)
				{
					cout << pop_data.letter << endl;
				}
			}
		}
	}
	return 0;
}