#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
vector<vector<double>> matrix(4, vector<double>(4, 0));
vector<double> x(4, 0);
void palu();
int main() {
    int n = 12;
    vector<double> t(n, 0), y(n, 0);
    vector<vector<double>> A(n, vector<double>(4, 0)), AT(4, vector<double>(n, 0));
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
        cin >> y[i];;
    }
    for(int i = 0; i < n; ++i) {
        A[i][0] = 1;
        A[i][1] = cos(2 * PI * t[i]);
        A[i][2] = sin(2 * PI * t[i]);
        A[i][3] = cos(4 * PI * t[i]);
        AT[0][i] = A[i][0];
        AT[1][i] = A[i][1];
        AT[2][i] = A[i][2];
        AT[3][i] = A[i][3];
    }
    for(int i = 0; i < 4; ++i) {
        double sumT = 0;
        for(int j = 0; j < n; ++j) {
            double sum = 0;
            sumT += AT[i][j] * y[j];
            for(int k = 0; k < n; ++k) {
                sum += AT[i][k] * A[k][j];
            }
            if(abs(sum) < 1e-15) sum = 0;
            matrix[i][j] = sum;
        }
        x[i] = sumT;
    }

    palu();
    return 0;
}
void palu() {
    int m = 4, n = 4;
    vector<vector<double>> L(m, vector<double>(n, 0)), U(m, vector<double>(n, 0)), P(m, vector<double>(n, 0));
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
            x[j] = x[j] - x[i] * multi;
            if(abs(x[j]) < 1e-9) x[j] = 0;
        }
    }

    for(int i = 0; i < m; ++i)for(int j = 0; j < n; ++j) U[i][j] = matrix[i][j];

    //solution x

    for(int i = m - 1; i >= 0; --i) {
        for(int l = m - 1; l > i; --l) {
            x[i] -= U[i][l] * x[l];
        }
        x[i] /= U[i][i];
    }
    cout << "C:" << endl;
    for(auto i : x) cout << i << " ";
    cout << endl;
}