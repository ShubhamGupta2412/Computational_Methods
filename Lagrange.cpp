#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "Enter the no of data points: ";
	cin >> n;
	float x[n];
	float y[n];
	float l[n];
	float m[n];
	float p=0;
	for(int i=0; i<n; i++){
		cout << "Enter value of x"<< i << ": ";
		cin >> x[i];
		cout << "Enter value of y"<< i << ": ";
		cin >> y[i];
	}
	
	cout << "|\tx\t|\ty\t|" << endl;
	for(int i=0; i<n; i++){
		cout << "|\t" << x[i] << "\t|\t" << y[i] << "\t|" << endl;
	}
	float a;
	cout << "Enter the reference data point: ";
	cin >> a;
	for(int i=0; i<n; i++){
		l[i]=1;
		for(int j=0; j<n; j++){
			if(j!=i){
				l[i]*=((a-x[j])/(x[i]-x[j]));
			}
		}
		m[i]=l[i]*y[i];
		p=p+m[i];
	}
	
	cout << "P = "<< p;
}
