#include<cstdio>

#define ll long long
const int maxn = 300005;	//���Ľ��Ҫ���ٶ࿪һ��
//��һ�����㷶Χ��ֵ�Ľṹ���ƺ�Ҳ����!
ll t[maxn];	//�߶��� 
ll tag_mul[maxn]; //������� 
ll tag_add[maxn]; //�������
int p;
//�ӷ����ȣ����涨��segtree[root*2].value=((segtree[root*2].value+segtree[root].add)*segtree[root].mul)%p��
//�����������Ļ��ǳ������׽��и��²���������ı�һ��add����ֵ��mulҲҪ�����������ֵֹķ���С����ʧ���ȣ����������Ǻܾܾ��ģ�
//�˷����ȣ����涨��segtree[root*2].value=(segtree[root*2].value*segtree[root].mul+segtree[root].add*(�����䳤��))%p��
//�����Ļ�����ı�add����ֵ��ֻ�ı�add���ı�mul��ʱ���addҲ��Ӧ�ĳ�һ�¾Ϳ����ˣ�û�о�����ʧ���������ܲ���
//https://www.luogu.com.cn/problemnew/solution/P3373���ݷ���ѡ���ȳ��ټ�
 
void f(int node,int left,int right,ll v_mul,ll v_add){	//���ܳ˺ͼ������ 
	//node�����ÿ��Ԫ�ض��ȳ����ó���������ü������ 
	tag_add[node] = (tag_add[node] * v_mul+v_add)%p;
	tag_mul[node] = (tag_mul[node] * v_mul)%p;
	t[node] = (v_mul*t[node] +v_add*(right-left+1))%p;
	return;
}

void push_down(int node,int left,int right){
	//��node������Ǵ��ݵ��ӽڵ�
	int mid = (left+right)>>1;
	f(node*2  ,left ,mid  ,tag_mul[node],tag_add[node]);
	f(node*2+1,mid+1,right,tag_mul[node],tag_add[node]);
	tag_add[node] = 0;
	tag_mul[node] = 1;
	return;
}

void update_add(int node,int left,int right,int nl,int nr,ll v){	//�����޸�[nl~nr]����v 
	//node:��ǰ���;left,right����ȡֵ��Χ;nl,nrԭ����ķ�Χ
	if(nl<=left&&right<=nr){
		t[node] =(t[node] + v*(right-left+1))%p;
		tag_add[node] += v;
		return;
	}
	push_down(node,left,right);	//��node��������Ǵ�����ȥ
	int mid = (left+right)>>1;
	if(nl<=mid) update_add(node*2,left,mid,nl,nr,v);
	if(mid+1<=nr) update_add(node*2+1,mid+1,right,nl,nr,v);
	t[node] = (t[node*2]+t[node*2+1])%p;//���� 
	return;
}

void update_mul(int node,int left,int right,int nl,int nr,ll v){	//�����޸�[nl~nr]������v 
	//node:��ǰ���;left,right����ȡֵ��Χ;nl,nrԭ����ķ�Χ
	if(nl<=left&&right<=nr){
		t[node] =(t[node]*v)%p;
		tag_add[node] *= v;
		tag_mul[node] *= v;
		return;
	}
	push_down(node,left,right);	//��node��������Ǵ�����ȥ
	int mid = (left+right)>>1;
	if(nl<=mid) update_mul(node*2,left,mid,nl,nr,v);
	if(mid+1<=nr) update_mul(node*2+1,mid+1,right,nl,nr,v);
	t[node] = (t[node*2]+t[node*2+1])%p;//����  
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
    return res%p;
}

int n,m;//���ָ���,�������� 
int main(){
	for(int i=1;i<=maxn;i++)
		tag_mul[i] = 1;
	scanf("%d %d %d",&n,&m,&p);
	int o,x,y;
	ll k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		update_add(1,1,n,i,i,k);//nums[i]����k 
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&o);
		if(o==1){
			scanf("%d %d %lld",&x,&y,&k);//[x~y]�ڵļ���k 
			update_mul(1,1,n,x,y,k);
		}else if(o==2){
			scanf("%d %d %lld",&x,&y,&k);//[x~y]�ڵļ���k 
			update_add(1,1,n,x,y,k);
		}else{
			scanf("%d %d",&x,&y);
			printf("%lld\n",getsum(1,1,n,x,y));
		}
	}
	return 0;
}
