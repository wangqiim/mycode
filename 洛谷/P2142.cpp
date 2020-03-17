#include<cstdio>
#include<cstring>

const int maxn = 10088;
struct bign{
	int d[maxn];
	int len;
	int zf;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
		zf = 1;	//1��ʾ����,-1��ʾ���� 
	}
};

int compare(bign a,bign b){	//�Ƚ�a��b�Ĵ�С,a>b����1,��ȷ���0,a<b����-1 
	if(a.len>b.len) return 1;
	if(a.len<b.len) return -1;
	for(int i=a.len-1;i>=0;i--){
		if(a.d[i]>b.d[i]) return 1;
		if(a.d[i]<b.d[i]) return -1;
	}
	return 0;
}

bign add(bign a,bign b){	//������֮����мӷ� 
	bign c;
	int carry = 0;	//��λ
	for(int i=0;i<a.len||i<b.len;i++){
		int temp = a.d[i]+b.d[i] + carry;
		c.d[c.len++] = temp%10;
		carry = temp/10;
	} 
	if(carry!=0) c.d[c.len++] = carry;
	return c;
}

bign sub(bign a,bign b){	//������֮����м��� 
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){
		if(a.d[i]<b.d[i]){	//��λ������,��Ҫ��λ
			a.d[i+1]--; 
			a.d[i]+=10;
		}
		c.d[c.len++] = a.d[i]-b.d[i];
	}
	while(c.len-1>=1&&c.d[c.len-1]==0)
		c.len--;	//ȥ����λ0
	return c;
}

bign change(char str[]){
	bign a;
	int n=strlen(str);
	if(str[0]=='-'){
		a.zf = -1;
		a.len = n - 1;
	}else
		a.len = n;
	for(int i = 0;i<a.len;i++){
		a.d[i] = str[n-1-i] - '0';
	}
	return a;
}

void print(bign a){
	if(a.zf == -1) printf("-");
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
	return;
}

int main(){
	char s1[maxn],s2[maxn];
	scanf("%s %s",s1,s2);
	bign a = change(s1), b = change(s2);
	bign c;
	if(a.zf==1&&b.zf==-1)
		c = add(a,b);
	else if(a.zf==-1&&b.zf==1){
		c = add(a,b);
		c.zf = -1;
	}else if(a.zf==1&&b.zf==1){
		if(compare(a,b)>=0)
			c = sub(a,b);
		else{
			c = sub(b,a);
			c.zf = -1;
		}
	}else{
		if(compare(a,b)>0){
			c = sub(a,b);
			c.zf = -1;
		}
		else
			c = sub(b,a);
	}
	print(c);
	return 0;
}
