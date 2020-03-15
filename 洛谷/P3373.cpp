#include<cstdio>

#define ll long long
const int maxn = 300005;	//树的结点要至少多开一倍
//用一个存结点范围和值的结构体似乎也不错!
ll t[maxn];	//线段树 
ll tag_mul[maxn]; //乘懒标记 
ll tag_add[maxn]; //加懒标记
int p;
//加法优先，即规定好segtree[root*2].value=((segtree[root*2].value+segtree[root].add)*segtree[root].mul)%p，
//问题是这样的话非常不容易进行更新操作，假如改变一下add的数值，mul也要联动变成奇奇怪怪的分数小数损失精度，我们内心是很拒绝的；
//乘法优先，即规定好segtree[root*2].value=(segtree[root*2].value*segtree[root].mul+segtree[root].add*(本区间长度))%p，
//这样的话假如改变add的数值就只改变add，改变mul的时候把add也对应的乘一下就可以了，没有精度损失，看起来很不错。
//https://www.luogu.com.cn/problemnew/solution/P3373根据分析选择先乘再加
 
void f(int node,int left,int right,ll v_mul,ll v_add){	//接受乘和加懒标记 
	//node区间的每个元素都先乘以用乘懒标记再用加懒标记 
	tag_add[node] = (tag_add[node] * v_mul+v_add)%p;
	tag_mul[node] = (tag_mul[node] * v_mul)%p;
	t[node] = (v_mul*t[node] +v_add*(right-left+1))%p;
	return;
}

void push_down(int node,int left,int right){
	//把node的懒标记传递到子节点
	int mid = (left+right)>>1;
	f(node*2  ,left ,mid  ,tag_mul[node],tag_add[node]);
	f(node*2+1,mid+1,right,tag_mul[node],tag_add[node]);
	tag_add[node] = 0;
	tag_mul[node] = 1;
	return;
}

void update_add(int node,int left,int right,int nl,int nr,ll v){	//区间修改[nl~nr]都加v 
	//node:当前结点;left,right结点的取值范围;nl,nr原数组的范围
	if(nl<=left&&right<=nr){
		t[node] =(t[node] + v*(right-left+1))%p;
		tag_add[node] += v;
		return;
	}
	push_down(node,left,right);	//把node结点的懒标记传递下去
	int mid = (left+right)>>1;
	if(nl<=mid) update_add(node*2,left,mid,nl,nr,v);
	if(mid+1<=nr) update_add(node*2+1,mid+1,right,nl,nr,v);
	t[node] = (t[node*2]+t[node*2+1])%p;//回溯 
	return;
}

void update_mul(int node,int left,int right,int nl,int nr,ll v){	//区间修改[nl~nr]都乘以v 
	//node:当前结点;left,right结点的取值范围;nl,nr原数组的范围
	if(nl<=left&&right<=nr){
		t[node] =(t[node]*v)%p;
		tag_add[node] *= v;
		tag_mul[node] *= v;
		return;
	}
	push_down(node,left,right);	//把node结点的懒标记传递下去
	int mid = (left+right)>>1;
	if(nl<=mid) update_mul(node*2,left,mid,nl,nr,v);
	if(mid+1<=nr) update_mul(node*2+1,mid+1,right,nl,nr,v);
	t[node] = (t[node*2]+t[node*2+1])%p;//回溯  
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
    return res%p;
}

int n,m;//数字个数,操作个数 
int main(){
	for(int i=1;i<=maxn;i++)
		tag_mul[i] = 1;
	scanf("%d %d %d",&n,&m,&p);
	int o,x,y;
	ll k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		update_add(1,1,n,i,i,k);//nums[i]加上k 
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&o);
		if(o==1){
			scanf("%d %d %lld",&x,&y,&k);//[x~y]内的加上k 
			update_mul(1,1,n,x,y,k);
		}else if(o==2){
			scanf("%d %d %lld",&x,&y,&k);//[x~y]内的加上k 
			update_add(1,1,n,x,y,k);
		}else{
			scanf("%d %d",&x,&y);
			printf("%lld\n",getsum(1,1,n,x,y));
		}
	}
	return 0;
}
