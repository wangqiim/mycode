#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200000;
const int maxnum = 100000;
int num,n,r,q;
struct player{
	int no;
	int s;//初试分数
	int w;//实力值 
}pls[maxn],win[maxnum],los[maxnum];
//每次胜者进入胜者组,败者进入败者组再次合并O(n),比直接排序O(nlogn)快 

bool cmp(player a,player b){
	if(a.s!=b.s)
		return a.s>b.s;
	else 
		return a.no<b.no;
}

void merge(){	//合并win和los到pls中
	int i=0,w=0,l=0; 
	while(w<num&&l<num){
		if(cmp(win[w],los[l]))
			pls[i++]=win[w++];
		else
			pls[i++]=los[l++];
	}
	while(w<num)
		pls[i++]=win[w++];
	while(l<num)
		pls[i++]=los[l++];
	return;
}

int main(){
	//2num名选手,R轮比赛,关心名次q
	scanf("%d %d %d",&num,&r,&q);
	n=num*2;
	for(int i=0;i<n;i++){
		pls[i].no = i+1;
		scanf("%d",&pls[i].s);
	}
	for(int i=0;i<n;i++) scanf("%d",&pls[i].w);
	sort(pls,pls+n,cmp);
	while(r--){
		for(int i=0;i<num;i++){	//每次分成num组 
			if(pls[2*i].w>pls[2*i+1].w){	//根据题意实力值不会相同 
				pls[2*i].s++;
				win[i] = pls[2*i];
				los[i] = pls[2*i+1];
			}
			else{
				pls[2*i+1].s++;
				win[i] = pls[2*i+1];
				los[i] = pls[2*i];
			}
		}		
		merge();
	}
	printf("%d",pls[q-1].no);
	return 0;
}
