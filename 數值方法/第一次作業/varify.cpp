#include<bits/stdc++.h>
using namespace std;
double e=2.71828182846;
#define PI acos(-1)
double degree = PI/180.0;
int main(){
    double a;
    cin>>a;
    double b=20-a;
    cout<<(a+pow(a,0.5))*(b+pow(b,0.5))<<endl;
    //cout<<-0.25753*0.25753+3*0.25753-2<<endl;
    return 0;
}