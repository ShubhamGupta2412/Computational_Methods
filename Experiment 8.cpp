#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#define r 0.618034
#define r2 0.381966
#define error 0.0001

int ite = 0;
double mid = 0, prevmid = 0;

double f(double x) {
    return (fabs(log(x)));
}

double golden(double a, double b) {
    double x, y;
    mid = (a - b) / 2;
    if ((fabs(prevmid - mid) < error) || (ite == 100))
        return a;
    x = a + r * (b - a);
    y = a + r2 * (b - a);
    cout << fixed << setprecision(3) << ++ite << " \t " << a << " \t " << b << " \t " << x << " \t " << y << " \t " << f(x) << " \t " << f(y) << " \t ";
    cout << fixed << setprecision(4) << fabs(prevmid - mid) << endl;
    prevmid = mid;
    if (f(x) > f(y))
        return golden(a, x);
    else
        return golden(y, b);
}

int main() {
    double a, b;
    cout << "\nEnter initial values of a: ";
    cin >> a;
    cout << "\nEnter initial values of b: ";
    cin >> b;
    cout << "ite\t a\tb\tx\ty\tf(x)\tf(y)\terror\n";
    double pmin = golden(a, b);
    cout << "\nNumber of iterations= " << ite << endl;
    cout << fixed << setprecision(3) << "Point of Minima= " << pmin << endl;
    cout << "Minima= " << f(pmin) << endl;

    cout << endl;
    return 0;
}

