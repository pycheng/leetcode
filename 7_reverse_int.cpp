#include <iostream>
#include <math.h>
using namespace std;

// res = x%10 + res*10;
// sign: record sign and process abs(x), return to append sign
// overflow: res < ori return 0;
// drop tailing zeros: remove tailing zero will save O(1) time 

int reverse(int x){
    int res = 0;
    int sign = (x<0)? -1: 1;
    x = abs(x);
    while(x>0){
        int ori = res;
        res = res*10+x%10;
        x = x/10;
        if(ori !=  res/10) return 0;
    }
    return res*sign;
}

int main(){
    cout << reverse(1534236469)<<"\n";
    cout << reverse(-1234567890)<<"\n";
    cout << reverse((int)((double)pow(2,32)-1))<<"\n";
}
