#if 0
return the vedio name with top 10 watch rate.
map cannot sort -->  trnasfer to vector<pair<string, int> >
int f = (vod_s.size()>10)?10:vod_s.size();

int test = min((int)a.size(), 10);
there's a compile error without the (int)cast
#endif
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


bool msort(pair<string, int> a,pair<string, int> b){
    return a.second > b.second;
}


vector<string> twr(vector<pair<string, int> > in){
    vector<string> top10(10);
    map<string, int> vdo;
    vector<pair<string, int>> vod_s;

    for(auto i:in){
        if(vdo.count(i.first)>0){
            vdo[i.first]+=i.second;
        }else{
            vdo[i.first]=i.second;
        }
    }
    for(auto i:vdo){
        vod_s.push_back(make_pair(i.first, i.second));
    }
    sort(vod_s.begin(), vod_s.end(), msort);

    int f = (vod_s.size()>10)?10:vod_s.size();

    for(int i=0; i< f ; i++){
        top10[i] = vod_s[i].first;
    }
    return top10;
}

int main(){
    vector<pair<string, int> > a = {{"a", 10}, {"b", 0}, {"c", 1},{"d", 10}, {"e", 0}, {"f", 1},{"b", 190}, {"c", 5}, {"z", 100}};
    vector<string> rslt;

    rslt = twr(a);
    for(auto i:rslt) cout << i << ",";

    return 0;

}

