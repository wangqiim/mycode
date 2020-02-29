#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 5001;

struct student{
	int id;
	int grade;
}students[maxn];

bool cmp(student a,student b){//先按成绩排序，再按序号排序
	if(a.grade!=b.grade)
		return a.grade>b.grade;
	else
		return a.id<b.id; 
}

int main(){
	int n,m;	//n为参加人数,m为录取人数
	int pass_grade;	//录取的最低分
	int min_grade;	//1.5*录取分数线
	int people;	//实际进入面试人数 
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&students[i].id,&students[i].grade);
	}
	sort(students,students+n,cmp);
	people = m*1.5-1;	//向下取整,取索引-1 
	min_grade=students[people].grade;
	for(int i=people+1;i<n;i++){	//看是否有重分 
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
