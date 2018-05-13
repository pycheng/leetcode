#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
            vector<int> deg(n,0);
            unordered_map<int, set<int>> hash;
            vector<int> leaves, rslt;

            for(auto i:edges){
                //init degree vector
                deg[i.first]++;
                deg[i.second]++;
                //init hash for edges
                hash[i.first].insert(i.second);
                hash[i.second].insert(i.first);
            }
            while(n>2){
                //store degree 1 in leaves 
                leaves.clear();
                for(int i=0 ; i<deg.size(); i++){
                    if(deg[i] == 1){
                        leaves.push_back(i);
                    }
                }
                //reduce the deg of nbr of leaves
                for(auto i:leaves){
                    deg[i]=-1; n--;
                    for(auto j:hash[i]){
                        deg[j]--;
                    }
                }
            }
            //return item in degree with positive degree
            for(int i=0; i<deg.size(); i++){
                if(deg[i] >= 0) rslt.push_back(i);
            }
            return rslt;
        }
};
class Solution1 {
    public:
        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
                vector<int> rslt;
                map<int, int> deg;        
                queue<int> q;
                int item;
                int dg_sz = 0;
                
                deg.clear();
                rslt.clear();
                if(n==1){
                    rslt.push_back(0);
                    return rslt;
                }
                // init degree 
                // mistake 2 loop twice of the deg map is stupid too
                // should skip map.count(key)>0 case
                for(auto i:edges){
                    deg.insert(make_pair(i.first, 0));
                    deg.insert(make_pair(i.second, 0));
                }
                for(auto i:edges){
                    deg[i.first] ++;
                    deg[i.second] ++;
                }

                //push leaves with degree as 1 to q
                for(auto i:deg){
                    if(i.second == 1){
                        q.push(i.first);
                    }
                }
                dg_sz = deg.size(); 
                // mistake 1 to q.empty is too stupid
                // base case number of node should larger than 2
                // store the node in the vector<int>
                while(!q.empty()){
                   rslt.clear();
                   while(!q.empty()){
                       item=q.front(); q.pop(); 
                       //reduce neighbor deg by 1
                       //mistake 3 build a hash...please....
                       for(auto i:edges){
                            if(i.first == item && deg.count(i.second) > 0){
                                deg[i.second]--;
                            }else if(i.second == item && deg.count(i.first) > 0){
                                deg[i.first]--;
                            }
                        }
                       //record the leaves in rslt
                       rslt.push_back(item);
                       //remove leaves from deg map
                       deg.erase(item);
                   }

                   if(deg.size() == 1){
                       rslt.clear();
                       rslt.push_back(deg.begin()->first);
                       return rslt;
                   }
                   //push leaves with degree as 1 to q
                    for(auto i:deg){
                        if(i.second == 1){
                            q.push(i.first);
                        }
                    }
                }
                
                return rslt;
        }
};


int main(){
    Solution sol;
    vector<int> rslt;
    vector<pair<int,int>> e = {{1,0},{1,2},{1,3}};  //4
    vector<pair<int,int>> e1 = {{0,3},{1,3},{2,3},{4,3},{5,4}};  //6
    vector<pair<int,int>> e2 = {{0,1}};  //2
    vector<pair<int,int>> e3 = {{0,1},{0,2},{0,3},{3,4},{4,5}};  //6
    rslt =  sol.findMinHeightTrees(6,e3);

    for(auto i:rslt) cout<<i<<",";
    cout << "\n";
    return 0;
}
