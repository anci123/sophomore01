#include<iostream>
using namespace std;
#define N 3//我自己假設的例子，這裡N等於4，結果a=1,b=2,c=3,d=4
double m[N][N + 1] = {
};
double s[N];
double v[N];
int loc[N];
void Allmin(int s, int n);//宣告函式，不然會報錯
void make1(int h, int n) {
    double t = m[h][n];
    if (m[h][n] == 0)
        return;
    for (int i = 0; i < N + 1; i++)
        m[h][i] /= t;
}
void setloc(int h, int n) {
    loc[h] = n;
}
void Allmake1(int n) {
    for (int i = 0; i < N; i++) {
        if (loc[i] == -1 && m[i][n] != 0)
            make1(i, n);
    }
}
void Onereplace(int n) {
    int l;
    for (int i = 0; i < N; i++) {
        if (loc[i] == -1 && m[i][n] != 0) {
            l = i;
            setloc(i, n);
            make1(i, n);
            break;
        }
    }
    Allmake1(n);
    Allmin(l, n);
}
void min(int s, int h, int n) {
    if(loc[h] == -1 && m[h][n] != 0)
        for (int i = 0; i < N + 1; i++)
            m[h][i] -= m[s][i];
}
void Allmin(int s, int n) {
    for (int i = 0; i < N; i++)
        min(s, i, n);
}
void Allreplace() {
    for (int i = 0; i < N; i++)
        Onereplace(i);
}
void cacular(int n) {
    for(int i = 0; i < N; i++) {
        if (loc[i] == n) {
            for (int k = 0; k < N; k++)
                if (m[i][k] != 0 && k != n)
                    m[i][N] -= m[i][k] * s[k];
            s[n] = m[i][N] / m[i][n];
            break;
        }
    }
}
void Allcacular() {
    for (int i = N - 1; i >= 0; i--)
        cacular(i);
}
void pc() {
    fill(loc, loc + N, -1);
    Allreplace();
    Allcacular();
}
void Cout() {
    for (int i = 0; i < N; i++)
        cout << s[i] << " ";
    cout << endl;
}
void Ffunc() {
    m[0][3] = 64 + (16 * v[0]) + (v[0] * v[0]) + 16 + (8 * v[1]) + (v[1] * v[1]) - (v[2] * v[2]);
    m[1][3] = 36 - (12 * v[0]) + (v[0] * v[0]) + 81 - (18 * v[1]) + (v[1] * v[1]) - (v[2] * v[2]);
    m[2][3] = 16 - (8 * v[0]) + (v[0] * v[0]) + 81 + (18 * v[1]) + (v[1] * v[1]) - (v[2] * v[2]);
}
void Dfunc() {
    m[0][0] = 2 * v[0] + 16;
    m[0][1] = 2 * v[1] + 8;
    m[0][2] = -2 * v[2];
    m[1][0] = 2 * v[0] - 12;
    m[1][1] = 2 * v[1] - 18;
    m[1][2] = -2 * v[2];
    m[2][0] = 2 * v[0] - 8;
    m[2][1] = 2 * v[1] + 18;
    m[2][2] = -2 * v[2];
}
void elimatiom() {
    Ffunc();
    Dfunc();
    pc();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N + 1; ++j) cout << m[i][j] << " ";
        cout << endl;
    }
    Cout();
    copy(s, s + 4, v);
}
int main() {
    for(int i = 0; i < 20; ++i) elimatiom();
    return 0;
}