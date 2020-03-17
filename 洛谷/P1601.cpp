#include<cstdio>
#include<cstring>

const int maxn = 502;

struct bign{
	int d[maxn];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};

bign add(bign a,bign b){
	bign c;
	int carry = 0;
	for(int i=0;i<a.len||i<b.len;i++){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp%10;
		carry = temp / 10;
	}
	if(carry) c.d[c.len++] = carry;
	return c;
}

bign change(char str[]){
	bign a;
	a.len = strlen(str);
	for(int i = 0;i<a.len;i++){
		a.d[i] = str[a.len-1-i] - '0';
	}
	return a;
}

void print(bign a){
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
	return;
}

int main(){
	char s1[maxn],s2[maxn];
	scanf("%s %s",s1,s2);
	print(add(change(s1),change(s2)));
	return 0;
}
