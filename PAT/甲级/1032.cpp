#include<iostream>
#include<cstdio>
using namespace std;

int node[100010];

int main(){
	int word1,word2,n;
    cin>>word1>>word2>>n;
	int index;
	char letter;
	int next;
	for(int i=0;i<n;i++){
		cin>>index>>letter>>next;
		node[index] = next;
	}
	int num1=1,num2=1;
	for(int i = word1;i!=-1;i = node[i]) num1++;
	for(int i = word2;i!=-1;i = node[i]) num2++;
	while(num1>num2){
		word1 = node[word1];
		num1--;
	}
	while(num1<num2){
		word2 = node[word2];
		num2--;
	}
	while(word1!=word2){
		word1 = node[word1];
		word2 = node[word2];
	}
    if(word1 == -1)
        printf("-1");
    else
	    printf("%05d\n",word1);
	return 0;
}
