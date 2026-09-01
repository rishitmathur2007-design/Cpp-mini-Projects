#include<iostream>
using namespace std;
int main()
{
    float cc,gp,s=0,t,t_Credit=0,t_gp=0,sgpa=0;
    int n;
    cout<<"Enter Number of Subjects:";
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cout<<"Enter Course Credit of Subject "<<i<<" :";
        cin>>cc;
        cout<<"Enter Grade Point of Subject "<<i<<" :";
        cin>>gp;
        t=cc*gp;
        s=s+t;
        t_Credit=t_Credit+cc;
        t_gp=t_gp+t;
        cout<<endl;
    }
    sgpa=s/t_Credit;
    cout<<"Total Credit:"<<t_Credit<<endl;
    cout<<"Total Grade Point:"<<t_gp<<endl;
    cout<<"SGPA:"<<sgpa<<endl;
}