#include<bits/stdc++.h>
using namespace std;
int main() {
    int m = 6, n = 6;
    vector<double> u(m, 0);
    vector<double> new_u(m, 0);
    vector<double> x(m, 0);
    vector<vector<double>> matrix(m, vector<double>(n, 0));
    vector<double> D(m, 0);
    vector<vector<double>> L(m, vector<double>(n, 0));
    vector<vector<double>> U(m, vector<double>(n, 0));
    for(auto &i : matrix)
        for(auto &j : i)
            cin >> j;
    for(auto &i : x) cin >> i;
    for(int i = 0; i < m; ++i) D[i] = matrix[i][i];
    for(int i = 1; i < m; ++i) {
        for(int j = 0; j < i; ++j) {
            L[i][j] = matrix[i][j];
            U[j][i] = matrix[j][i];
        }
    }
    int time = 0;
    while(++time) {
        if(time > 1 && abs(new_u[0] - u[0]) < 1e-6) break;
        for(int  i = 0; i < m; ++i) u[i] = new_u[i];
        for(int i = 0; i < m; ++i) {
            new_u[i] = x[i];
            for(int j = 0; j < n; ++j) {
                new_u[i] -= u[j] * U[i][j];
                new_u[i] -= new_u[j] * L[i][j];
            }
            new_u[i] /= D[i];
        }
    }
    for(auto i : new_u) cout << i << endl;
    return 0;
}