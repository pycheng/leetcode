//#DP 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cussort(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
class Solution {
    public:
    int findLongestChain(vector< vector<int> >& pairs) {
        int cnt = 0;
        int target = 0;

        //sort the by pairs[1]
        sort(pairs.begin(), pairs.end(), cussort);
        target = pairs[0][1]; 

        for(int i=0; i<pairs.size(); i++){
            //find the pairs[i][0] > pairs[prev][1]
            if(pairs[i][0] > target){
                cnt++;
                //update pairs[prev]
                target = pairs[i][1];
            }
        }
        return cnt;

    }
};


int main(){
    Solution sol;
    int rslt = 0;
    vector< vector<int> > test {{1,2},{2,3},{3,4}};
    rslt = sol.findLongestChain(test);
    cout << rslt;
    return 0;
}
