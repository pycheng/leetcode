#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#if 0 
time complexity: O(n), space complexity O(n)
if(hand.size()%W!=0) return false;
Build a (ordered) map of <card, count>
use map.begin()->first to get the card with smallest value

origin: Solution_queue
time complexity: O(NlogN+N*M) M=N+(N-W)+(N-2W)+...+0=W/N*N
Space complexity: O(2N)
    1. if hand.size()%W !=0 return false
    2. sort the hand 
    3. use ping-pong queue to have the each W cards erased in one queue and store the rest in the other
#endif

class Solution{
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> rbt;

        if(hand.size()%W!=0) return false;
        //build the map
        for(auto i:hand) rbt[i]++;

        while(!rbt.empty()){
            int start = rbt.begin()->first;
            //remove one staright from hand
            int i;
            for(i=0; i<W;){
                if(rbt.empty() || rbt.count(start)<=0) return false;
                if(--rbt[start]==0) rbt.erase(start);
                start++; i++;
            }
            if(i!=W) return false; 
        } 
        return true;
    }
};

class Solution_queue {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
		queue<int> q1, q2;
		queue<int> *cur, *nxt;
		if(hand.size()%W != 0) return false;
		sort(hand.begin(), hand.end());
		for(auto i:hand) q1.push(i);
		cur = &q1; nxt = &q2;

		while(!cur->empty() || !nxt->empty()){
			int first = cur->front();
            int i;
			for(i=0; i<W; ){
				if(cur->empty()) break;

			    if(cur->front() == first){ 
                    i++; first++;
                }else{ 
                    nxt->push(cur->front());
                }
                cur->pop();
			}			
            if(i!=W)return false;
            while(!cur->empty()){
                nxt->push(cur->front());
                cur->pop();
            }
            swap(cur, nxt);
		}
		return true; 
    }
};


int main(){
    vector<int> h1 = {1,2,3,6,2,3,4,7,8}; //3, true
    vector<int> h2 = {1,2,3,4,5};         //4, false 
    vector<int> h3 = {1,5};               //2, false 
    Solution s;
    cout << s.isNStraightHand(h1, 3) << "\n";
    cout << s.isNStraightHand(h2, 4) << "\n";
    cout << s.isNStraightHand(h3, 2) << "\n";

}
