#include<cstdio>
#include<cmath>

const int maxn = 100001;
int price[maxn];	//�۸� 
int num[maxn];	//����

int main(){
	int pre,k=-1; //Ԥ�ڼ۸����Ӧ������ 
	int x,y;	//ÿһ�е����
	int m=0;	//���� 
	int input_d;	//����ı仯�� 
	int d;//�����м��ȱ����ʱ�ı仯��
	float umax=1e9,umin=-1e9;
	scanf("%d",&pre);
	int i=0;
	scanf("%d %d",&x,&y);
	price[m] = x;num[m] = y;	//�ɱ�,����
	while(1){
		scanf("%d %d",&x,&y);
		if(x==-1&y==-1) break;
		if(x-price[m] == 1){
			m++;
			price[m] = x;
			num[m] = y;
		}
		else{	//��Ҫ�����ȱ���� 
			d = (y-num[m])/(x-price[m]);//ÿ����һԪ���ٵ�����
			while(x>price[m]){
				m++;
				price[m] = price[m-1]+1;
				num[m] = num[m-1] + d;
			}
		}
	}
	scanf("%d",&input_d);
	x = price[m];y = num[m];
	while(y>input_d){//����������0
		m++;
		x+=1;y-=input_d;
		price[m] = x;
		num[m] = y; 
	}
	for(int i=0;i<=m;i++){
		if(price[i]==pre){
			k = i;
			break;
		}
	}
	if(k==-1){
		printf("NO SOLUTION");
		return 0;
	}
	for(int i=0;i<k;i++){
		if((float)((num[k]*(price[k]-price[0])-num[i]*(price[i]-price[0]))/(float)(num[i]-num[k]))<umax)	
		//(Ԥ������-i����)/Ԥ������=��λ��Ʒ��Ҫ������ֵ<umax 
			umax = (float)((num[k]*(price[k]-price[0])-num[i]*(price[i]-price[0]))/(float)(num[i]-num[k]));
	}
	for(int i=k+1;i<=m;i++){
		if((float)((num[i]*(price[i]-price[0])-num[k]*(price[k]-price[0]))/(float)(num[k]-num[i]))>umin)
		//(Ԥ������-i����)/Ԥ������=��λ��Ʒ��Ҫ������ֵ>umin
			umin =  (float)((num[i]*(price[i]-price[0])-num[k]*(price[k]-price[0]))/(float)(num[k]-num[i]));
	}
	
	if(umin>umax) printf("NO SOLUTION");
	else if(umin>0){
		if(fabs(umin-(int)(umin))>1e-6)
			printf("%d",(int)umin+1);
		else
			printf("%d",(int)umin);
	}else if(umax<0){
		if(fabs((int)umax-umax)>1e-6)
			printf("%d",(int)umax-1);
		else
			printf("%d",(int)umax);
	}else{
		printf("0");
	}
	return 0;
}
