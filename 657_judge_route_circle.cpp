#include <iostream>
using namespace std;

#if 0
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle. 
#endif

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto c: moves){
            switch(c){
                case 'R': x++; break;
                case 'L': x--; break;
                case 'U': y++; break;
                case 'D': y--; break;
            }
        }
        return (x==0)&&(y==0);
    }
};

int main(){
    Solution s;
    cout << s.judgeCircle("") ,"\n";
    cout << s.judgeCircle("UDRL") ,"\n";
    cout << s.judgeCircle("UU") ,"\n";
}
