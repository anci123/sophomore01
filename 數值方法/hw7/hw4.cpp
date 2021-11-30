#include<bits/stdc++.h>
using namespace std;
int main(){
  int size=0;
  cin>>size;
  double x[100]={0},y[100]={0},d=0,up=0,low=0,ans=0;
  cout<<"input x,y"<<endl;
  for(int i=0;i<size;++i){
    cin>>x[i];
    cin>>y[i];
  }
  cin>>d;
  for(int k=0;k<size;++k){
    up=y[k];
    low=1;
    for(int j=0;j<size;++j){
      if(j==k) continue;
      up*=(d-x[j]);
      low*=(x[k]-x[j]);
      //cout<<up<<" "<<low<<endl;
      //cout<<j<<endl;
    }
    ans+=(up/low);
  }
  cout<<ans<<endl;
  return 0;
}
/*
1 0.1924
1.05 0.2414
1.1 0.2933
1.15 0.3492
1.09
*/