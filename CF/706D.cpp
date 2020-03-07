#include<cstdio>
using namespace std;

const int maxn = 6000006;

struct Trie{
	int next[maxn][2];	//01trie
	int cnt[maxn];	//������ǰ�������ĸ��� 
	int node_num=1;	//��ǰֻ��һ�����ڵ� 
	
	void init(){	//01trie��ʼ�� 
		node_num=1;
		for(int i=0;i<maxn;i++){
			next[i][0]=next[i][1]=0;
			cnt[i] = 0;
		}
	}
	
	void insert(int x){	//���� 
		int t = 0x40000000;//��31λΪ1
		int now=0;	//01trie�ĸ��ڵ� 
		while(t!=0){//�����λһֱ���뵽���λ
			int xx = ((x&t)==0?0:1);	//�жϸ�λ��0����1 
			cnt[now]++;
			if(next[now][xx]==0) next[now][xx]=node_num++;
			now = next[now][xx];
			t>>=1;	//����һλ 
		}
		cnt[now]++;
		return;
	}
	
	void erase(int x){	//ɾ��ʱֻҪ��cnt������--���� 
		int t =0x40000000;
		int now=0;
		while(t!=0){
			int xx = ((x&t)==0?0:1);
			cnt[now]--;
			now = next[now][xx];	//ɾ��ʱ���Ѿ���֤�϶�ɾ�����ڵ������� 
			t>>=1;
		}
		cnt[now]--;
		return;
	}
	
	int find_max(int x){
		int t = 0x40000000;
		int now = 0;
		int res_max = 0;
		while(t!=0){
			res_max<<=1;
			int xx = ((x&t)==0?0:1);	//��Ϊ��^���,������ָ��ͬ�Ľ��
			if(next[now][1-xx]!=0&&cnt[next[now][1-xx]]>0){
				res_max+=1-xx;
				now = next[now][1-xx];
			}
			else{
				res_max+=xx;
				now = next[now][xx];
			}
			t>>=1;
		}
		return x^res_max;
	}
}mytrie;

int nums[maxn];
int len=0;

int main(){
	int n,num;
	char c;
	scanf("%d",&n);
	mytrie.init();
	mytrie.insert(0);
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %d",&c,&num);
		if(c=='+'){
			mytrie.insert(num);
		}else if(c=='-'){
			mytrie.erase(num);
		}else{
			nums[len++] = mytrie.find_max(num);
		}
	}
	for(int i=0;i<len;i++)
		printf("%d\n",nums[i]);
	return 0;
}

