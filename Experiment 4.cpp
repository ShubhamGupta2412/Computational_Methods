#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define tol 0.00001

int ite1=0,ite2=0;
double lastMid=0;

double fx(double x) {
    return pow(x,5) + x*x*x + 3;
}

double secant(double x0, double x1)
{
    double x2=(x0*fx(x1)-x1*fx(x0))/(fx(x1)-fx(x0));
    cout<<fixed<<setprecision(5)<<++ite1<<" \t "<<x0<<" \t "<<x1<<" \t "<<x2<<" \t "<<fx(x2)<<" \t "<<fabs(x1-x2)<<endl;
    if(fabs(x1-x2)<=tol || fabs(fx(x2))<=tol)
    {
        return x2;
    }
    else if((fx(x1)-fx(x2)==0))
    cout<<"\nMethod not defined for "<<x1<<" & "<<x2<<" values";
    else
    {
        return secant(x1,x2);
    }
}

int main()
{
    int m,n;
    cout<<"For SECANT Method, \nEnter values of x0 and x1 "<<endl;
    cin>>m>>n;
    if(fx(m)==0)
    cout<<"Root is "<<m<<endl;
    else if(fx(n)==0)
    cout<<"Root is "<<n<<endl;
    else if((fx(n)-fx(m))==0)
    cout<<"Method not defined for these values";
    else
    {
        cout<<"\nite \t x(n-1) \t x(n) \t\t x(n+1) \t f(x(n+1)) \t error\n";
        double sroot=secant(m,n);
        cout<<"\nRoot by SECANT Method is: "<<sroot<<endl<<endl;
    }

    cout<<"Number of iterations for SECANT Method is: "<<ite1<<endl;

    return 0;
}

