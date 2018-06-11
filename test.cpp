#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <math.h>
using namespace std;
vector<int> res;
int dfs(int v, vector<int> quiet, unordered_map<int, vector<int>> g)
{
	if(res[v]>=0) return res[v]; //visited	

	res[v]=v;
	for(auto i: g[v]){
		int ret = dfs(i, quiet, g); 
		res[v] = (quiet[res[v]]>quiet[ret])?res[ret]:res[v];
	}
	return res[v];
}

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    res=vector<int>(quiet.size(), -1);
	unordered_map<int, vector<int>> g;
	for(auto i: richer)
		g[i[1]].push_back(i[0]);
//	for(int i=0; i<quiet.size(); i++)
//		dfs(i, quiet, g);
    for(auto i:g)
        dfs(i.first, quiet, g);
    return res;
}

int main(){
    vector<vector<int>> richer = {{1,0}, {2,1}, {3,1}, {3,7}, {4,3},{5,3},{6,3}};
    vector<int> quiet = {3,2,5,4,6,1,7,0};
    vector<int> res1;

    res1 = loudAndRich(richer, quiet);
    
    for(auto i:res1) cout << i << ",";
    cout <<"\n";
}
