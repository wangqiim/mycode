#include<cstdio>
#include<cstring>

char nums[100];
int len;
int n1_s,n2_s;	//数字的开头位置 
int ch1_s = 0,ch2_s;	//行列号的开头位 

void excel_2_rxcy(){
	putchar('R');
	for(int i=n1_s;i<len;i++)
		putchar(nums[i]);
	putchar('C');
	int res = 0;
	for(int i=0;i<n1_s;i++){
		res*=26;
		res+=nums[i]-'A'+1;
	}
	printf("%d",res);
	putchar('\n');
	return;
}

void rxcy_2_excel(){
	int res = 0;
	for(int i=n2_s;i<len;i++){
		res *= 10;
		res += nums[i]-'0';
	}
	char s[10];
	int n = 0;
	while(res){
		int mod = res%26;
		if(mod == 0){
			s[n++] = 'Z';
			res = res/26-1;
		}
		else{
			s[n++] = 'A'+mod-1;
			res = res/26;
		}
	}
	for(int i = n-1;i>=0;i--)
		putchar(s[i]);
	for(int i = 1;i<ch2_s;i++)
		putchar(nums[i]);
	putchar('\n');
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(nums);
		len = strlen(nums);
		int flag = 0;	//出现了几组数 
		for(int i=0;i<len;i++){
			if('0'<=nums[i]&&nums[i]<='9'&&nums[i-1]>'9'){
				flag++;
				if(flag==1)
					n1_s = i;
				else
					n2_s = i;
			}else if('A'<=nums[i]&&nums[i]<='Z'&&nums[i-1]<='9')
				ch2_s = i;
		}
		if(flag == 2)
			rxcy_2_excel();
		else
			excel_2_rxcy();
	}
	return 0;
}
