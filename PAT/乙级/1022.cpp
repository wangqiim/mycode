#include<cstdio>

int res[32]={0};

int main(){
    int a,b,d,n;
    scanf("%d %d %d",&a,&b,&d);
    a = a+b;
    if(a==0)
        n=1;
    else
        n=0;
    while(a>0){
        res[n] = a%d;
        a/=d;
        n++;
    }
    for(n = n-1;n>=0;n--)
        printf("%d",res[n]);
    return 0;
}