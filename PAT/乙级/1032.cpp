#include<cstdio>

int school_score[100001]={};

int main(){
    int n;  //行数
    scanf("%d",&n);
    int num,score;  //编号，成绩
    for(int i= 0;i<n;i++){  //输入n个数
        scanf("%d %d",&num,&score);
        school_score[num] += score;
    }
    int max_i=0,max_score=-1;    //存放最大成绩的编号和成绩
    for(int i = 1 ; i <= n;i++){ 
        if(max_score<school_score[i]){
            max_i = i;
            max_score=school_score[i];
        }
    }
    printf("%d %d",max_i,max_score);
    return 0;
}