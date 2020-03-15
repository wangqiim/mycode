#include<cstdio>

#define ll long long
const int maxn = 300005;	//���Ľ��Ҫ���ٶ࿪һ��
//��һ�����㷶Χ��ֵ�Ľṹ���ƺ�Ҳ����!
ll t[maxn];	//�߶��� 
ll tag[maxn];	//Ϊ�˼ӿ��������ĵ��ٶȣ����������

void f(int node,int left,int right,ll v){	
	//node�����ÿ��Ԫ�ض���v
	tag[node]+=v;
	t[node]+=v*(right-left+1);
	return;
}

void push_down(int node,int left,int right){
	//��node������Ǵ��ݵ��ӽڵ�
	int mid = (left+right)>>1;
	f(node*2  ,left ,mid  ,tag[node]);
	f(node*2+1,mid+1,right,tag[node]);
	tag[node] = 0;
	return;
}

void update(int node,int left,int right,int nl,int nr,ll v){	//�����޸�[nl~nr]����v 
	//node:��ǰ���;left,right����ȡֵ��Χ;nl,nrԭ����ķ�Χ
	if(nl<=left&&right<=nr){
		t[node] += v*(right-left+1);
		tag[node] += v;
		return;
	}
	push_down(node,left,right);	//��node��������Ǵ�����ȥ
	int mid = (left+right)>>1;
	if(nl<=mid) update(node*2,left,mid,nl,nr,v);
	if(mid+1<=nr) update(node*2+1,mid+1,right,nl,nr,v);
	t[node] = t[node*2]+t[node*2+1];//���� 
	return;
}

ll getsum(int node,int left,int right,int nl,int nr){	//������� 
	if(nl<=left&&right<=nr)
		return t[node];	//�ý�㷶Χ����Ҫ��͵����串��
    int mid=(left+right)>>1;
    push_down(node,left,right);	//������Ǵ�����ȥ
    ll res=0;
    if(nl<=mid)
		res+=getsum(node*2,left,mid,nl,nr);
    if(mid+1<=nr) 
		res+=getsum(node*2+1,mid+1,right,nl,nr);
    return res;
}

int n,m;//���ָ���,�������� 
int main(){
	scanf("%d %d",&n,&m);
	int o,x,y;
	ll k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		update(1,1,n,i,i,k);//nums[i]����k 
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&o);
		if(o==1){
			scanf("%d %d %lld",&x,&y,&k);//[x~y]�ڵļ���k 
			update(1,1,n,x,y,k);
		}else{
			scanf("%d %d",&x,&y);
			printf("%lld\n",getsum(1,1,n,x,y));
		}
	}
	return 0;
}
