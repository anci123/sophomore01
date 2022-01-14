//nolinear
#include<bits/stdc++.h>
using namespace std;
double e=2.71828182846;

double myabs(double a){
	if(a >= 0)
	return a;
  else 
	return 0-a;
}
int main(void) {
  
	//f1 = 64+16h+h*h + 16+8k+k*k - r*r 
	//f2 = 36-12h+h*h + 81-18k+k*k - r*r
	//f3 = 16-8h+h*h + 81+18k+k*k - r*r
	double xk[3] = {-1,-2,1};
  double Df[3][3] = {0};
	double F[3] = {0};
	double s[3] = {0};

	int go = -3;
  int tmp = 0;
	while(go){
		//xk代入Df
		
		Df[0][0] = 3*xk[0]*xk[0] +2*xk[0]-1;
		Df[0][1] = 1;
		Df[0][2] = -1;
		Df[1][0] = xk[0]*pow(e,xk[0]);
		Df[1][1] = xk[1]*pow(e,xk[1]);
		Df[1][2] = -1;
		Df[2][0] = -2;
		Df[2][1] = 2*xk[1]*xk[1];
		Df[2][2] = (-2);
    //xk代入方程式
		F[0] = pow(xk[0],3)+xk[0]*xk[0]*xk[1]-xk[0]*xk[2]+6;
		F[1] = pow(e,xk[0]),pow(e,xk[1])-xk[2];
		F[2] = xk[1]*xk[1]-2*xk[0]*xk[2]-4;

		
		double U[3][3] = {0};
		for(int32_t i = 0;i<3;i++){
			for(int32_t j = 0;j<3;j++){
				U[i][j] = Df[i][j];
			}
		}

		for(int32_t i = 0;i < 2;i++){
			for(int32_t j = i+1;j<3;j++){
				double l= U[j][i]/U[i][i];
				for(int32_t m = i;m<3;m++){
					U[j][m] = U[j][m] - (l*U[i][m]);
					//printf("%d ", U[j][m]);
				}
			}
		}

		//Df(xk)s = -F(xk)，求s
		
		s[2] = (0-F[2])/U[2][2];
		s[1] = ((0-F[1])-(s[2]*U[1][2]))/U[1][1];
		s[0] = ((0-F[0])-(s[2]*U[0][2]+s[1]*U[0][1]))/U[0][0];

		
		
		for(int32_t i = 0;i<3;i++){
			if(myabs(s[i])< 0.00001)
				go =0;
		}
		if(go){//x(k+1) = xk+s
			for(int32_t i = 0;i<3;i++){
				xk[i] = xk[i]+s[i];
			}
		}
	}
	

	for(int32_t i =0;i<3;i++){
		printf("u%d: %.4lf \n", i+1, xk[i]);
	}
	
  return 0;
}