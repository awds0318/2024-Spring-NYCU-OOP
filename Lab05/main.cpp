#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;



class science{
	friend ostream& operator<<(ostream&out, const science &sci);
	friend istream& operator>>(istream&in, science &sci);
private:
	double a;   
	int n;
public:
	science():a(0), n(0) {}
	science(double a_) : a(a_), n(0) {}
  	science(double a_, int n_){
    // ------------- Write Your Code Here ------------- //
    // 
    // ------------------------------------------------ //
	}
	
  // Member function declarations
  // ------------- Write Your Code Here ------------- //
  // 
  // ------------------------------------------------ //
};

// Finish the ctor and function definitions
// ------------- Write Your Code Here ----------------- //
// 
// ---------------------------------------------------- //

int main(){
	science v, t, w;
	char op;
	while(1){
		cout << "Please enter an expression:" << endl << endl;

    cin >> v;

		cin >> op;
		if( op != '+' && op != '-' && op != '*' && op != '/' ) break;

		cin >> t;
		if(cin.fail()) break;

		switch(op){
			case '+':  w = v + t; break;
			case '-':  w = v - t; break;
			case '*':  w = v * t; break;
			case '/':  w = v / t; break;
		}
		cout << v << ' ' << op << ' ' << t << " = " << w << endl << endl;
	}
	return 0;
}
