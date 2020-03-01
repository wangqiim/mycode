#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 200000;
const int maxnum = 100000;
int num,n,r,q;
struct player{
	int no;
	int s;//���Է���
	int w;//ʵ��ֵ 
}pls[maxn],win[maxnum],los[maxnum];
//ÿ��ʤ�߽���ʤ����,���߽���������ٴκϲ�O(n),��ֱ������O(nlogn)�� 

bool cmp(player a,player b){
	if(a.s!=b.s)
		return a.s>b.s;
	else 
		return a.no<b.no;
}

void merge(){	//�ϲ�win��los��pls��
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
	//2num��ѡ��,R�ֱ���,��������q
	scanf("%d %d %d",&num,&r,&q);
	n=num*2;
	for(int i=0;i<n;i++){
		pls[i].no = i+1;
		scanf("%d",&pls[i].s);
	}
	for(int i=0;i<n;i++) scanf("%d",&pls[i].w);
	sort(pls,pls+n,cmp);
	while(r--){
		for(int i=0;i<num;i++){	//ÿ�ηֳ�num�� 
			if(pls[2*i].w>pls[2*i+1].w){	//��������ʵ��ֵ������ͬ 
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
