#include<bits/stdc++.h>
using namespace std;
//x^5+x-1=0;
int main(){
    double prev=1,now=0;
    while(abs(prev-now)>0.00001){
        prev=now;
        now=prev-(pow(prev,5)+prev-1)/(5*pow(prev,4)+1);
    }
    cout<<now<<endl;
    return 0;
}