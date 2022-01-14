#include<bits/stdc++.h>
using namespace std;
#define M 4
double x[M], y[M];
double f[M][M + 1];
bool fi[M][M];
void F(int index, int size) {
    if(size == 1) {
        f[index][size] = y[index];
        fi[index][size] = true;
        //cout<<f[index][size]<<endl;
        //cout<<index<<" "<<size<<endl;
        return;
    }
    if(!fi[index][size - 1]) F(index, size - 1);
    if(!fi[index - 1][size - 1]) F(index - 1, size - 1);
    if(fi[index][size - 1] && fi[index - 1][size - 1]) {
        f[index][size] = (f[index][size - 1] - f[index - 1][size - 1]) / (x[index] - x[index - size + 1]);
        fi[index][size] = true;
        //cout<<f[index][size]<<endl;
        //cout<<index<<" "<<size<<endl;
        return;
    }
}
int main() {
    memset(fi, 0, sizeof(fi));
    //cout << "input x: " << endl;
    for(int i = 0; i < M; ++i) cin >> x[i];
    //cout << "input y: " << endl;
    for(int i = 0; i < M; ++i) cin >> y[i];
    F(M - 1, M);
    /*for(int i = 0; i < M; ++i) {
        for(int j = 1; j <= M; ++j) cout << f[i][j] << " ";
        cout << endl;
    }*/
    double z, xx = 1;
    double ans;
    //cout << "input z: " << endl;
    cin >> z;
    ans=f[3][4];
   // cout << f[3][4] << endl;
    for(int i = M-1; i >0; --i) {
        //cout << x[i-1] << endl;
        ans *= (z - x[i-1]);
        ans += f[i-1][i];
        
    }
    cout << ans << endl;
    return 0;
}