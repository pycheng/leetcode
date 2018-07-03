#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
	// in[s].start <= s < in[s].end  || s < in[s].start
	// e < in[e].start 
	bool bsearch(vector<Interval>& in, Interval n, int& s, int& e){
		//seartch s
		int left = 0, right = in.size()-1;
		int ind = (left+right)/2;
		while(left <= right && ind < in.size()-1){
            if(in[ind].start <= n.start && in[ind+1].start > n.start){
                break;
            }else if(in[ind].start < n.start){
                left = ind+1;
            }else{
                right = ind-1;
            }
            ind = (left+right)/2;
		}
        if(in[ind].start <= n.start && in[ind].end >= n.start) s = ind;
        else s = ind+1;
        //search e
        left = 0, right = in.size()-1;
        ind = (left+right)/2;
        while(left <= right  && ind < in.size()-1){
            if(in[ind].start <= n.end && in[ind+1].start > n.end){
                break;
            }else if(in[ind].end < n.end){
                left = ind+1;
            }else{
                right = ind-1;
            }
            ind = (left+right)/2;
        }
        e = ind+1;
        return s==e;
	}
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.emplace(intervals.begin(), INT_MIN, INT_MIN);
        //intervals.emplace(intervals.end(),   INT_MAX, INT_MAX);
        int s, e;
        vector<Interval>::iterator its, ite;
        bsearch(intervals, newInterval, s, e);
        cout << s << "," << e << "----\n";
        its = intervals.begin()+s;
        
        ite = intervals.begin()+e;
        if(s!=e){
            newInterval.start = min(newInterval.start, its->start);
            newInterval.end   = max(newInterval.end  , prev(ite)->end);
            intervals.erase(its,ite);
        }
        intervals.emplace(its, newInterval);
        intervals.erase(intervals.begin());
        
        //intervals.erase(intervals.end());
        return intervals;
    }
};
int main(){
    vector<Interval> t={Interval(1,5)};
    Solution s;
    Interval v(5,6);
    s.insert(t,v);
    for(auto i:t){
        cout << i.start << "," << i.end << "\n";
    }
}
