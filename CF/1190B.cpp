#include<cstdio>
#include<unordered_map>
using namespace std;

const int maxn = 100005;
unordered_map<int,int> hashmap;
int nums[maxn];

int main(){
	int n;
    scanf("%d",&n);
    bool res = true;	//������0�ظ� 
    int cnt=0;//�������ֵ��ظ�����
    int index;//�ظ������� 
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        ++hashmap[nums[i]];
        if(hashmap[nums[i]]>1&&nums[i]==0)	//����������0 
        	res = false;
        if(hashmap[nums[i]]>1){
        	index = nums[i];
        	cnt++;
		}
	}
	if(n==1){    //ֻ��һ��ʯͷ
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
