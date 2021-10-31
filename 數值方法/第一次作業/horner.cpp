#include<iostream>
using namespace std;
int main(){
    double x=1.0001,xx=1,ans=1;
    int time=50;
    for(int i=0;i<time;++i){
        xx*=x;
        ans+=1*xx;
    }
    cout<<ans<<endl;
    return 0;
}