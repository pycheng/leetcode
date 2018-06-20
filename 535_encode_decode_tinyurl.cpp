#include <iostream>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;

// actual implementation hash should be replaced by leveldb/mysql 
// hash function should be replaced by uuid to prevent the comflict

class Solution {
public:
	unordered_map<string, string> h;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
		stringstream stream; 
		stream << hex << (int)(hash<string>()(longUrl));
		string key(stream.str());
		h[key] = longUrl;
		return key;        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return h[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
int main(){
	Solution s;
	string res;
	res = s.encode("https://leetcode.com/problems/design-tinyurl");
	cout << res << "\n";
	res = s.decode(res);
	cout << res << "\n";
}
