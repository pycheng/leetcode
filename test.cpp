#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <math.h>
using namespace std;

int rectangleArea(vector<vector<int>>& rectangles);

int main(){
	//vector<vector<int>> r = {{0,0,2,2},{1,0,2,3},{1,0,3,1,} };
	//vector<vector<int>> r = {{0,0,3,1},{2,0,3,3} };
	//vector<vector<int>> r = {{0,0,int(pow(10,9)),int(pow(10,9))}};
	vector<vector<int>> r = {{224386961,128668997,546647847,318900555},{852286866,238086790,992627088,949888275},{160239672,137108804,398130330,944807066},{431047948,462092719,870611028,856851714},{736895365,511285772,906155231,721626624},{289309389,607009433,558359552,883664714},{780746435,397872372,931219192,863727103},{573523994,124874359,889018012,471879750},{619886375,149607927,727026507,446976526},{51739879,716225241,115331335,785850603},{171077223,267051983,548436248,349498903},{314437215,169054168,950814572,481179241},{64126215,646689712,595562376,829164135},{926011655,481539702,982179297,832455610},{40370235,231510218,770233582,851797196},{292546319,45032676,413358795,783606009},{424366277,369838051,453541063,777456024},{211837048,142665527,217366958,952362711},{228416869,402115549,672143142,644930626},{755018294,194555696,846854520,939022548},{192890972,586071668,992336688,759060552},{127869582,392855032,338983665,954245205},{665603955,208757599,767586006,276627875},{260384651,10960359,736299693,761411808},{46440611,559601039,911666265,904518674},{54013763,90331595,332153447,106222561},{73093292,378586103,423488105,826750366},{327100855,516514806,676134763,653520887},{930781786,407609872,960671631,510621750},{35479655,449171431,931212840,617916927}};
	rectangleArea(r);
}


int rectangleArea(vector<vector<int>>& rectangles){
        int mod = 1000000000 + 7;
        vector<int> x = {0};
        for (auto r : rectangles) {
            x.push_back(r[0]);
            x.push_back(r[2]);
        }
        sort(x.begin(), x.end());
        vector<int>::iterator end_unique = unique(x.begin(), x.end());
        x.erase(end_unique, x.end());
		//FIXME why do we need this map?
        unordered_map<int, int> x_i;
        for (int i = 0; i < x.size(); ++i) {
            x_i[x[i]] = i;
        }
        cout << "x  ";
        for(auto i:x) cout << i << ",";
        cout << "\nx_i  ";
        for(auto i:x_i) cout << "(" << i.first << "," << i.second << "), ";
        cout << "\n";
        vector<int> count(x.size(), 0);
        vector<vector<int>> L;
        for (auto r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            L.push_back({y1, x1, x2, 1});
            L.push_back({y2, x1, x2, -1});
        }
        sort(L.begin(), L.end());
        long long cur_y = 0, cur_x_sum = 0, area = 0;
        for (auto l : L) {
            long long  y = l[0], x1 = l[1], x2 = l[2], sig = l[3];
			cout << "--> (" << y << "," << x1 << "," << x2 <<"," << sig << ")\n";
			cout << "		(" << cur_y << ", " << cur_x_sum << ")\n"; 
            area = (area + (y - cur_y) * cur_x_sum) % mod;
			cout << "area: " << area << "\n";
            cur_y = y;
			//count[i] means the number of overlaps on the interval [x[i], x[i + 1]]
            for (int i = x_i[x1]; i < x_i[x2]; i++)
                count[i] += sig;
			
			for(auto i:count) cout << i << ",";
			cout << "\n";

            cur_x_sum = 0;
            for (int i = 0; i < x.size(); ++i) {
                if (count[i] > 0)
                    cur_x_sum += x[i + 1] - x[i];
            }
			cout << "cur_x_sum: " << cur_x_sum  << "\n";
			cout << "<--\n";
        }
        return area;
}
#if 0
[[0,0,2,2],[1,0,2,3],[1,0,3,1]]

Scan from y = 0, count the coverage of rectangles on x.
For example, at y = 0, the intervale [0, 3] is covered by rectangles.
The current sum of coverage is 3.

Then we move our scan line upper to next y.
At y = 1, we add (1 - 0) * 3 = 3 to area. Now area = 3.
And we update the sum of coverage to 2 because it's coverd on [0, 2].

Then we move our scan line upper to next y.
At y = 2, we add (2 - 1) * 2 = 2 to area. Now area = 5.
And we update the sum of coverage to 1 because it's coverd on [1, 2].

Then we move our scan line upper to next y.
At y = 3, we add (3 - 2) * 1 = 1 to area. Now area = 6.
And we update the sum of coverage to 0.

The final result is 6.
#endif
#if 0
{{224386961,128668997,546647847,318900555},{852286866,238086790,992627088,949888275},{160239672,137108804,398130330,944807066},{431047948,462092719,870611028,856851714},{736895365,511285772,906155231,721626624},{289309389,607009433,558359552,883664714},{780746435,397872372,931219192,863727103},{573523994,124874359,889018012,471879750},{619886375,149607927,727026507,446976526},{51739879,716225241,115331335,785850603},{171077223,267051983,548436248,349498903},{314437215,169054168,950814572,481179241},{64126215,646689712,595562376,829164135},{926011655,481539702,982179297,832455610},{40370235,231510218,770233582,851797196},{292546319,45032676,413358795,783606009},{424366277,369838051,453541063,777456024},{211837048,142665527,217366958,952362711},{228416869,402115549,672143142,644930626},{755018294,194555696,846854520,939022548},{192890972,586071668,992336688,759060552},{127869582,392855032,338983665,954245205},{665603955,208757599,767586006,276627875},{260384651,10960359,736299693,761411808},{46440611,559601039,911666265,904518674},{54013763,90331595,332153447,106222561},{73093292,378586103,423488105,826750366},{327100855,516514806,676134763,653520887},{930781786,407609872,960671631,510621750},{35479655,449171431,931212840,617916927}}
#endif