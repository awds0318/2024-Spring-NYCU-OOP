#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;



class science{
	friend ostream& operator<<(ostream&, const science& );
	friend istream& operator>>(istream&, science& );
private:
	double a;
	int n;
public:
	science():a(0), n(0) {}
	science(double _a) :a(_a), n(0) {}

    science(double _a, int _n){

		int k;

		if (_a==0)
            k = 0;
		else
            k = floor(log10(fabs(_a)));


		a = _a/pow(10,k);
		n = _n + k;

	}

	const science operator+(const science& rhs) const {

	    int i = n-rhs.n;

		return science(pow(10,i)*a+rhs.a, rhs.n);
	}

    const science operator-(const science& rhs) const {

        int i = n-rhs.n;

		return science(pow(10,i)*a-rhs.a, rhs.n);
	}
	const science operator*(const science& rhs) const {

		return science(a*rhs.a, n+rhs.n);
	}
	const science operator/(const science& rhs) const {

		return science(a/rhs.a, n-rhs.n);
	}

//finish this class

};

ostream& operator<<(ostream& os, const science& f){


    os << f.a << "*10^" << f.n ;

	return os;

}
istream& operator>>(istream& is, science& f){


    double _a;
    int _n;
    is >> _a >> _n ;

    int k;

    if (_a==0)
        k = 0;
    else
        k = floor(log10(fabs(_a)));


    f.a = _a/pow(10,k);
    f.n = _n + k;

    return is;
}


int main(){
	science v,t,w;
	char op;
	while(1){
		cout<<"Please enter an expression:"<<endl<<endl;

        cin>>v;

		cin>>op;
		if( op!='+' && op!='-' && op!='*' && op!='/' ) break;

		cin>>t;
		if(cin.fail()) break;

		switch(op){
			case '+':  w = v+t; break;
			case '-':  w = v-t; break;
			case '*':  w = v*t; break;
			case '/':  w = v/t; break;
		}
		cout<<v<<' '<<op<<' '<<t<<" = "<<w<<endl<<endl;



	}
	return 0;
}
