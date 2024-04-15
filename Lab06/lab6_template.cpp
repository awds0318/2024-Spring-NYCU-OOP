#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Science {
    friend ostream& operator<<(ostream&, Science &);
    friend istream& operator>>(istream&, Science &);
	friend class Complex;  // You might need this.
private:
    double a;
    int n;
public:
	Science():a(0), n(0) {}
	Science(double a_) : a(a_), n(0) {}
  	Science(double a_, int n_) : a{a_}, n{n_} {}
	friend const Science operator+(const Science& src1, const Science& src2);
	friend const Science operator-(const Science& src1, const Science& src2);
	friend const Science operator*(const Science& src1, const Science& src2);
	friend const Science operator/(const Science& src1, const Science& src2);
	Science reduced_form();
    // ...
};

Science Science::reduced_form()
{
	Science reduce;
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

ostream& operator<<(ostream& out, Science& src)
{
    out << src.reduced_form().a << " * 10 ^ " << src.reduced_form().n;

    return out;
}

istream& operator>>(istream& in, Science& science)
{
    in >> science.a;
    in >> science.n;

    return in;
}

const Science operator+(const Science& src1, const Science& src2)
{
	Science temp;
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

const Science operator-(const Science& src1, const Science& src2)
{
	Science temp;
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

const Science operator*(const Science& src1, const Science& src2)
{
	Science temp;

	temp.n = src1.n + src2.n;
	temp.a = src1.a * src2.a;

    return temp.reduced_form();
}

const Science operator/(const Science& src1, const Science& src2)
{
	Science temp;

	temp.n = src1.n - src2.n;
	temp.a = src1.a / src2.a;

    return temp.reduced_form();
}

class Complex {
	friend ostream& operator<<(ostream&, Complex&);
    friend istream& operator>>(istream&, Complex&);
public:
	Complex(){};
	// const Complex operator-() const;
	// const Complex operator+(const Complex&) const;

	friend const Complex operator+(const Complex& src1, const Complex& src2);
	friend const Complex operator-(const Complex& src1, const Complex& src2);
	friend const Complex operator*(const Complex& src1, const Complex& src2);
	// ...
private:
	Science re;
	Science im;
};

ostream& operator<<(ostream& out, Complex& src){return out << src.re << " + " << src.im << " i";}

istream& operator>>(istream& in, Complex& src){return in >> src.re >> src.im;}

const Complex operator+(const Complex& src1, const Complex& src2)
{
	Science re1,re2;
	Science im1,im2;
	Science re_temp, im_temp;
	Complex temp;
	re1 = src1.re;
	re2 = src2.re;
    // (re1+im1i)(re2+im2i) = 
	im1 = src1.im;
	im2 = src2.im;

	re_temp = re1 + re2;
	temp.re = re_temp.reduced_form();

	im_temp = im1 + im2;
	temp.im = im_temp.reduced_form();

    return temp;
}

const Complex operator-(const Complex& src1, const Complex& src2){
	Science re1,re2;
	Science im1,im2;
	Science re_temp, im_temp;
	Complex temp;
	re1 = src1.re;
	re2 = src2.re;
    // (re1+im1i)(re2+im2i) = 
	im1 = src1.im;
	im2 = src2.im;

	re_temp = re1 - re2;
	temp.re = re_temp.reduced_form();

	im_temp = im1 - im2;
	temp.im = im_temp.reduced_form();

    return temp;
}

const Complex operator*(const Complex& src1, const Complex& src2){
	Science re1,re2;
	Science im1,im2;
	Science re_temp, im_temp;
	Complex temp;
	re1 = src1.re;
	re2 = src2.re;
    // (re1+im1i)(re2+im2i) = 
	im1 = src1.im;
	im2 = src2.im;

	re_temp = re1 * re2 - im1 * im2;
	temp.re = re_temp.reduced_form();

	im_temp = re1 * im2 + im1 * re2;
	temp.im = im_temp.reduced_form();

    return temp;
}





class ComplexPolynomial {
public:
	ComplexPolynomial(){}; 
	ComplexPolynomial(Complex a, Complex b, Complex c):a{a}, b{b}, c{c}{}; 
	Complex eval(const Complex& x);
private:
	Complex a;
	Complex b;
	Complex c;
};

Complex ComplexPolynomial::eval(const Complex& x){
// axx bx c
	return a*x*x + b*x + c;
}







int main() {
    Complex a, b, c, x;
	ComplexPolynomial p;
	Complex eval_ans;

	cout << "Enter coefficient a (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> a;
	cout << "Enter coefficient b (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> b;
	cout << "Enter coefficient c (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> c;
	cout << "Enter x (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> x;

	p = ComplexPolynomial{a, b, c};
	eval_ans = p.eval(x);
    
	cout << "The evaluation answer is " << eval_ans << endl;

    return 0;
}