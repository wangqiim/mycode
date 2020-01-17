#include<cstdio>

int main(){
    int time = 0;
    int n;
    scanf("%d",&n);
    while(n!=1){
        if(n%2==0)
            n /= 2;
        else
            n = (3*n+1)/2;
        time++;
    }
    printf("%d\n",time);
    return 0;
}