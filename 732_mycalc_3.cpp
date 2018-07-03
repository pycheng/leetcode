#include <iostream>
#include <map>
#include <limits.h>
using namespace std;

// brute force hashmap, hash[s]
// time complexity = O(n^2), n is the number of pair of (start, end)
// space complexity = O(n)
class MyCalendarThree_option1{
private: 
    map<int, int> m;  //value 1: start -1: end
public:
    MyCalendarThree_option1(){
    }
    // [start, end)
    int book(int start, int end) {
        m[start]++; m[end]--;
        int max_book = 0;
        int run_sum  = 0;
        for(auto i:m){
            run_sum += i.second;
            max_book = max(max_book, run_sum);
        }
        return max_book;
    }
};
// store the max_len internally and traverse only overlapped record
// time complexity = O(n^2) space complexity = O(n)
class MyCalendarThree_option2 {
private: 
    map<int, int> m;  //value: current book count
    int max_book;
public:
    MyCalendarThree_option2():max_book(0){
        m[INT_MIN] = 0;
        m[INT_MAX] = 0;
    }
    
    int book(int start, int end) {
        //setup left/right boundary
        map<int, int>::iterator left  = prev(m.upper_bound(start));   //left  <= start
        map<int, int>::iterator right = m.lower_bound(end);           //right >= end
        //iterate through left to right
        //FIXME we cannot use cur++ in the for statement as below we insert m[start]
        for(auto cur=left,nxt=cur; cur!=right; cur=nxt){
            nxt = next(cur); // nxt++ is also fine
            //cout << cur->first << "," << nxt->first << "\n";

            //update m[end]
            //FIXME nxt record the position after m[end]
            if(end < nxt->first) m[end] = cur->second;
            //update m[start]
            //FIXME nxt record the position after m[start]
            if(cur->first <= start  && start < nxt->first){
                max_book = max(max_book, m[start] = cur->second+1);
            }else{
                max_book = max(max_book, ++cur->second);
            }
        }
        //for(auto i:m) cout << i.first << "," << i.second << "\n";
        return max_book;
    }
};
int main(){
    MyCalendarThree_option2 mc;
    cout << "(10,20)--->" << mc.book(10,20) << "\n"; //1
    cout << "(50,60)--->" << mc.book(50,60) << "\n"; //1
    cout << "(10,40)--->" << mc.book(10,40) << "\n"; //2
    cout << "( 5,15)--->" << mc.book( 5,15) << "\n"; //3
    cout << "( 5,10)--->" << mc.book( 5,10) << "\n"; //3
    cout << "(25,55)--->" << mc.book(25,55) << "\n";//3
}
