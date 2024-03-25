#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;



class science{
	friend ostream& operator<<(ostream&out, science &sci);
	friend istream& operator>>(istream&in, science &sci);
	friend const science operator+(const science& src1, const science& src2);
	friend const science operator-(const science& src1, const science& src2);
	friend const science operator*(const science& src1, const science& src2);
	friend const science operator/(const science& src1, const science& src2);
private:
	double a;   
	int n;

public:
	science():a(0), n(0) {}
	science(double a_) : a(a_), n(0) {}
  	science(double a_, int n_) : a{a_}, n{n_} {
    // ------------- Write Your Code Here ------------- //
    // 
    // ------------------------------------------------ //
	}
  // ------------- Write Your Code Here ------------- //
  // Member function declarations
	science reduced_form();
};

science science::reduced_form()
{
	science reduce;
	int temp;
	if(1 < abs(a) && abs(a) < 10)
		temp = 0;
	else if(0 < abs(a) && abs(a) < 1)
		temp = -1;
	else if(a == 0)
		temp = 0;
	else 
		temp = log10(abs(a));
		
	reduce.n = temp + n;
	reduce.a = a / pow(10, temp);

	return reduce;
}


// Finish the ctor and function definitions
// ------------- Write Your Code Here ----------------- //
ostream& operator<<(ostream& out, science& src)
{
    out << src.reduced_form().a << " * 10 ^ " << src.reduced_form().n;

    return out;
}

istream& operator>>(istream& in, science& science)
{
    in >> science.a;
    in >> science.n;

    return in;
}




const science operator+(const science& src1, const science& src2)
{
	science temp;
	int i, j, min_n;
	double x, y;
	min_n = min(src1.n, src2.n);
	i = src1.n - min_n;
	j = src2.n - min_n;
	x = src1.a * pow(10, i);
	y = src2.a * pow(10, j);

	temp.n = min_n;
	temp.a = x + y;

    return temp.reduced_form();
}

const science operator-(const science& src1, const science& src2)
{
	science temp;
	int i, j, min_n;
	double x, y;
	min_n = min(src1.n, src2.n);
	i = src1.n - min_n;
	j = src2.n - min_n;
	x = src1.a * pow(10, i);
	y = src2.a * pow(10, j);

	temp.n = min_n;
	temp.a = x - y;

    return temp.reduced_form();
}

const science operator*(const science& src1, const science& src2)
{
	science temp;

	temp.n = src1.n + src2.n;
	temp.a = src1.a * src2.a;

    return temp.reduced_form();
}

const science operator/(const science& src1, const science& src2)
{
	science temp;

	temp.n = src1.n - src2.n;
	temp.a = src1.a / src2.a;

    return temp.reduced_form();
}

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
