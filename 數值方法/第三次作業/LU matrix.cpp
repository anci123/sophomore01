#include<bits/stdc++.h>
using namespace std;
int main() {
    int m = 4, n = 4;
    double L[m][n], U[m][n];
    double matrix[m][n] = {
        {1, 1, 0, 3},
        {2, 1, -1, 1},
        {3, -1, -1, 2},
        {-1, 2, 3, -1}
    };
    memset(L, 0, sizeof(L));
    memset(U, 0, sizeof(U));
    for(int i = 0; i < n; ++i) L[i][i] = 1;
    double multi = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < m; ++j) {
            multi = matrix[j][i] / matrix[i][i];
            L[j][i] = multi;
            for(int k = 0; k < n; ++k) {
                matrix[j][k] = matrix[j][k] - matrix[i][k] * multi;
            }
    }
    for(int i = 0; i < m; ++i)for(int j = 0; j < n; ++j) U[i][j] = matrix[i][j];
    cout << "L:" << endl;
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
    return 0;
}