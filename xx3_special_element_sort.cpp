//#sort
//s_sort
//quick sort can only swap special elemenet.
//please note that swap two item is not as assign a buffer
//since you cannot change/assign swap items' content
//i.e. think about the if(lt!=i){
//
//s_sort_rec
//recursive version. base case {2,999,1} ==> {999,1,2}
#include <iostream>
#include <vector>
using namespace std;

void swap(int & a, int & gap){
    int buf;
    buf = gap;
    gap = a;
    a = buf;
    return;
}

int partition(vector<int> &in, int s, int e, int& gap){
    int lt = -1;
    for(int i=s; i<e; i++){
        if(in[i]<in[e]){
            lt++;
            if(lt!=i){
                swap(gap, in[lt]);
                swap(in[i], gap);
                swap(gap, in[lt]);
            }
        }
    }
    lt++;
    if(lt!=e){
        swap(gap, in[lt]);
        swap(in[e], gap);
        swap(gap, in[lt]);
    }
    return lt;
}

void q_sort(vector<int> &in, int s, int e, int& gap){
    int pvt;
    if(s<e){
        pvt = partition(in, s, e, gap);
        q_sort(in, s, pvt-1, gap);
        q_sort(in, pvt+1, e, gap);
    }
}


void s_sort(vector<int> &in, int se){
    int se_idx, i;
    //find the index of special element
    for(i=0; i<in.size(); i++){
            if(in[i] == se){ se_idx=i; break;}
    }
    //swap the special element to the end of input in[in.size()-1]
    swap(in[se_idx], in[in.size()-1]);
    se_idx = in.size()-1;

    //quick sort in[0..in.size()-2]
    q_sort(in, 0, in.size()-2, in[se_idx]);

    return; 
}

void sort_rec(vector<int> & in, int run, int se_idx){
    if(run == 0 ){
        for(int i = se_idx; i<in.size()-1;i++){
            swap(in[i+1], in[i]);
        }
        return;
    }
    //swap special element to in.size()-2
    //second last element
    if(se_idx == 0){
        for(int i=0; i<in.size()-2; i++){
            in[i] = in[i+1]; 
        }
        in[in.size()-2] = 999;
        se_idx = in.size()-2;
    }
    
    if(in[se_idx-1] > in[se_idx+1]){
        //base case {2,999,1} ==> {999,1,2}
        swap(in[se_idx+1], in[se_idx]);
        swap(in[se_idx+1], in[se_idx-1]);
    }else{
        //base case {1,999,2} ==> {999,1,2}
        swap(in[se_idx-1], in[se_idx]);
    }
    se_idx--;

    for(auto i: in) cout<< i<<","; cout<<"\n";
    return sort_rec(in, run-1, se_idx);
}
void s_sort_rec(vector<int> &in, int se){
    int se_idx, i;
    //find the index of special element
    for(i=0; i<in.size(); i++){
            if(in[i] == se){ se_idx=i; break;}
    }
    //swap the special element to in[in.size()-2]
    swap(in[se_idx], in[in.size()-2]);
    se_idx = in.size()-2;
    sort_rec(in,in.size(),se_idx);
}


int main(){
    vector<int> test = {1,2,3,4,5,999,6,7,8};
    
    //s_sort(test, 999);
    s_sort_rec(test, 999);
    for(auto i: test) cout<< i<<","; cout<<"\n";

    return 0;
}
