#include<cstdio>
#include<deque>
using namespace std;
//ʹ��deque(���ԴӶ���ͷ��ɾ��Ԫ��) 
const int maxn = 1000006;
int nums[maxn];
deque<pair<int,int> > dq_ma;
deque<pair<int,int> > dq_mi; //firstֵ,second�� 

int main(){
	int n,k;//n���г�,k���ڴ�С 
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&nums[i]);
	}
	for(int i=0;i<n;i++){
		while(!dq_mi.empty()&&dq_mi.back().first>=nums[i])
			dq_mi.pop_back();
		dq_mi.push_back(make_pair(nums[i],i));
		if(dq_mi.front().second==i-k)
			dq_mi.pop_front();
		if(i>=k-1)
			printf("%d ",dq_mi.front().first);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		while(!dq_ma.empty()&&dq_ma.back().first<=nums[i])
			dq_ma.pop_back();
		dq_ma.push_back(make_pair(nums[i],i));
		if(dq_ma.front().second==i-k)
			dq_ma.pop_front();
		if(i>=k-1)
			printf("%d ",dq_ma.front().first);
	}
	return 0;
}
