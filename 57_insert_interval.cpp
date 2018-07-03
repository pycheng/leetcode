#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//option 1. directly search the start and end intervals covers newinterval[start, end)
// insert O(logn)
//option 2. insert the intervals to the RBT and search the start and end intervals covers newinterval[start, end)
// insert O(logn)
class Solution {
private:
    //case s1: in[s].start <= n.start && in[s].end >= n.start  merge with s
    //case s2: in[s].end > n.start && in[s+1].start > n.start  insert bt s/s+1
    //case e1: in[e].start > n.end
    //case e2: e = in.size();
    bool bs(vector<Interval> &in, Interval n, int &s, int &e)
    {
        in.emplace(in.begin(), INT_MIN, INT_MIN);
        in.emplace(in.end(),   INT_MAX, INT_MAX);
        int left = 0;
        int right = in.size()-1;
        //binary search s
        while(left <= right){
            s = (left+right)/2;
            if(in[s-1].start <= n.start && in[s].start > n.start)
                break;
            else if(in[s].start > n.start)
                right = s-1;
            else
                left = s+1;
        }
        if(in[s-1].start <= n.start && in[s-1].end >= n.start) s--;
        //binary search e
        left = 0;
        right = in.size()-1;
        while(left <= right){
            e = (left+right)/2;
            if(in[e-1].start <= n.end && in[e].start > n.end)
                break;
            else if(in[e].start > n.end)
                right = e-1;
            else
                left = e+1;
        }
        in.erase(in.begin());
        in.erase(in.end());
        s--;e--;
        return s!=e;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       int s, e;
       bs(intervals, newInterval, s, e);
       cout << s << "," << e << "\n\n";
       if(s!=e){
           newInterval.start = min(newInterval.start, intervals[s].start);
           newInterval.end   = max(newInterval.end, intervals[e-1].end);
           intervals.erase(intervals.begin()+s, intervals.begin()+e);
       }
       intervals.emplace(intervals.begin()+s, newInterval);
       return intervals;
    }
};


int main(){
    vector<Interval> t;
#if 1
    t.emplace_back(1,2);
    t.emplace_back(3,5);
    t.emplace_back(6,7);
    t.emplace_back(8,10);
    t.emplace_back(12,16);
    Solution s;
    s.insert(t, Interval(4,8));
#else
    t.emplace_back(1,5);
    Solution s;
    s.insert(t, Interval(0,5));
#endif
    for(auto i:t) cout << i.start << "," << i.end << "\n";

}
