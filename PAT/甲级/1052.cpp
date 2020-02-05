#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100005;

struct Node{
	int address,data,next;
	bool flag;	//防止有些结点输入了，但是不在链表上 
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false){
		return a.flag>b.flag;
	}else{
		return a.data<b.data;
	}
}

int main(){
	int n,start_address;
	scanf("%d%d",&n,&start_address);
	int t_addr,t_data,t_next;
	for(int i = 0;i<n;i++){
		scanf("%d%d%d",&t_addr,&t_data,&t_next);
		node[t_addr].address = t_addr;
		node[t_addr].data = t_data;
		node[t_addr].next = t_next;
	}
	
	int p = start_address;
	int val_n = 0;
	while(p!=-1){
		node[p].flag = true;
		p = node[p].next;
		val_n++;
	}
	if(val_n == 0){
		printf("0 -1");
		return 0;
	}
	sort(node,node+maxn,cmp);
	printf("%d %05d\n",val_n,node[0].address);
	printf("%05d %d ",node[0].address,node[0].data);
	int i;
	for(i = 1 ;i<val_n;i++){
		printf("%05d\n%05d %d ",node[i].address,node[i].address,node[i].data);
	}
	printf("-1\n");
	return 0; 
}
