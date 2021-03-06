#include<bits/stdc++.h>
using namespace std;
int main() {
    vector< vector<double>> r(4, vector<double>(3, 0)), q(4, vector<double>(3, 0)), y(4, vector<double>(3, 0)), a(4, vector<double>(3, 0));
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) cin >> a[i][j];
    y = a;
    for(int i = 0; i < 3; ++i) {
        if(i > 0) {
            for(int j = 0; j < 4; ++j) y[j][i] = a[j][i];
            for(int k = 1; k <= i; ++k) {
                for(int j = 0; j < 4; ++j) {
                    y[j][k] -= q[j][k - 1] * r[k - 1][k];
                }
            }
        }
        for(int j = 0; j < 4; ++j)
            r[i][i] += y[j][i] * y[j][i];
        r[i][i] = sqrt(r[i][i]);
        for(int j = 0; j < 4; ++j) q[j][i] = y[j][i] / r[i][i];
        if(i < 1) {
            for(int j = 0; j < 4; ++j)
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
    return 0;
}