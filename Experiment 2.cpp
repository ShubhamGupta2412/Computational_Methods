#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define tol 0.000001

int ite1=0;
double lastMid=0;

double fx(double x) {
    return x*x*x-8*x-3;
}

double bsct(double a, double b)
{
    double mid=(a+b)/2;
    cout<<fixed<<setprecision(6)<<++ite1<<"\t"<<a<<"\t"<<b<<"\t"<<mid<<"\t"<<fx(mid)<<"\t"<<fabs(lastMid-mid)<<endl;
    if(fx(mid)==0 || fabs(fx(mid))<=tol)
    {
        return mid;
    }
    else if(fabs(lastMid-mid)<=tol)
    {
        return mid;
    }
    else if(fabs(fx(mid))<=tol)
    {
        return mid;
    }
    else if((fx(a)*fx(mid))<0)
    {
        lastMid=mid;
        return bsct(a,mid);
    }
    else if((fx(mid)*fx(b))<0)
    {
        lastMid=mid;
        return bsct(mid,b);
    }
}

int main()
{
    double m,n,ia,root,root1;

    cout<<"For BISECTION Method \nEnter initial interval a b ";
    cin>>m>>n;
    if(fx(m)==0)
    cout<<"Root is "<<m<<endl;
    else if(fx(n)==0)
    cout<<"Root is "<<n<<endl;
    else if((fx(m)*fx(n))<0)
    {
        cout<<"\nite\ta\t\tb\t\tmid\t\tfx(mid))\terror"<<endl;
        root=bsct(m,n);
        cout<<"\nRoot by BISECTION Method is: "<<root<<endl<<endl;
    }
    else
    cout<<"Sign is same at both values, try another interval";
    return 0;
}

