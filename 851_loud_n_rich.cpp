#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

// richer[i] = [x,y] ==> x has more money than y
// answer[x]=y       ==> y is the most quiestest(smallest quite) amound people richer than x;
// node has different quiteness thus the answer is unique

// topology sort 
// using queue (BFS) cannot show the order of richer
// FIXME time complexity: Quadratic O(n^2) space complexity O(n)
// using state (DFS) and record the quiet value accordingly 
// FIXME sort from child to parents
// FIXME time complexity: O(longest_path) space complexity O(n) --> store res;

class Solution {
public:
    unordered_map<int, vector<int>> richer2;
    vector<int> res;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		//construct a map of parent
        for (auto v : richer) 
            richer2[v[1]].push_back(v[0]);
        res = vector<int> (quiet.size(), -1);
        for (int i = 0; i < quiet.size(); i++) 
            dfs(i, quiet);
        return res;
    }
	//recursion
	// basic case: i is visited ==> res[i] != -1
    int dfs(int i, vector<int>& quiet) {
        if (res[i] >= 0) return res[i]; //FIXME handle the visited node
        res[i] = i;
        for (int j : richer2[i]) 
			if (quiet[res[i]] > quiet[dfs(j, quiet)]) 
				res[i] = res[j];
        return res[i];
    }
#if 0
//BFS
 vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<set<int>> graph(n,set<int>());
        vector<int> res(n,0);
        vector<bool> visited(n,false);
        queue<int> qu;
        
       
        for(int i = 0;i < richer.size(); ++i){
            graph[richer[i][1]].insert(richer[i][0]);
        }
        
        for(int i = 0;i < quiet.size(); ++i){
            res[i] = i;
            qu.push(i);
            visited[i] = true;
            
            while(!qu.empty()){
                int curr = qu.front();
                qu.pop();
                
                for(auto e:graph[curr]){
                    if(visited[e]){
                        if(quiet[res[i]] > quiet[res[e]]){
                            res[i] =res[e];
                        }
                    }else{
                        if(quiet[res[i]] > quiet[e]){
                            res[i] = e;
                        }
                        qu.push(e);
                    }
                }
            }
        }
        
        return res;
    }
#endif
};

#if 0
Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
#endif

int main(){
    Solution s;
    vector<vector<int>> richer = {{1,0}, {2,1}, {3,1}, {3,7}, {4,3},{5,3},{6,3}};
    vector<int> quite = {3,2,5,4,6,1,7,0};
    vector<int> res;

    res = s.loudAndRich(richer, quite);
    
    for(auto i:res) cout << i << ",";
    cout <<"\n";

}

