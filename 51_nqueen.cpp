//#dp
#include <vector> 
#include <iostream>
#include <math.h>
using namespace std;

bool isvalid(int row, int col, vector<int> columns)
{
    for(int i=0; i<row; i++){
        if(columns[i] == col) return false;
        if(abs(row-i) == abs(col-columns[i])) return false;
    }
    return true;
}

void nq_rec(int grid, int row, vector<int> & columns, vector<vector<string>> & res)
{
    if(row == grid){
        vector<string> buf(grid,string(grid,'.'));
        for(int r=0; r<grid; r++){
           buf[r][columns[r]]='Q';
        }
        res.push_back(buf);
        return;
    }

    for(int c=0; c<grid; c++){
        if(isvalid(row, c, columns)){
            columns[row] = c;
            nq_rec(grid, row+1, columns, res);
        }
    }

}

vector<vector<string>> nqueen(int n){
    vector<int> columns(n,-1); // in row index
    vector<vector<string>> res;

    nq_rec(n, 0, columns, res);
    return res;
}

int main(){
    vector<vector<string>> res;
    res = nqueen(4);
    for(auto i:res){
        for(auto j:i) cout<<j<<"\n";
        cout << "\n";
    }
    return 0;
}
