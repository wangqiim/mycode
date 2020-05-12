#include<iostream>
#include<string>
#include<map>
using namespace std;

#define PIIC pair<int,pair<int,char> >
#define MPIIC(x,y,z) make_pair((x),make_pair((y),(z)))

map<PIIC,int> vis;

int main(){
	int t;
	cin >> t;
	string path;
	pair<int,int> loc;
	while(t--){
		loc = make_pair(0, 0);
		vis.clear();
		int ans = 0;
		cin >> path;
		int n = path.size();
		for(int i = 0; i < n; i++){
			if(path[i] == 'N'){
				if(vis[MPIIC(loc.first, loc.second, 'N')] == 0 && vis[MPIIC(loc.first, loc.second - 1, 'S')] == 0)
					ans += 5;
				else
					ans++;
				vis[MPIIC(loc.first, loc.second, 'N')] = 1;
				loc.second--;
			}else if(path[i] == 'S'){
				if(vis[MPIIC(loc.first, loc.second, 'S')] == 0 && vis[MPIIC(loc.first, loc.second + 1, 'N')] == 0)
					ans += 5;
				else
					ans++;
				vis[MPIIC(loc.first, loc.second, 'S')] = 1;
				loc.second++;
			}else if(path[i] == 'W'){
				if(vis[MPIIC(loc.first, loc.second, 'W')] == 0 && vis[MPIIC(loc.first - 1, loc.second, 'E')] == 0)
					ans += 5;
				else
					ans++;
				vis[MPIIC(loc.first, loc.second, 'W')] = 1;
				loc.first--;
			}else{
				if(vis[MPIIC(loc.first, loc.second, 'E')] == 0 && vis[MPIIC(loc.first + 1, loc.second, 'W')] == 0)
					ans += 5;
				else
					ans++;
				vis[MPIIC(loc.first, loc.second, 'E')] = 1;
				loc.first++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
