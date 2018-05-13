//#array, #rand
#include <iostream>

#include <vector>
using namespace std;

vector<int> s(vector<int> in, int n){
    vector<int> rslt(n);
    srand(time(NULL));
    
    for(int i=0, j=0; j<n; i++, j++){
        i += (n-j-1 == 0)?0:rand() % (n-j-1);
        rslt[j] = in[i];
    }
    return rslt;
}
int main(){
   for(auto i: s({1,2,3,4,5,11,12,15,18,20,22}, 5)){
        cout << i << ",";
    }
   cout << "\n";
}
