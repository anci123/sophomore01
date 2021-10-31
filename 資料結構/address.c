#include<stdio.h>
int main(){
    int a[3]={1,2,3};
    for(int i=0;i<3;++i){
        printf("%8p %2d\n",a+i,*(a+i));
    }
    return 0;
}