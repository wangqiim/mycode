#include<cstdio>

const int maxn = 100005;
//������ģ��ʵ��˫������ 
struct node{
	int l,r;
}nums[maxn];
int head = 1;

void insert(int i,int k,int p){
	if(p==0){//��i���뵽k�����(p=0)
		nums[i].l = nums[k].l;
		nums[nums[k].l].r = i;
		nums[k].l = i;
		nums[i].r = k;
		if(k==head) head = i;
	}else{//��i���뵽k���ұ�(p=1)
		nums[i].r = nums[k].r;
		nums[nums[k].r].l = i; 
		nums[k].r = i;
		nums[i].l = k;
	}
	return;
}

void erase(int i){	//ɾi
	if(nums[i].l==-1) return;	//�ý���Ѿ�ɾ����һ����  
	int left = nums[i].l,right = nums[i].r;
	if(head==i) head = right;
	nums[left].r = right;
	nums[right].l = left;
	nums[i].l = -1;
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	int k,p;
	for(int i=2;i<=n;i++){	//2-n�Ž����� 
		scanf("%d %d",&k,&p);
		insert(i,k,p);
	}
	int m;	//ȥ����ͬѧ����Ŀ 
	scanf("%d",&m);
	int x;
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		erase(x);
	}
	for(int i=head;i!=0;i=nums[i].r){
		printf("%d ",i);
	}
	return 0;
}
