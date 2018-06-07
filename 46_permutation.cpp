#include<vector>
#include<iostream>
using namespace std;
void perm(vector<int> pre, vector<int> pos, vector<vector<int>> &res)
{
    if(pos.size() == 0){
        res.insert(res.begin(),pre);
    }
    for(int i=0; i<pos.size(); i++)
    {
        vector<int> v1;
        vector<int> v0;
        v1=pos; v0=pre;
        v1.erase(v1.begin()+i);
        v0.push_back(pos[i]);
        perm(v0, v1, res);
    }

}
vector<vector<int>> permutation(vector<int> remainer){
    vector<vector<int>> res;
    perm({},remainer,res);
    return res;
}

int main(){
   vector<int> test = {1,2,3};
   vector<vector<int>> res;
   res = permutation(test);

   for(auto i:res){
       string sep = "";
       for (auto j:i){
        cout << sep << j;
        sep=",";
       }
       cout << "\n";
   }
}
