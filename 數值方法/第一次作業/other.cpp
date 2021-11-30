#include<iostream>
#include<cmath>
using namespace std;
#define PI acos(-1)
double degree = PI/180.0;
//double degree = 1;
int main() {
    cout << degree << endl;
    cout<<cos(45*degree)<<endl;
    return 0;
}