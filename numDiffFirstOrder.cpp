//BE21B040 Sumedh Kangne
//Numerical Differentiation
//f'(x), truncating at second order

#include <bits/stdc++.h>
using namespace std;

double h; //h is step function
void printArr(int A[], int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;
}

double fwdAppOh(double x, double a1)
{
    double fx= (a1-x)/(h);
    return fx;
}
double bwdAppOh(double b1, double x)
{
    double fx= (x-b1)/(h);
    return fx;
}
double cntdAppOh2(double b1, double x, double a1)
{
    double fx= (a1-b1)/(2*h);
    return fx;
}
double fwdAppOh2(double x, double a1, double a2)
{
    double fx= (-a2+(4*a1)-(3*x))/(2*h);
    return fx;
}
double bwdAppOh2(double b2, double b1, double x)
{
    double fx= (b2-(4*b1)+(3*x))/(2*h);
    return fx;
}
double cntdAppOh4(double b2, double b1, double x, double a1, double a2)
{
    double fx= (-a2+(8*a1)-(8*b1)+b2)/(12*h);
    return fx;
}

int32_t main()
{
    double x;
    double arr[5];
    cout<<"Enter the value of x: ";
    cin>>x;
    cout<<"\nEnter the value of step function h: ";
    cin>>h;
    cout<<endl;
    double X=x-(2*h);
    for(int i=0;i<5;i++)
    {
        //Write your function below
        arr[i]= -0.1*pow(X,4) -0.15*pow(X,3) -0.5*pow(X,2) -0.25*X + 1.2;
        X+=h;
    }
    cout<<"Forward Approx O(h) f'(x): "<<fwdAppOh(arr[2],arr[3])<<endl;
    cout<<"Backward Approx O(h) f'(x): "<<bwdAppOh(arr[1],arr[2])<<endl;
    cout<<"Centered Approx O(h^2) f'(x): "<<cntdAppOh2(arr[1],arr[2],arr[3])<<endl;
    cout<<endl;
    cout<<"Forward Approx O(h^2) f'(x): "<<fwdAppOh2(arr[2],arr[3],arr[4])<<endl;
    cout<<"Backward Approx O(h^2) f'(x): "<<bwdAppOh2(arr[0],arr[1],arr[2])<<endl;
    cout<<"Centered Approx O(h^4) f'(x): "<<cntdAppOh4(arr[0],arr[1],arr[2],arr[3],arr[4])<<endl;
    return 0;
}

