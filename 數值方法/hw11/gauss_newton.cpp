#include<bits/stdc++.h>
using namespace std;
int M = 3, N = 2;
void palu(vector<vector<double>> &matrix, vector<double> &x);
void Rvec(vector<double> x, vector<double> y, vector<double> R, vector<double> &r, double xx, double yy) {
    for(int i = 0; i < M; ++i) {
        r[i] = sqrt((xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i])) - R[i];
        //cout<<r[i]<<endl;
    }
}
void Dmetric(vector<double> x, vector<double> y, vector<vector<double>> &Dr, double xx, double yy) {
    for(int i = 0; i < M; ++i) {
        double S = sqrt((xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i]));
        Dr[i][0] = (xx - x[i]) / S;
        Dr[i][1] = (yy - y[i]) / S;
    }

}
void Dtmetrix(vector<vector<double>> Dr, vector<vector<double>> &Dt) {
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            Dt[j][i] = Dr[i][j];
        }
    }
}
void DtD_generate(vector<vector<double>> Dr, vector<vector<double>> Dt, vector<vector<double>> &DrdDr) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            DrdDr[i][j] = 0;
            for(int k = 0; k < M; ++k) {
                DrdDr[i][j] += Dt[i][k] * Dt[j][k];
            }
            //cout<<DrdDr[i][j]<<" ";
        }
        //cout<<endl;
    }
}
void negDtr_generae(vector<vector<double>> Dr, vector<double> r, vector<double> &Drt) {
    for(int i = 0; i < N; ++i) {
        Drt[i] = 0;
        for(int j = 0; j < M; ++j) {
            Drt[i] -= Dr[j][i] * r[j];
        }
        //cout<<Drt[i]<<" ";
    }
    //cout<<endl;
}
int main() {
    vector<vector<double>> Dr(3, vector<double>(2, 0)), Dt(3, vector<double>(3, 0)), DrdDr(2, vector<double>(2, 0));
    vector<double> r(3, 0), Dtr(2, 0), x(3, 0), y(3, 0), R(3, 0);
    double xx = -1, yy = -1;
    for(int i = 0; i < 3; ++i) cin >> x[i] >> y[i] >> R[i];
    int t = 5;
    //xx+=Dtr[0],yy+=Dtr[1];
    Rvec(x, y, R, r, xx, yy);
    Dmetric(x, y, Dr, xx, yy);
    Dtmetrix(Dr, Dt);
    DtD_generate(Dr, Dt, DrdDr);
    negDtr_generae(Dr, r, Dtr);
    palu(DrdDr, Dtr);
    while(abs(Dtr[0]) > 1e-8 && abs(Dtr[1]) > 1e-8) {
        xx += Dtr[0], yy += Dtr[1];
        if(abs(xx) < 1e-4) xx=0;
        if(abs(yy) < 1e-4) yy=0;
        //cout << xx << " " << yy << endl;
        Rvec(x, y, R, r, xx, yy);
        Dmetric(x, y, Dr, xx, yy);
        Dtmetrix(Dr, Dt);
        DtD_generate(Dr, Dt, DrdDr);
        negDtr_generae(Dr, r, Dtr);
        palu(DrdDr, Dtr);
    }
    cout<<xx<<" "<<yy<<endl;
}
void palu(vector<vector<double>> &matrix, vector<double> &x) {
    int m = 2, n = 2;
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
    /*    cout << "v:" << endl;
        for(auto i : x) cout << i << " ";
        cout << endl;
    */
}
