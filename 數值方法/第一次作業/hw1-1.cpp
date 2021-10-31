#include<iostream>
#include<cmath>
using namespace std;
//x-x^1/3-2 (3<x<4)
int main() {
    double low = 3, upper = 4, fmid, mid = 3.5,th=1.0/3.0;
    while( upper - low > 0.0000001 || (fmid > 0.0000001 && fmid < -0.0000001)) {
        fmid = mid - pow(mid, th) - 2;
        if(fmid < 0) low = mid;
        else if(fmid > 0) upper = mid;
        else break;
        mid = (low + upper) / 2.0;
    }
    cout << mid << endl;
    //cout<<mid - pow(mid, th) - 2<<endl;
    return 0;
}