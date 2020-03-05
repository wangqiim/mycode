#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 10001;
pair<int,int> nums[maxn];	//first ����,second����

struct bign{	//��123ʱ: d={3,2,1}llen =3; 
	int d[maxn];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;}
}res,sum,ans;	//res���ս��,sum�۳˽��,ans�Ƚϱ���

bign multi(bign a,int b){	//�߾��ȴ�������;��ȵĳ˷�
	bign c;
	int carry = 0; //��λ
	for(int i=0;i<a.len;i++){
		int temp = a.d[i]*b + carry;
		//printf("%d*%d+%d\n",a.d[i],b,carry);
		c.d[c.len++] = temp%10;
		carry = temp / 10;
	} 
	while(carry!=0){
		c.d[c.len++] = carry%10;
		carry/=10;
	}
	return c;
}

bign divide(bign a,int b,int& r){	//�߾��ȳ��Ե;���,rΪ���� 
	bign c;
	c.len = a.len;
	r=0;
	for(int i=a.len-1;i>=0;i--){
		r = r*10 + a.d[i];
		if(r<b) c.d[i] = 0;
		else{
			c.d[i] = r/b;
			r %= b;
		}
	}
	while(c.len-1>=1&&c.d[c.len-1]==0){
		c.len--;
	}
	return c;
}

int compare(bign a,bign b){	//�Ƚ�a��b�Ĵ�С,a>b����1,��ȷ���0,a<b����-1 
	if(a.len>b.len) return 1;
	if(a.len<b.len) return -1;
	for(int i=a.len-1;i>=0;i--){
		if(a.d[i]>b.d[i]) return 1;
		if(a.d[i]<b.d[i]) return -1;
	}
	return 0;
}

void print(bign a){	//��������� 
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
	return;
}

int cmp(pair<int,int> a,pair<int,int> b){
	return a.first*a.second<b.first*b.second;
}

int main(){
	int n;
	scanf("%d",&n);
	scanf("%d %d",&nums[0].first,&nums[0].second);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&nums[i].first,&nums[i].second);
	sort(nums+1,nums+1+n,cmp);
	sum.d[0] = 1; sum.len = 1;
	for(int i=1;i<=n;i++){
		int r = 0;	//������ 
		sum = multi(sum,nums[i-1].first);
		ans = divide(sum,nums[i].second,r);
		if(compare(ans,res)==1)
			res = ans;
	}
	print(res);
	return 0;
}
