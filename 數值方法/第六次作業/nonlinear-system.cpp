#include<bits/stdc++.h>
using namespace std;
vector<double> jacobi(vector<vector<double>> D, vector<double> F) {
    int m = 3, n = 3;
    vector<vector<double>> L(m, vector<double>(n, 0)), U(m, vector<double>(n, 0)), P(m, vector<double>(n, 0));
    vector<double> x(F);
    vector<vector<double>> matrix(D);
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
            if(abs(x[j]) < 1e-6) x[j] = 0;
        }
    }
    for(int i = 0; i < m; ++i)for(int j = 0; j < n; ++j) U[i][j] = matrix[i][j];
    for(int i = 0; i < n; ++i) L[i][i] = 1;
    /*for(auto i:U){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    for(auto i:x) cout<<i<<"";
    cout<<endl;*/
    for(int i = m - 1; i >= 0; --i) {
        for(int l = m - 1; l > i; --l) {
            x[i] -= U[i][l] * x[l];
        }
        if(abs(U[i][i])>1e-4)x[i] /= U[i][i];
    }
    cout << "x:" << endl;
    for(auto i : x) cout << i << " ";
    cout << endl;
    return x;
}
vector<double> Ffunc(vector<double> v) {
    vector<double> f(3, 0);
    f[0] = 64 + 16 * v[0] + v[0] * v[0] + 16 + 8 * v[1] + v[1] * v[1] - v[2] * v[2];
    f[1] = 36 - 12 * v[0] + v[0] * v[0] + 81 - 18 * v[1] + v[1] * v[1] - v[2] * v[2];
    f[2] = 16 - 8 * v[0] + v[0] * v[0] + 81 + 18 * v[1] + v[1] * v[1] - v[2] * v[2];
    for(int i=0;i<3;++i) f[i]*=-1;
    return f;
}
vector<vector<double>> Dfunc(vector<double> v) {
    vector<vector<double>> d(3, vector<double>(3, 0));
    d[0][0] = 2 * v[0] + 16;
    d[0][1] = 2 * v[1] + 8;
    d[0][2] = -2 * v[2];
    d[1][0] = 2 * v[0] - 12;
    d[1][1] = 2 * v[1] - 18;
    d[1][2] = -2 * v[2];
    d[2][0] = 2 * v[0] - 8;
    d[2][1] = 2 * v[1] + 18;
    d[2][2] = -2 * v[2];
    return d;
}
int main() {
    vector<vector<double>> m(3, vector<double>(3, 0));
    vector<double> v0(3, 1), v1(3, 0);
    for(int k = 0; k < 25; ++k) {
    //while(abs(v1[0] - v0[0]) > 1e-4 && abs(v1[1] - v0[1]) > 1e-4 && abs(v1[2] - v0[2]) > 1e-4) {
        vector<double> F = Ffunc(v0);
        //for(auto i : F) cout << i << endl;
        vector<vector<double>> D = Dfunc(v0);
        //for(auto i : D) for(auto j : i) cout << j << endl;
        v0 = v1;
        v1 = jacobi(D, F);
    }
    for(auto i : v1) cout << i << endl;
    //double r=64 + 16 * v1[0] + v1[0] * v1[0] + 16 + 8 * v1[1] + v1[1] * v1[1] - v1[2] * v1[2];
    //cout<<sqrt(r)<<endl;
    return 0;
}