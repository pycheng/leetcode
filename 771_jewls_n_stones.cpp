#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel;
        for(auto i: J){
            jewel.insert(i);
        }

        int num_jewel = 0;
        for(auto i: S){
            if(jewel.count(i) > 0){
                num_jewel++;
            }
        }
        return num_jewel;
    }
};

int main(){
    Solution s;
    cout << s.numJewelsInStones("aA", "aaAbbbhb");
}
