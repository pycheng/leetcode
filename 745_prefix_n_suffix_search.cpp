#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
using namespace std;


//option 1 hash_table with key of every prefix_suffix
// e.g., a_e, ap_le, ..., apple_apple
// n: number of words, l: length of word q:number of query
// time complexity for build hash: O(n*l^3)
//      l^2 possible keys, each key length 2*l 
// time complexity for find : O(q*l) --> construct the key took O(l)
// space complexity: O(n*l^2)
//
//option 2 trie with key of suffix_prefix 
// e.g., e_apple, le_apple, ..., apple_apple
// time complexity for build trie: O(n*l^2)
//      l possible keys, each key length 2*l 
// time complexity for find : O(q*l)
// space complexity: O(n*l^2)

class WordFilter_op2{
private:
    class trie_node{
    public:
        char c;
        unordered_map<char, trie_node*> children;
        bool isword;
        int wordidx;
        trie_node(char ch): c(ch), isword(false), wordidx(-99){}
        trie_node(char ch, int idx): c(ch), isword(false), wordidx(idx){}
        ~trie_node(){
            for(auto c:children)
                delete c.second;
        }
        trie_node* find(char ch){
            return children[ch];
        }
        trie_node* add_child(char ch, int idx){
            //if(children.count(ch) <= 0){
            if(children.find(ch) == children.end()){
                children[ch] = new trie_node(ch, idx);
            }else{
                children[ch]->wordidx = idx;
            }
            return children[ch];
        }
        void set_word(bool is, int id){
            isword = is;
            wordidx = id;
        }
        bool is_word(){
            return isword;
        }
        int get_id(){
            return wordidx;
        }
    };
    class trie{
    private:
        unique_ptr<trie_node> root;
    public:
        trie():root(new trie_node('@')){}
        void insert(string s, int idx){
            cout << "inserting: " << s << "\n";
            trie_node *n = root.get();
            for(auto c:s){
                n = n->add_child(c, idx);
            }
            n->set_word(true, idx);
        }
        int search(string s){
            trie_node *n = root.get();
            //cout << "\n\n";
            //for(auto v:root->children['a']->children['_']->children) cout << v.first << ",";
            //for(auto v:root->children['a']->children['_']->children) cout << v.second->wordidx << ",";
            //cout << "\n\n";
            for(auto c:s){
                n = n->find(c);
                if(n==NULL) return -1;
            }
            return (n!=NULL)?n->get_id():-1;
        }
    };
    trie t;
public:
    WordFilter_op2(vector<string> words) {
        for(int i=0; i<words.size(); i++){
            string key = "_"+words[i];
            t.insert(key, i);
            for(int j=words[i].size()-1; j>=0; j--){
                key=words[i][j]+key;
                t.insert(key, i);
            }
        }
    }

    int f(string prefix, string suffix) {
        string key = suffix+"_"+prefix;
        cout << "searching for: " << key;
        return t.search(key);
    }
};

class WordFilter_op1 {
private:
    unordered_map<string, int> map;
public:
    WordFilter_op1(vector<string> words) {
        for(int i=0; i<words.size(); i++){
            for(int prefix_len = 0; prefix_len <= words[i].size(); prefix_len++){
                for(int suffix_len = 0; suffix_len <= words[i].size(); suffix_len++){
                    string key = words[i].substr(0, prefix_len)+"_";
                    key += words[i].substr(words[i].size()-suffix_len, suffix_len);
                    map[key] = i;
                }
            }
	    } 
    }
    
    int f(string prefix, string suffix) {
        string key = prefix+"_"+suffix;
        if(map.find(key) != map.end())
            return map[key];
        return -1;
    }
};

int main(){
//    WordFilter_op2 wop1({"apple"});
//    cout << wop1.f("a", "e") << "\n";
//    cout << wop1.f("an", "le") << "\n";
//    cout << wop1.f("", "e") << "\n";

    WordFilter_op2 wop1({"aa"});
    cout << wop1.f("a", "a") << "\n";
}
