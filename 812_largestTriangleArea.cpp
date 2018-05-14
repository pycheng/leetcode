//#graphic
//fabs in math.h
//A = 0.5*(x1(y2-y3)+x2(y3-y1)+x3(y1-y2));
//Example:Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
//Output: 2
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:    
        double largestTriangleArea(vector<vector<int>>& points) {             
            double rslt = 0;
                for(auto i : points)
                for(auto j : points)
                for(auto k : points)
                    rslt = max(rslt, 0.5*fabs(
                                i[0]*(j[1]-k[1])+
                                j[0]*(k[1]-i[1])+
                                k[0]*(i[1]-j[1])));
            return rslt;
        }
};      
int main(){
    vector<vector<int>> test = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    Solution s;
    double rslt;

    rslt =  s.largestTriangleArea(test);
    cout << to_string(rslt);

    return 0;
}
