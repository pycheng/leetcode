#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

#if 0
n jobs 0..n-1 single processor
executing each job take one unit of time
<i, j> j must finished before executing i
input:
    n <i,j> list of job dependencies
output:
    min req time for finishing job index 0
#endif

// the goal is to find the min path from 0
// build a graph root as 0, BFS the graph
// When the node is the leaf, return the result 

int min_ex_time(vector<vector<int>> job){
    int res = 0;
    queue<int> q;
    unordered_map<int, vector<int>> g; //job, dependence
    //construct the graph g
    for(auto i: job){
        g[i[0]].push_back(i[1]);
    }
    //from g[0] do the dfs
    q.push(0);
    //if g[n] has no neighbor return res;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i:g[cur]){
            q.push(i);
        }
        res++;
    }
    return res;
}

int main(){
    vector<vector<int>> j = {{1,2}, {1,3}, {4,1}, {0,1}, {4,5}};
    cout << min_ex_time(j);    
}
