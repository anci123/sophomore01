#include<bits/stdc++.h>
using namespace std;
int main() {
    vector< vector<double>> r(5, vector<double>(3, 0)), q(5, vector<double>(3, 0)), y(5, vector<double>(3, 0)), a(5, vector<double>(3, 0));
    for(int i = 0; i < 5; ++i) for(int j = 0; j < 3; ++j) cin >> a[i][j];
    y = a;
    for(int i = 0; i < 3; ++i) {
        if(i > 0) {
            for(int j = 0; j < 5; ++j) y[j][i] = a[j][i];
            for(int k = 1; k <= i; ++k) {
                for(int j = 0; j < 5; ++j) {
                    y[j][k] -= q[j][k - 1] * r[k - 1][k];
                }
            }
        }
        for(int j = 0; j < 5; ++j)
            r[i][i] += y[j][i] * y[j][i];
        r[i][i] = sqrt(r[i][i]);
        for(int j = 0; j < 5; ++j) q[j][i] = y[j][i] / r[i][i];
        if(i < 1) {
            for(int j = 0; j < 5; ++j)
                r[i][i + 1] += q[j][i] * a[j][i + 1];
        }
    }
    cout << 'r' << ":" << endl;
    for(auto i : r) {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    cout << 'q' << ":" << endl;
    for(auto i : q) {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    cout<<0.640513*-0.640513+0.549369*2.56705<<endl;
    return 0;
}