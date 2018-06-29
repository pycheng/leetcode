#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int s=0, e=0;
        int mlen = 0;
        int midx = 0;

        while(s<A.size()){
            int cidx = -1;
            if(A[s]<A[s+1] && (e+1)<A.size()){
                e=s;
                while(A[e]<A[e+1] && (e+1)<A.size()) e++;
                if(A[e]>A[e+1] && (e+1)<A.size()){
                    cidx = e;
                    while(A[e]>A[e+1] && (e+1)<A.size()) e++;
                    if(e-s+1 > mlen){
                        mlen = e-s+1;
                        midx = cidx;
                    }
                }
            }
            s=max(s,e)+1;
        }
        return midx;
    }

    int peakIndexInMountainArray_for(vector<int>& A) {
		int max_len = 0;
		int max_idx = -1;
		int cur_len = 0;
		int cur_max_idx = -1;
		int down_hill_phase = false;
 		for(int i = 0; i < A.size(); i++){
			if(A[i]<A[i+1]){
				if(down_hill_phase){
					//conclude previous moutain
					if(cur_len > max_len){
						max_len = cur_len;
						max_idx = cur_max_idx;
					}
					cur_max_idx = -1;
					cur_len=0;
					down_hill_phase = false;
				}else{
					cur_len++;
				}		
			}else if(A[i] > A[i+1] && cur_len>0){
                if(down_hill_phase == false){
                    down_hill_phase = true;
                    cur_max_idx = i;
                }
                cur_len++;
			}else if(A[i] == A[i+1]&&cur_len>0){
				if(down_hill_phase){
					//conclude previous moutain
					if(cur_len > max_len){
						max_len = cur_len;
						max_idx = cur_max_idx;
					}
				}
				cur_max_idx = -1;
				cur_len=0;
				down_hill_phase = false;
			}
		}       
		//handle EOF

	    if(down_hill_phase){
	    	//conclude previous moutain
	    	if(cur_len > max_len){
	    		max_len = cur_len;
	    		max_idx = cur_max_idx;
	    	}
	    }
        return max_idx;
    }
};

int main(){
    Solution s;
    vector<int> A = {0,2,1,0};
    cout << s.peakIndexInMountainArray(A);
}
