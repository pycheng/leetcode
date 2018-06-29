#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
		unsigned int v = x^y;
		int res = 0;
		while(v!=0){ 
			res++;
			v = v&(v-1);
		}
		return res;
    }
};


int main(){
	Solution s;
	cout << s.hammingDistance(1,4);
}
