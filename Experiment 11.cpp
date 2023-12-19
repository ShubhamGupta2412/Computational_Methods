#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double f(double x){
    return (x*x + sin(53*x));
}

int main(){
    double a=-0.2, b=0.2;
    double x,y;
    double D,d;
    int N=ceil(log((b-a)/(0.0001*1.618))/log(1.618))+1;
    cout<<"\nNumber of steps: "<<N-1<<endl;

    int fib[N];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<N;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    cout<<"k \t a \t\t b \t\t x \t\t y\n";
    int k;
    for(k=N-1;k>=2;k--){
        D=(1.0*fib[k-2]/fib[k])*(b-a);
        x=a+D;
        y=b-D;
        cout<<fixed<<setprecision(5)<<k<<" \t "<<a<<" \t "<<b<<" \t "<<x<<" \t "<<y<<endl;
        if(f(x)>=f(y))
        a=x;
        else
        b=y;
    }
    d=(y-x)/4;
    x=(a+b)/2-2*d;
    y=(a+b)/2+2*d;
    cout<<fixed<<setprecision(5)<<k--<<" \t "<<a<<" \t "<<b<<" \t "<<x<<" \t "<<y<<endl;
    if(f(x)>=f(y))
        a=x;
    else
        b=y;

    double xmin=(a+b)/2;
    double minima=f(xmin);

    cout<<"Minima is at = "<<xmin<<endl;
    cout<<"\nValue of Minima: "<<minima;
    cout<<endl<<endl;
    return 0;
}

