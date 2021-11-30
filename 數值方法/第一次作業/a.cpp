#include<iostream>
#include<cmath>
using namespace std;
double e=2.71828182846;
#define PI acos(-1)
double degree = PI/180.0;
int main() {
    double low = -50, upper = 100, fmid, mid = (low+upper)/2;
    while( upper - low > 0.0000001 || (fmid > 0.0000001 && fmid < -0.0000001)) {
        fmid = pow(mid,1.4)-pow(mid,0.5)+1/mid-100;
        if(fmid < 0) low = mid;
        else if(fmid > 0) upper = mid;
        else break;
        mid = (low + upper) / 2.0;
    }
    cout << mid << endl;
    //cout<<mid - pow(mid, th) - 2<<endl;
    return 0;
}