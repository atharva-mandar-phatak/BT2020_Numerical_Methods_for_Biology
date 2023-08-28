#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pb push_back
#define rep(i,a,n) for(int i=a; i<n; i++)
#define per(i,a,n) for(int i=a; i>n; i--)

dd h;

int* init(int n)
{
    int *p;
    p = new int[n];
    rep(i,0,n)
    {
        cin>>p[i];
    }
    return p;
}

void printArr(int A[], int n)
{
    rep(i,0,n)
        cout<<A[i]<<endl;
}

dd fwdApp1(dd x, dd a1, dd a2)
{
    dd fx= (-a2+(4*a1)-(3*x))/(2*h);
    return fx;
}
dd bwdApp1(dd b2, dd b1, dd x)
{
    dd fx= (b2-(4*b1)+(3*x))/(2*h);
    return fx;
}
dd cntdApp1(dd b2, dd b1, dd x, dd a1, dd a2)
{
    dd fx= (-a2+(8*a1)-(8*b1)+b2)/(12*h);
    return fx;
}
void App1()
{
    dd x;
    dd arr[5];
    cin>>x>>h;
    dd f= -0.1*pow(x,4) -0.15*pow(x,3) -0.5*pow(x,2) -0.25*x + 1.2;
    dd X=x-(2*h);
    rep(i,0,5)
    {
        arr[i]=-0.1*pow(X,4) -0.15*pow(X,3) -0.5*pow(X,2) -0.25*X + 1.2;
        X+=h;
    }
    cout<<"Forward Approx f'(x): "<<fwdApp1(arr[2],arr[3],arr[4])<<endl;
    cout<<"Backward Approx f'(x): "<<bwdApp1(arr[0],arr[1],arr[2])<<endl;
    cout<<"Centered Approx f'(x): "<<cntdApp1(arr[0],arr[1],arr[2],arr[3],arr[4])<<endl;
}
dd graphicalMethod(dd c, dd inc)
{
    dd f=1,fx=1;
    while(f*fx>0)
    {
        f=fx;
        /*write your eq here*/
        fx=(667.38*(1-exp(-c/6.81))/c) -40;
        c+=inc;
    }
    c-=inc;
    return c;
}
dd bisectionMethod(dd xl, dd xu, int n, dd t)
{
    dd root;
    dd arr[n][6];
    arr[0][4]=-1;
    for(int i=0; i<n; i++)
    {
        dd xr = (xr+xl)/2;
        arr[i][0]=i+1;
        arr[i][1]=xl;
        arr[i][2]=xu;
        arr[i][3]=xr;
        if(i!=0)
            arr[i][4]=(arr[i][3]-arr[i-1][3])*100/arr[i][3];
        arr[i][5]= (t-arr[i][3])*100/t;

        if((667.38*(1-exp(-xl/6.81))/xl) -40==0)
            return xl;
        else if((667.38*(1-exp(-xu/6.81))/xu) -40==0)
            return xu;
        else if(((667.38*(1-exp(-xl/6.81))/xl) -40)*((667.38*(1-exp(-xr/6.81))/xr) -40)<0)
        {
            xu=xr;
        }
        else if(((667.38*(1-exp(-xu/6.81))/xu) -40)*((667.38*(1-exp(-xr/6.81))/xr) -40)<0)
        {
            xl=xr;
        }
        root=xr;
    }
    rep(i,0,n)
    {
        rep(j,0,6)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
        return root;
}

void solve()
{
    //App1();

    /*dd c,inc;
    cin>>c>>inc;
    dd a=graphicalMethod(c,inc);
    cout<<"By graphical method, the root can be found in between x="<<a-inc<<" and x="<<a<<endl;*/

    bisectionMethod(12,16,6,14.7802);

}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
