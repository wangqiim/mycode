#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct rgs{
	char registration_number[15];
	int grade;
	//int final_rank;
	int location_number;
	int local_rank;
}stu[30010];

bool cmp(rgs a,rgs b){
	if(a.grade != b.grade)
		return a.grade>b.grade;
	else 
		return strcmp(a.registration_number,b.registration_number)<0;
}

int main(){
	int n; //考点数量
	int k; //某点的考生数量
	int num; //总考生数 
	scanf("%d",&n);	//读n
	int ranking;//排名 
	for(int i = 1 ; i<=n;i++){
		scanf("%d",&k);	//读k 
		for(int j = 0;j<k;j++){
			scanf("%s %d",&stu[num].registration_number,&stu[num].grade); //读该区域考生号和成绩 
			stu[num].location_number = i;
			num++;
		}
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].local_rank = 1;
		for(int j = num-k+1;j<num;j++){
			if(stu[j].grade==stu[j-1].grade)
				stu[j].local_rank = stu[j-1].local_rank;//排名，考虑并列
			else
				stu[j].local_rank = j - (num - k) + 1;
		}
	}
	sort(stu,stu+num,cmp);
	ranking=1;
	printf("%d\n",num);
	for(int i = 0 ;i<num;i++){
		if(i > 0 && stu[i].grade!=stu[i-1].grade)
			ranking = i+1;//无并列时更新 
		printf("%s %d %d %d\n",stu[i].registration_number,ranking,stu[i].location_number,stu[i].local_rank);
	} 
	return 0;
}
