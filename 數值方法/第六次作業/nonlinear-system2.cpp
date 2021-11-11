#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<double>> m(2, vector<double>(2, 0));
    vector<double> F = {-20, 37}, v1(2, 0);
    vector<vector<double>> D(2, vector<double>(2, 0));
    D = {{-4, -36}, {28, 26}};
    //v1 = jacobi(D, F);
    double mult = D[1][0] / D[0][0];
    for(int i = 0; i < 2; ++i) D[0][i] *= mult;
    F[0] = F[0] * mult - F[1];
    for(int i = 0; i < 2; ++i) D[0][i] -= D[1][i];
    F[0] /= D[0][1];
    F[1] = (F[1] - D[1][1] * F[0]) / D[1][0];
    for(auto i : F) cout << i << endl;
    double r = 64 + 16 * F[0] + F[0] * F[0] + 16 + 8 * F[1] + F[1] * F[1];
    cout << sqrt(r) << endl;
    return 0;
}