//#dp
#include <vector>
#include <iostream>
using namespace std;

vector<int> countbits(int num)
{
    vector<int> nbits(num+1,0);
    nbits[0] = 0;
    for(int i=1; i<=num; i++){
        // countbits(i) = countbit(i>>1) + (i%2);
        nbits[i] = nbits[i>>1]+(i%2);
    }
    return nbits;
}
#if 0
class Solution {
    public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i = 1;i <= num;i++) 
            res[i] = i&1?res[i-1]+1:res[i>>1];
        return res;
    }
};
#endif

int main(){
    vector<int> res;
    res = countbits(5);

    string sep="";
    for(auto i: res){
        cout << sep << i;
        sep = ", ";
    }
    return 0;
}
