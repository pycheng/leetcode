#include <iostream>
#include <map>
#include <unordered_map>
#include <memory>
using namespace std;

class Trie {
private:
	class trie_node{
    private:
		char c;
        bool isword;
		unordered_map<char, trie_node*> children;
	public:
		trie_node(char ch):c(ch), isword(false){}
		~trie_node(){
			for(auto i: children){
				delete i.second;
			}	
		}
        trie_node* add_child(char c){
            if(children.count(c) <= 0){
                children[c] = new trie_node(c);
            }
            return children[c];
        }
        trie_node* find_child(char c){
            if(children.count(c) > 0){
                return children[c];
            }
            return NULL;
        }
        void set_word(bool isleaf){
            isword = isleaf;
        }
        bool is_word(){ return isword;}
	};
    unique_ptr<trie_node> root;
    trie_node* find(string word) {
       trie_node* n = root.get();
       for(auto c:word){
           n = n->find_child(c);
           if(n == NULL) return n;
       }
       return n;
    }
public:
    /** Initialize your data structure here. */
    Trie():root(new trie_node('@')){
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie_node* n = root.get();
        for(auto c:word){
            n = n->add_child(c);
        }
        n->set_word(true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie_node* n = find(word);
        return n!=NULL && n->is_word();

    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_node* n = find(prefix);
        return n!=NULL;
    }
};


int main(){
    Trie t;
    t.insert("apple");
    cout << "should be true: " << t.search("apple") << "\n";
    cout << "should be true: " << t.startsWith("app") << "\n";
    cout << "should be false: " << t.search("app") << "\n";
    t.insert("app");
    cout << "should be true: " << t.search("app") << "\n";
}

