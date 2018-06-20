#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <float.h>
#include <limits.h>
using namespace std;

bool mysort(vector<double> c1, vector<double> c2){
    return c1[0] > c2[0];
}
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<double>> car;

        for(int i = 0; i<speed.size(); i++){
            car.push_back({(double)position[i], (double)(target-position[i])/speed[i]});
        }
        sort(car.begin(), car.end(), mysort);
        for(auto c:car) cout << c[0] <<":" << c[1] <<", ";

        double cur = car[0][1];
        int num_fleet = 1;
        for(auto c:car){
            if(c[1] > cur){
                cur = c[1];
                num_fleet++;
            }
        }
        return num_fleet;
    }
};

int main(){
    Solution s;
    //vector<int> i1 = {10,8,0,5,3};
    //vector<int> i2 = {2,4,1,1,3};
    //vector<int> i1 = {8,6};
    //vector<int> i2 = {2,3};
    vector<int> i1 = {3};
    vector<int> i2 = {3};
    cout << s.carFleet(10, i1, i2)<<"\n";
}

