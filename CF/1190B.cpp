#include<cstdio>
#include<unordered_map>
using namespace std;

const int maxn = 100005;
unordered_map<int,int> hashmap;
int nums[maxn];

int main(){
	int n;
    scanf("%d",&n);
    bool res = true;	//输入无0重复 
    int cnt=0;//输入数字的重复个数
    int index;//重复的数字 
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        ++hashmap[nums[i]];
        if(hashmap[nums[i]]>1&&nums[i]==0)	//有两个以上0 
        	res = false;
        if(hashmap[nums[i]]>1){
        	index = nums[i];
        	cnt++;
		}
	}
	if(n==1){    //只有一个石头
        if(nums[0]%2 == 0)
            printf("cslnb\n");
        else
            printf("sjfnb\n");
        return 0; 
	}
	if(res==false||(cnt>1)){
		printf("cslnb\n");
		return 0;
	}
	if(cnt==1&&hashmap[index-1]!=0){
		printf("cslnb\n");
		return 0;
	}
	long long sum = -(n-1)*n/2;
	for(int i=0;i<n;i++)
		sum -= nums[i];
	if(sum%2==0)
		printf("cslnb\n");
    else 
    	printf("sjfnb\n");
    return 0;
}
