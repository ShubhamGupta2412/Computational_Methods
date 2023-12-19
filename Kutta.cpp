#include<iostream>
#include<cmath>
using namespace std;

double f(double y){
return 2*(1+(y*y));
}

double rk(double y, double h){
double k1= h*f(y);
double k2= h*f(y+(k1/2));
double k3= h*f(y+(k2/2));
double k4= h*f(y+k3);

return y+((k1+(2*k2)+(2*k3)+k4)/6);
}
int main() {
    double h = 0.05;
    double y = 0;
    int n;
    double x;
    cout << "Enter the target x: ";
    cin >> x;
    n = static_cast<int>(ceil((x - 0) / h));  // Use ceil to round up
    cout << "No of iterations: " << n << endl;
    for (int i = 0; i < n; i++) {
        y = rk(y, h);
    }
    cout << "y= " << y << endl;
    cout << "y'= " << f(y);
}
