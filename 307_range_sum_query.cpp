#include<iostream>
#include<vector>
using namespace std;


//option 1 use runsum table to record the sum of(nums[0..i])
//init the table O(n)
//update nums[i] O(n)
//query O(1)

//option 2 use fenwick tree -- prefix sum
//init the tree  O(nlogn)
//update nums[i] O(logn)
//query          O(logn)


class fenwick_tree{
private:
    vector<int> data;
	int lowbit(int x) {return x&(-x);}
public:
    fenwick_tree(int sz):data(sz+1, 0){}
	void update(int v, int delta){
		v++;
		while(v<data.size()){
            data[v] += delta;
            v += lowbit(v);
		}	
	}
    int query(int v){
        v++;
        int sum = 0;
        while(v>0){
            sum+=data[v];
            v -= lowbit(v);
        }
        return sum;
    }
    void dump(){
        for(auto i: data){
            cout << i << ", ";
        }
        cout << "\n";
    }
};


class NumArray {
    fenwick_tree fwt;
    vector<int>  n;
public:
    NumArray(vector<int> nums):fwt(nums.size()), n(nums){
       for(int i = 0; i< nums.size(); i++){
           fwt.update(i, nums[i]);
       }
       fwt.dump();
    }
    
    void update(int i, int val) {
       fwt.update(i, val - n[i]);
       n[i] = val;
       fwt.dump();
    }
    
    int sumRange(int i, int j) {
        return fwt.query(j)-fwt.query(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
int main(){
    vector<int> n = {7,2,7,2,0};
    NumArray *obj = new NumArray(n);
    obj->update(4,6);
    obj->update(0,2);
    obj->update(0,9);
    obj->update(3,8);
    cout << obj->sumRange(0,4) << "\n";
}
