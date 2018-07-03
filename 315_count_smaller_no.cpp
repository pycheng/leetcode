#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

//time complexity
//insert  O(logn)
//retrive O(logn)
class fenwick_tree{
private:
    vector<int> data;
    int lowbit(int x) { return x&(-x); }
public:

    fenwick_tree(int sz): data(sz+1, 0){
    }
    
    void insert(int v, int delta){
		v+=1;
        while(v < data.size()){
            data[v] += delta; 
            v += lowbit(v);
        }
    }

    int query(int v){
		v+=1;
        int sum = 0;
        while(v>0){
            sum += data[v];
            v -= lowbit(v);
        }
        return sum;
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
		set<int> no(nums.begin(), nums.end());
       	fenwick_tree fwt(no.size());
		unordered_map<int, int> ranks;
        int rank=0;
		for(auto i:no){
            ranks[i] = rank++;
		}
        for(int i=nums.size()-1; i>=0; i--){
            res.push_back(fwt.query(ranks[nums[i]]-1));
            fwt.insert(ranks[nums[i]], 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(){
    vector<int> t = {5,2,6,1};
    Solution s;
    vector<int> r;
    r = s.countSmaller(t);
    for(auto i:r) cout << i << ",";

}
