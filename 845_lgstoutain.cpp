#include <iostream>
#include <vector>
using namespace std;

#if 0
Time complexity O(N), Space complexity O(1)
By definition of moutain, one moutain can only start when the previous end.
    1. rising steps follow by falling steps
    2. length > 3, yes or cannot satisfy 1.
Using s and e to identify the start and end index
compare the e-s+1 with the max_length

Solution_haha is designed based on a complicated FSM.
Time complexity O(N), Space complexity O(1)
#endif

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int s=0, e=0;
        int max_len=0;

        //search through every item
        while(s<A.size()){
            
            //go through rising steps;
            if(((s+1)<A.size()) && A[s]<A[s+1]){
                e = s;
                while(((e+1)<A.size()) && A[e]<A[e+1]) e++;
                //go through failing steps;
                if(((e+1)<A.size()) && A[e]>A[e+1]){
                    //moutain must be made by rising following falling
                    while(((e+1)<A.size()) && A[e]>A[e+1]) e++;
                    //update max_len
                    max_len = max(max_len, e-s+1);
                }
            }

            //update s to find next moutain, moutain will not overlap
            s = max(s+1, e);
        }

        return max_len;
    }
};

class Solution_haha {
public:
	int findnxt_rising(vector<int> A, int v){
		int i;
		for(i=v+1; i<A.size(); i++){
			if(A[i-1] < A[i]){
				break;
			}
		}
		return i;
	}
    int longestMountain_haha(vector<int>& A) {
        bool rising = false;
        int  r_step = 0;
        int  f_step = 0;
        int  max_step = 0;
        int  i;

		//locate idx of 1st rising edge
		i=findnxt_rising(A,0);
		if(i==A.size()||A.size()<3) return 0;
		r_step=0;
		rising = true;

			cout << "sssA(" << i << ")= " << A[i];
			cout << ", rising " << rising ;
			cout << ", r_step "   << r_step ;
			cout << ", f_step "   << f_step ;
			cout << ", max_step " << max_step << "\n";
		//search the peak;
        for(; i<A.size(); i++){
            if(rising){
                if(A[i-1] < A[i]){
                    r_step++;
                }else if(A[i-1] > A[i]){
					f_step++;
                    rising = false;
                }else{
                    max_step = max(max_step, (r_step+1+f_step));
					r_step=0; f_step=0;
					i = findnxt_rising(A,i)-1;
                    rising = true;
                }
            }else{ //failing or init
                if(A[i-1] < A[i]){
                    max_step = max(max_step, (r_step+1+f_step));
                    r_step=1; f_step=0;
                    rising = true;
                }else if(A[i-1] > A[i]){
					f_step++;
                }else{
                    max_step = max(max_step, (r_step+1+f_step));
					r_step=0; f_step=0;
					i = findnxt_rising(A,i)-1;
                    rising = true;
                }
            }
			cout << "A(" << i << ")= " << A[i];
			cout << ", rising " << rising ;
			cout << ", r_step "   << r_step ;
			cout << ", f_step "   << f_step ;
			cout << ", max_step " << max_step << "\n";

        }
        if(f_step>0&&r_step>0){
    		max_step = max(max_step, f_step+r_step+1);
        }
        return (max_step>2)?max_step:0;
    }
};


int main(){
	Solution s;
	vector<int> in  = {0,1,2,3,4,2,1,0};     //8
	vector<int> in1 = {2,1,4,7,3,2,5};       //5
	vector<int> in2 = {0,1,2,3,4,5,6,7,8,9}; //0
	vector<int> in3 = {9,8,7,6,5,4,3,2,1,0}; //0
	vector<int> in4 = {7,4,8};               //0
	vector<int> in5 = {2,1,4,7,3,2,2,5};     //5 
	cout <<s.longestMountain(in)<<"\n";
	cout <<s.longestMountain(in1)<<"\n";
	cout <<s.longestMountain(in2)<<"\n";
	cout <<s.longestMountain(in3)<<"\n";
	cout <<s.longestMountain(in4)<<"\n";
	cout <<s.longestMountain(in5)<<"\n";
}
