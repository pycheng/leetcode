// #dp
#include <iostream>
using namespace std;

#if 0
You are playing the following Nim Game with your friend: 
There is a heap of stones on the table, each time one 
of you take turns to remove 1 to 3 stones. 
The one who removes the last stone will be the winner. 
You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies 
for the game. Write a function to determine whether you 
can win the game given the number of stones in the heap.
#endif


// think it in dp
// CanWinNim(n) = CanWinNim(n-1)||CanWinNim(n-2)||CanWinNim(n-3)
// base case n = 1,2,3 = true;
// But the question request O(1) execution time or you will pass the time limit
// from the dp code you can found the rule that if(n%4==0) you will loss the game
// thus, (n%4!=0) is the answer


class Solution {
public:
    bool canWinNim_dp(int n) {
        bool canwinn_1 = true;
        bool canwinn_2 = true;
        bool canwinn_3 = true;
        bool canwin;

        if(n<4) return true;
        for(int i = 4; i<=n; i++){
            canwin = !(canwinn_1 && canwinn_2 && canwinn_3);
            canwinn_3 = canwinn_2;
            canwinn_2 = canwinn_1;
            canwinn_1 = canwin;
        }

        return canwin;
    }                    
    bool canWinNim(int n){
        return (n%4!=0);
    }
            
};

int main(){
    Solution s;
    for(int i = 0; i<10; i++){
        cout << s.canWinNim(i) << "," ;
    }
    cout << "\n";
    for(int i = 0; i<10; i++){
        cout << s.tricky_canWinNim(i) << "," ;
    }
}
