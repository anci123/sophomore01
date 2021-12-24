#include<bits/stdc++.h>
using namespace std;
int main() {
    vector< vector<double>> r(2, vector<double>(2, 0)), q(2, vector<double>(2, 0)), y(2, vector<double>(2, 0)), a(2, vector<double>(2, 0));
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) cin >> a[i][j];
    y = a;
    for(int i = 0; i < 2; ++i) {
        if(i > 0) {
            for(int j = 0; j < 2; ++j) {
                y[j][i] = a[j][i] - q[j][i - 1] * r[i - 1][i];
            }
        }
        for(int j = 0; j < 2; ++j)
            r[i][i] += y[j][i] * y[j][i];
        r[i][i] = sqrt(r[i][i]);
        for(int j = 0; j < 2; ++j) q[j][i] = y[j][i] / r[i][i];
        if(i < 1) {
            for(int j = 0; j < 2; ++j) 
                r[i][i + 1] += q[j][i] * a[j][i + 1];
        }
    }
    cout<<'r'<<":"<<endl;
    for(auto i:r){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    cout<<'q'<<":"<<endl;
    for(auto i:q){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}