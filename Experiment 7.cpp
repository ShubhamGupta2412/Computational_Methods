#include<iostream>
#include<cmath>
using namespace std;

double f(double x){
	return exp(-x*x);
}

double I(double a, double b, int n){
	double y=0;
	for(int i=1; i<n; i++){
		y=y+f(a+(i*(b-a)/n));
	}
	double res = ((b-a)/(2*n))*(f(a)+f(b)+2*y);
	cout << "I"<< n << "= "<< res<< endl;;
	return res;
}

int main(){
	double TV = 0.746824132812;
	double i1=I(0,1,1);
	double i2=I(0,1,2);
	int n=3;
	while (abs(i2-TV)>0.00005){
		i2=I(0,1,n);
		n=n+1;
	}
	cout << "I= " << i2 << "\t Iterations: " << n-1;
}
