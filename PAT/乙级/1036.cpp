#include<cstdio>

int main(){
    int r;
    char c;
    scanf("%d %c",&r,&c);
    for(int i=0;i<r;i++)    //第一行
        printf("%c",c);
    printf("\n");
    for(int i = 0;i<(r+1)/2-2;i++){
        printf("%c",c);
        for(int j = 1;j<r-1;j++)
            printf(" ");
        printf("%c",c);
        printf("\n");
    }
    for(int i=0;i<r;i++)    //最后一行
        printf("%c",c);
    return 0;
}
