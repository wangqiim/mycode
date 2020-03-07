#include<cstdio>
using namespace std;

const int maxn = 6000006;

struct Trie{
	int next[maxn][2];	//01trie
	int cnt[maxn];	//经过当前结点的数的个数 
	int node_num=1;	//当前只有一个根节点 
	
	void init(){	//01trie初始化 
		node_num=1;
		for(int i=0;i<maxn;i++){
			next[i][0]=next[i][1]=0;
			cnt[i] = 0;
		}
	}
	
	void insert(int x){	//插入 
		int t = 0x40000000;//第31位为1
		int now=0;	//01trie的根节点 
		while(t!=0){//从最高位一直插入到最低位
			int xx = ((x&t)==0?0:1);	//判断该位是0还是1 
			cnt[now]++;
			if(next[now][xx]==0) next[now][xx]=node_num++;
			now = next[now][xx];
			t>>=1;	//右移一位 
		}
		cnt[now]++;
		return;
	}
	
	void erase(int x){	//删除时只要把cnt计数器--即可 
		int t =0x40000000;
		int now=0;
		while(t!=0){
			int xx = ((x&t)==0?0:1);
			cnt[now]--;
			now = next[now][xx];	//删除时候已经保证肯定删除存在的数字了 
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
			int xx = ((x&t)==0?0:1);	//因为是^异或,尽量找指不同的结点
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

