#include<bits/stdc++.h>
using namespace std;
//lnx+x^2-3=0;
//f'(x)=1/x+2x
//e=2.71828182846
int main(){
    double prev=1,now=10,e=2.71828182846;
    while(abs(prev-now)>0.00001){
        prev=now;
        now=prev-(log(prev)/log(e)+prev*prev-3)/(1/prev+2*prev);
    }
    cout<<now<<endl;
    return 0;
}