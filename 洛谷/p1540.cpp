#include<cstdio>
#include<queue>
using namespace std;

const int maxn = 1001;

queue<int> q;
bool ismem[maxn] = {false}; //内存中有无该数字 
int len = 0;	//初始内存中无数字 

int main(){
	int m,n;	//m内存容量,n文章长度
	int res=0;	//查字典的次数 
	scanf("%d %d",&m,&n);
	int num; 
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(!ismem[num]){//内存中没有该数字
			res++;
			if(len<m){
				len++;
				q.push(num);
				ismem[num] = true;
			}else{	//内存容量不足需要替换 
				ismem[q.front()] = false;
				q.pop();
				q.push(num);
				ismem[num]=true;
			}
		}
	}
	printf("%d",res);
	return 0;
}
