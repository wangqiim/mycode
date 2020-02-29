#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 5001;

struct student{
	int id;
	int grade;
}students[maxn];

bool cmp(student a,student b){//�Ȱ��ɼ������ٰ��������
	if(a.grade!=b.grade)
		return a.grade>b.grade;
	else
		return a.id<b.id; 
}

int main(){
	int n,m;	//nΪ�μ�����,mΪ¼ȡ����
	int pass_grade;	//¼ȡ����ͷ�
	int min_grade;	//1.5*¼ȡ������
	int people;	//ʵ�ʽ����������� 
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&students[i].id,&students[i].grade);
	}
	sort(students,students+n,cmp);
	people = m*1.5-1;	//����ȡ��,ȡ����-1 
	min_grade=students[people].grade;
	for(int i=people+1;i<n;i++){	//���Ƿ����ط� 
		if(students[i].grade != min_grade){
			people = i;
			break;
		}
	}
	printf("%d %d\n",min_grade,people);
	for(int i=0;i<people;i++){
		printf("%d %d\n",students[i].id,students[i].grade);
	}
	return 0;
}
