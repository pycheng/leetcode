#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <limits.h>
#include <queue>
#include <bitset>
using namespace std;

#if 0
1.   1 <= graph.length <= 12
2.   0 <= graph[i].length < graph.length
#endif

//BFS solution
//class tuple = <bitmask, node, cost>
//set<tuple>  --> this is a unique discribe of a path 
//queue<tuple> --> BFS
//BFS can reach the shortest path with all node visited before longer path


//Dijkstra's Algorithm for all node
//--> no Dijkstra's Algorithm gives the shorted path of a pair

//DFS recursive
//  base: 1. all node visited, return (true, 1, set_visited_node)
//  base: 2. some node not visited, no child not visited (false, 1, set_visited_node)
//  stuck at how to return



class Solution {
public:
    class tuple{
        public:
            unsigned int bitmask;
            int node;
            int cost;
            tuple(unsigned int b, int n, int c):bitmask(b), node(n), cost(c) {}
			tuple(){}
    };
	
	struct tuplehash{
		size_t operator()(const tuple t) const{
			return hash<int>()(t.bitmask+t.node+t.cost);
		}
	};
	struct tuplecompare{
		bool operator()(const tuple t1, const tuple t2) const{
			if((t1.bitmask == t2.bitmask)&&
				(t1.node == t2.node)&&(t1.cost == t2.cost)){
				return true;
			}else{	
				return false;
			}
		}
	};

    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_set<tuple, tuplehash, tuplecompare> h;
        queue<tuple> q;

		int min_dist = INT_MAX;
		for(int s=0; s<graph.size(); s++){
            tuple t(1<<s, s, 1);
            q.push(t);
            h.insert(t);
        }
        while(!q.empty()){
            tuple t;
			t = q.front();
            q.pop();
			//cout << bitset<12>(t.bitmask) << "," << t.cost << "," << q.size() << "\n";
            if(t.bitmask == (1<<graph.size())-1){
                return t.cost-1;
            }

            for(auto i: graph[t.node]){
                tuple t_child(t.bitmask|(1<<i), i, t.cost+1);
                if(h.count(t_child) <= 0){
                    h.insert(t_child);
                    q.push(t_child);
                }
            }
        }
		return -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> t1 = {{1,2,3}, {0}, {0}, {0}}; // 4
    vector<vector<int>> t2 = {{1}, {0,2,4}, {1,3,4}, {2}, {1,2}}; //4
    cout << s.shortestPathLength(t1) << "\n";
    cout << s.shortestPathLength(t2) << "\n";
}


