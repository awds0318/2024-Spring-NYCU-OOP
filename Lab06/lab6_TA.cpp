#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Science {
	friend class Complex;
    friend ostream& operator<<(ostream&os, const Science &f);
    friend istream& operator>>(istream&is, Science &f);
private:
    double a;   
    int n;
public:
    Science():a(0), n(0) {}
    Science(double a_) : a(a_), n(0) {}
    Science(double a_, int n_){
        int k;
        if (a_==0)
            k = 0;
        else
            k = floor(log10(fabs(a_)));
        a = a_/pow(10,k);
        n = n_ + k;
    }
    
    const Science operator+(const Science& other) const {
        int i = n - other.n;
        return Science(pow(10,i)*a+other.a, other.n);
    }

    const Science operator-(const Science& other) const {
        int i = n - other.n;
        return Science(pow(10,i)*a-other.a, other.n);
    }

    const Science operator*(const Science& other) const {
        return Science(a*other.a, n+other.n);
    }

    const Science operator/(const Science& other) const {
        return Science(a/other.a, n-other.n);
    }
};

ostream& operator<<(ostream& os, const Science& f)
{
    cout << f.a << "*10^" << f.n;
	return os;
}

istream& operator>>(istream& is, Science& f)
{
    double _a;
    int _n;
    int k;

    is >> _a >> _n ;
    if (_a==0)
        k = 0;
    else
        k = floor(log10(fabs(_a)));
    f.a = _a/pow(10,k);
    f.n = _n + k;

    return is;
}



class Complex {
	friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
public:
	Complex(const Science& _re = 0, const Science& _im = 0): re(_re), im(_im) {}
	Complex(const Complex& c): re(c.re), im(c.im) {}
	const Complex operator-() const;
	const Complex operator+(const Complex& c) const;
	const Complex operator-(const Complex& c) const;
	const Complex operator*(const Complex& c) const;
private:
	Science re;
	Science im;
};

const Complex Complex::operator-() const
{
	return Complex(Science{-re.a, re.n}, Science{-im.a, im.n});
}

const Complex Complex::operator+(const Complex& c) const
{
	return Complex(re + c.re, im + c.im);
}

const Complex Complex::operator-(const Complex& c) const
{
	return Complex(re - c.re, im - c.im);
}

const Complex Complex::operator*(const Complex& c) const
{
	Science new_re = re * c.re - im * c.im;
	Science new_im = re * c.im + im * c.re;
	return Complex(new_re, new_im);
}

ostream& operator<<(ostream&os, const Complex &c)
{
    cout << c.re << " + " << c.im << " i";
	return os;
}

istream& operator>>(istream&is, Complex &c)
{
	is >> c.re >> c.im;
	return is;
}


class ComplexPolynomial {
public:
	ComplexPolynomial(): a(0), b(0), c(0) {}
	ComplexPolynomial(Complex a, Complex b, Complex c): a(a), b(b), c(c) {}
	Complex eval(const Complex& x);
private:
	Complex a;
	Complex b;
	Complex c;
};

Complex ComplexPolynomial::eval(const Complex &x)
{
	return a * x * x + b * x + c;
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