#include<cstdio>
using namespace std;

const int maxn = 100005;
long long nums[maxn];

int main(){
	int t,n,k;
	for(int i=1;i<maxn;i++){
		nums[i] = nums[i-1]+i;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		int left = 0,right = n;
		int mid;
		while(left<right){	//找到最后一个小于k的 
			mid = (left+right+1)/2;
			if(nums[mid]>=k)
				right = mid-1;
			else
				left = mid;
		}
		int pos_b = k-nums[left];
		for(int i=n-1;i>left+1;i--)
			putchar('a');
		putchar('b');
		for(int i=left;i>=pos_b;i--)
			putchar('a');
		putchar('b');
		for(int i=pos_b-2;i>=0;i--)
			putchar('a');
		putchar('\n');
	}
	return 0;
}
