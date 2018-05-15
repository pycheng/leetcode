//#goi #queue 
//for(auto i: words) ac.insert(i.begin(), i.end());
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

string alienorder(vector<string> words){
    set<char> ac;
    set<pair<char,char>> ac_pair;
    map<char, int> deg;
    queue<char> q;
    string res;
   
    //init set<char> ac 
    for(auto i: words) ac.insert(i.begin(), i.end());
    //for(auto i:ac) cout << i << ",";
    //cout << "\n";

    //init set<pair<char,char>> ac_pair for words difference
    for(int i = 0; i<words.size()-1; i++){
        int minsz = min(words[i].size(), words[i+1].size());
        int j = 0;
        for(j=0; j<minsz; j++){
            if(words[i][j]!=words[i+1][j]){
                ac_pair.insert(make_pair(words[i][j], words[i+1][j]));
                break;
            }
        }
        if(j==minsz&&words[i].size() > words[i+1].size()) return "";
    }

    //init map<char, int> deg to record the indegree of ac_pair.second
    for(auto i:ac) deg[i] = 0;
    for(auto i:ac_pair) deg[i.second]++;

    //push the map[i].second==0 root char to the queue
    //put the root char to the q and add to res
    for(auto i:ac){
        if(deg[i]==0){ 
            q.push(i);
            res+=i;
        }
    }
    //cout << res<<"\n";
    while(!q.empty()){
        //q.pop
        char c = q.front(); q.pop();
        for(auto i:ac_pair){
            if(i.first == c){
                //reduce the degree of ac_pair.second
                //push the root char to the q and add to res
                if(--deg[i.second] == 0){
                    q.push(i.second);
                    res+=i.second;
                }
            }
        }
    }
    return res;
}
int main(){
    vector<string> test = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << alienorder(test);
    return 0;
}
