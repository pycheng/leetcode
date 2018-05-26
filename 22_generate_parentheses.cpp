#include <vector>
#include <iostream>
using namespace std;

void parens(string buf, int l, int r, vector<string> &res)
{
    if(l<0 || r<l) return;

    if(l==0 && r==0){
        res.push_back(buf);
    }else{
        parens(buf+"(", l-1, r, res);
        parens(buf+")", l, r-1, res);
    }
}
vector<string> parens(int num)
{
    vector<string> res;
    parens("", num, num, res);
    return res;
}

int main(){
    vector<string> res;
    res = parens(3);
    for(auto i:res) cout << i << ",";
    return 0;
}
