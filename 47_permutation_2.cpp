#if 0
watch out the usage of local_pbuf and nums_sz
#endif
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;


void perm(unordered_map<int, int> hash, 
        vector<int> pbuf, int nums_sz, vector<vector<int>> &res)
{
    cout << "hash" << nums_sz << "..\n";
    for(auto i:hash) cout << "(" << i.first << "," << i.second << ")" << ", ";
    cout << "\n";
    for(auto i: pbuf) cout << i << ",";
    cout <<"\n==================\n";
    //base case, insert pbuf to res and return;
    if(nums_sz == 0)
    {
        res.push_back(pbuf);
        return;
    }

    vector<int> local_pbuf(pbuf);
    //for each n in hash, remove from hash and recursion
    for(auto i: hash)
    {
        int item = i.first;
        if(hash[item] > 0){
            hash[item]--;
            local_pbuf = pbuf;
            local_pbuf.push_back(item);
            perm(hash, local_pbuf, nums_sz-1,  res);
            hash[item]++;
        }
    }
}


vector<vector<int>> perm_dup(vector <int> nums){
    vector<vector<int>> res;
    unordered_map<int, int> hash;

    //init hash for <nums, count>
    for(auto i: nums) hash[i]++;
    //call perm_function(hash, p_buf, res)
    perm(hash, {}, nums.size(), res);
    return res;
}


int main(){
    vector<int> t = {1,1,2};
    vector<vector<int>> res;
    res = perm_dup(t);
    for(auto i:res){ 
        for(auto j:i){ 
            cout << j << ",";
        }
        cout << "\n";
    }
    return 0;
}
