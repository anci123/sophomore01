#include<bits/stdc++.h>
using namespace std;
int main() {
    int m = 4, n = 4;
    vector<vector<double>> L(m, vector<double>(n, 0)), U(m, vector<double>(n, 0)), P(m, vector<double>(n, 0)), matrix(m, vector<double>(n, 0));
    for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) cin >> matrix[i][j];
    vector<double> x(m);
    for(int i = 0; i < m; ++i) cin >> x[i];
    for(int i = 0; i < n; ++i) P[i][i] = 1;
    double multi = 0;
    for(int i = 0; i < n; ++i) {
        int maxP = matrix[i][i], maxIndex = i;
        for(int p = i; p < m; ++p) {
            if(abs(matrix[p][i]) > maxP) {
                maxP = abs(matrix[p][i]);
                maxIndex = p;
            }
        }
        swap(matrix[i], matrix[maxIndex]);
        swap(P[i], P[maxIndex]);
        swap(L[i], L[maxIndex]);
        swap(x[i], x[maxIndex]);
        for(int j = i + 1; j < m; ++j) {
            multi = matrix[j][i] / matrix[i][i];
            L[j][i] = multi;
            for(int k = 0; k < n; ++k) {
                matrix[j][k] = matrix[j][k] - matrix[i][k] * multi;
                if(abs(matrix[j][k]) < 1e-9) matrix[j][k] = 0;
            }
            x[j]=x[j]-x[i]*multi;
            if(abs(x[j]) < 1e-9) x[j] = 0;
        }
    }

    for(int i = 0; i < m; ++i)for(int j = 0; j < n; ++j) U[i][j] = matrix[i][j];
    cout << "P:" << endl;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }
    cout << "L:" << endl;
    for(int i = 0; i < n; ++i) L[i][i] = 1;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << "U:" << endl;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }
    //solution x

    for(int i = m - 1; i >= 0; --i) {
        for(int l = m - 1; l > i; --l) {
            x[i] -= U[i][l] * x[l];
        }
        x[i] /= U[i][i];
    }
    cout << "x:" << endl;
    for(auto i : x) cout << i << " ";
    cout << endl;
    return 0;
}