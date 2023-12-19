#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
	double res = exp(-x * x) - cos(x) - 1;
	return res;
}
double fd(double x){
	double res = -2 * x * exp(-x * x) + sin(x);
	return res;
}
int main() {
    double x;
    int i=0;
    double e=0.00001;
    cout << "Enter value of x: ";
    cin >> x;
    while(f(x)==0 || fd(x)==0){
    cout << "Enter value of x: ";
    cin >> x;
    cout << "f(x) = " << f(x) << endl;
    cout << "f'(x) = " << fd(x) << endl;
}
    
    while(abs(f(x))>e){
    	x=x-(f(x)/fd(x));
    	cout << "Root at iteration "<< i << " is "<< x<< endl;
    	i++;
	}
	cout<< "Final Root="<< x;
	cout<< "\nFinal Iterations = "<< i;
    return 0;
}

