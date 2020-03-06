#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1000006;	//结点个数 

struct Aho{
	struct trienode{
		int next[26];
		int fail=-1;
		int cnt=0;	//是否匹配到模式串 
	}ac[maxn];
	queue<int> que;
	int ac_num=1;
	
	void init(){	//自动机初始化 
		for(int i=0;i<maxn;i++){
			memset(ac[i].next,0,sizeof(ac[i].next));
			ac[i].fail = ac[i].cnt = 0;
		}
		ac[0].fail = -1;
		ac_num = 1;
	}
	
	void insert(char *word) {
	    int p = 0;
	    int size = strlen(word);
	    for(int i=0;i<size;i++){
	    	char c = word[i];
	        if(ac[p].next[c-'a']==0)
	            ac[p].next[c-'a'] = ac_num++;
	        p = ac[p].next[c-'a'];
	    }
	    ac[p].cnt++;
	    return;
	}
	
	void build(){
		ac[0].fail = -1;
		que.push(0);
		while(!que.empty()){
			int p=que.front();
			que.pop();
			for(int i=0;i<26;i++){
				if(ac[p].next[i]!=0){
					int p2 = ac[p].fail;
					while(p2!=-1){
						if(ac[p2].next[i]!=0){
							ac[ac[p].next[i]].fail = ac[p2].next[i];
							break;
						}
						p2 = ac[p2].fail;
					}
					if(p2==-1) ac[ac[p].next[i]].fail = 0; 
					que.push(ac[p].next[i]);
				}
			}
		}
		return;
	}
	
	int query(char *words){
		int n = strlen(words);
		int res=0;
		int p = 0;
		for(int i=0;i<n;i++){
			char c = words[i];
			if(ac[p].next[c-'a']!=0)
				p = ac[p].next[c-'a'];
			else{
				p=ac[p].fail;
				while(p!=-1&&ac[p].next[c-'a']==0)
					p = ac[p].fail;
				if(p==-1) p = 0;
				else p = ac[p].next[c-'a'];
			}
			for(int p2=p;p2!=-1&&ac[p2].cnt!=-1;p2=ac[p2].fail){
				res+=ac[p2].cnt;
				ac[p2].cnt = -1;	//此处是一个优化点！ 
			}
		}
		return res;
	}
}aho;

char p[1000006];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){	//输入模式串
		scanf("%s",p);
		aho.insert(p);
	}
	aho.build();
	scanf("%s",p);
	printf("%d",aho.query(p));
	return 0;
}

