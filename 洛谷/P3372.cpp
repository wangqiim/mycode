#include<cstdio>

#define ll long long
const int maxn = 300005;	//树的结点要至少多开一倍
//用一个存结点范围和值的结构体似乎也不错!
ll t[maxn];	//线段树 
ll tag[maxn];	//为了加快区间插入的的速度，引入懒标记

void f(int node,int left,int right,ll v){	
	//node区间的每个元素都加v
	tag[node]+=v;
	t[node]+=v*(right-left+1);
	return;
}

void push_down(int node,int left,int right){
	//把node的懒标记传递到子节点
	int mid = (left+right)>>1;
	f(node*2  ,left ,mid  ,tag[node]);
	f(node*2+1,mid+1,right,tag[node]);
	tag[node] = 0;
	return;
}

void update(int node,int left,int right,int nl,int nr,ll v){	//区间修改[nl~nr]都加v 
	//node:当前结点;left,right结点的取值范围;nl,nr原数组的范围
	if(nl<=left&&right<=nr){
		t[node] += v*(right-left+1);
		tag[node] += v;
		return;
	}
	push_down(node,left,right);	//把node结点的懒标记传递下去
	int mid = (left+right)>>1;
	if(nl<=mid) update(node*2,left,mid,nl,nr,v);
	if(mid+1<=nr) update(node*2+1,mid+1,right,nl,nr,v);
	t[node] = t[node*2]+t[node*2+1];//回溯 
	return;
}

ll getsum(int node,int left,int right,int nl,int nr){	//区间求和 
	if(nl<=left&&right<=nr)
		return t[node];	//该结点范围被需要求和的区间覆盖
    int mid=(left+right)>>1;
    push_down(node,left,right);	//把懒标记传递下去
    ll res=0;
    if(nl<=mid)
		res+=getsum(node*2,left,mid,nl,nr);
    if(mid+1<=nr) 
		res+=getsum(node*2+1,mid+1,right,nl,nr);
    return res;
}

int n,m;//数字个数,操作个数 
int main(){
	scanf("%d %d",&n,&m);
	int o,x,y;
	ll k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		update(1,1,n,i,i,k);//nums[i]加上k 
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&o);
		if(o==1){
			scanf("%d %d %lld",&x,&y,&k);//[x~y]内的加上k 
			update(1,1,n,x,y,k);
		}else{
			scanf("%d %d",&x,&y);
			printf("%lld\n",getsum(1,1,n,x,y));
		}
	}
	return 0;
}
