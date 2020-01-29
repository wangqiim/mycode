#include<cstdio>
#include<algorithm>
using namespace std;

struct mooncake{
    double store;   //库存
    double sell;    //总售价
    double price;   //单价
}cake[1010];

bool cmp(mooncake a,mooncake b){
    return a.price>b.price;
}

int main(){
    int n;
    double d;
    double res = 0;
    scanf("%d %lf",&n,&d);
    for(int i = 0; i<n; i++){
        scanf("%lf",&cake[i].store);
    }
    for(int i = 0;i<n;i++){
        scanf("%lf",&cake[i].sell);
        cake[i].price = cake[i].sell/cake[i].store;
    }
    sort(cake,cake+n,cmp);
    int i;
    for(i=0;i<n;i++){   //找到此时最合适卖的
        if(cake[i].store<=d){    //库存不够
            res += cake[i].sell;
            d -= cake[i].store;
        }
        else{   //够了
            res += d*cake[i].price;
            break;
        }
    }
    printf("%.2lf",res);
    return 0;
}