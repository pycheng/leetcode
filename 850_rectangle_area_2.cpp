#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<math.h>
#include<algorithm>
using namespace std;

// <x1,y1,x2,y2> --> represent the rectangle
//
// the idea is iterate throught y direction and accumulating the area in y'-y
// FIXME <requirement> sorting in y direction
// FIXME change the presentation to start and end 
//              <y1,x1,x2,1>  --> start
//              <y2,x1,x2,-1> --> end
//
// accumulating area can be obtained by (y'-y)*(sum_x)
// FIXME <requirement> construct and accumulating map for X
//  x x xThe naive way is to create an array from (0..x)
//       The better way is create an array acc_xidx[0..n] store the apperance count
//       which represents the overlap count of xidx
// FIXME <requirement> to identify the index of acc_xidx, a map_xval2xidx(hash) is requested
//       ex. for <x1, y1, x2, y2> need to accumulate acc_xidx[map_xval2xidx[x1]]..acc_xidx[map_xval2xidx[x2]]
//
// dig into the acc_xidx and map_xval2xidx, a sorted unique vector xval is needed
// FIXME <requirement> unique
//       vector<int>::iterator uniq_end_idx = unique(xval.begin(), xval.end());
//       xval.erase(uniq_end_idx, xval.end());
//
// Time complexity: O(2n*m), n=rectangles.size(), m=no_x
//      compute ares O(2*rectangles.size()*no_x) + sort O(no_x+2*no_y)
// Space complexity: O(2n)
//      rec_sorted_y O(rectangles.size()*2), map_xval2xidx O(2*no_xval) + acc_xidx/xval O(2*no_xval)  
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        //create the xval
        vector<int> xval;
        for(auto i:rectangles){
            xval.push_back(i[0]);
            xval.push_back(i[2]);
        }
        sort(xval.begin(), xval.end());
        vector<int>::iterator uniq_end_idx = unique(xval.begin(), xval.end());
        xval.erase(uniq_end_idx, xval.end());

        //create the map_xval2xidx 
        unordered_map<int, int> map_xval2xidx;
        for(int i=0; i<xval.size(); i++){
            map_xval2xidx[xval[i]] = i;
        }
#ifdef DEBUG
        cout << "x  ";
        for(auto i:xval) cout << i << ",";
        cout << "\nx_i  ";
        for(auto i:map_xval2xidx) cout << "(" << i.first << "," << i.second << "), ";
#endif
        //create the acc_xidx
        vector<int> acc_xidx(xval.size(), 0);

        //create the rec_sorted_y
        vector<vector<int>> rec_sorted_y;
        for(auto i:rectangles){
            int x1 = i[0], y1 = i[1], x2 = i[2], y2 = i[3];
            rec_sorted_y.push_back({y1,x1,x2,1});     //i[3] is used to identify if it's entering 
            rec_sorted_y.push_back({y2,x1,x2,-1});    //the area of y1..y2 or leaving it , refer to sig
        }
        //FIXME sorted by the 1st entry
        sort(rec_sorted_y.begin(), rec_sorted_y.end());
        
        long long area = 0, sum_x = 0, cur_y = 0;
        int mod = pow(10,9)+7;
        for(auto i:rec_sorted_y){
            long long y = i[0], x1 = i[1], x2 = i[2], sig=i[3];
            //leecode server take this as 
            area = (area+(y-cur_y)*sum_x) % mod;
#ifdef DEBUG
			cout << "--> (" << y << "," << x1 << "," << x2 <<"," << sig << ")\n";
			cout << "		(" << cur_y << ", " << sum_x << ")\n"; 
			cout << "area: " << area << "\n";
#endif
            //update cur_y
            cur_y = y;
            //update acc_xidx
            for(int j=map_xval2xidx[x1]; j<map_xval2xidx[x2]; j++){
                //FIXME note remember to reduce the x area
                acc_xidx[j]+=sig;
            }
#ifdef DEBUG
			for(auto j:acc_xidx) cout << j << ",";
			cout << "\n";
#endif
            //update sum_x
            sum_x = 0;
            for(int j=0; j<acc_xidx.size(); j++){
                if(acc_xidx[j]>0){
                    sum_x += xval[j+1]-xval[j];
                }
            }
#ifdef DEBUG
			cout << "sum_x: " << sum_x  << "\n";
			cout << "<--\n";
#endif
        }
        return area;
    }
};
int main(){
    Solution s;
	//vector<vector<int>> r = {{0,0,2,2},{1,0,2,3},{1,0,3,1} };
	//vector<vector<int>> r = {{0,0,3,1},{2,0,3,3} };
	vector<vector<int>> r = {{224386961,128668997,546647847,318900555},{852286866,238086790,992627088,949888275},{160239672,137108804,398130330,944807066},{431047948,462092719,870611028,856851714},{736895365,511285772,906155231,721626624},{289309389,607009433,558359552,883664714},{780746435,397872372,931219192,863727103},{573523994,124874359,889018012,471879750},{619886375,149607927,727026507,446976526},{51739879,716225241,115331335,785850603},{171077223,267051983,548436248,349498903},{314437215,169054168,950814572,481179241},{64126215,646689712,595562376,829164135},{926011655,481539702,982179297,832455610},{40370235,231510218,770233582,851797196},{292546319,45032676,413358795,783606009},{424366277,369838051,453541063,777456024},{211837048,142665527,217366958,952362711},{228416869,402115549,672143142,644930626},{755018294,194555696,846854520,939022548},{192890972,586071668,992336688,759060552},{127869582,392855032,338983665,954245205},{665603955,208757599,767586006,276627875},{260384651,10960359,736299693,761411808},{46440611,559601039,911666265,904518674},{54013763,90331595,332153447,106222561},{73093292,378586103,423488105,826750366},{327100855,516514806,676134763,653520887},{930781786,407609872,960671631,510621750},{35479655,449171431,931212840,617916927}};
	cout << s.rectangleArea(r) << "\n";
}
