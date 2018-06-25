#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;


class LRUCache {
public:

	class node {
		public:
		int key;
		node* prev;
		node* next;
		node(int k):key(k), prev(NULL), next(NULL){}
	};

	int size, cap;
	unordered_map<int, pair<int, node*>> hash;
	node *head;
	node *tail;


    LRUCache(int capacity):size(0), head(NULL), tail(NULL), cap(capacity) {
        
    }
    
	void move_n_to_head(node *n){
		if(n!=head){
			if(tail == n) tail = n->prev;
			if(n->prev) n->prev->next = n->next;
			if(n->next) n->next->prev = n->prev;
			n->next = head; n->prev = NULL;
			head->prev = n;
			head = n;
		}
	}

    int get(int key) {
        if(hash.count(key) <= 0) return -1;
		else{
			move_n_to_head(hash[key].second);	
			return hash[key].first;
		}
    }
    
    void put(int key, int value) {
        if(hash.count(key) > 0){
			move_n_to_head(hash[key].second);	
            hash[key].first = value;
        }else{
            node *t = new node(key);
            hash[key] = make_pair(value, t);
            if(head == NULL){
                head = tail = t;
                size++;
            }else if(size < cap){
                t->next = head;
                head->prev = t;
                head = t;
                size++;
            }else{
                if(cap==1){
                    node *tmp = tail;
			        hash.erase(tmp->key);
                    delete tmp;
                    head = tail = t;
                }else{
			        node *tmp = tail;
			        tail = tail->prev;
			        tail->next = NULL;
			        hash.erase(tmp->key);
			        delete tmp;
			        t->next = head;
			        head->prev = t;
			        head = t;
                }
            }
        }
			 
    }
};
int main(){
LRUCache cache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cout << cache.get(1) << "\n";       // returns 1
cache.put(3, 3);    // evicts key 2
cout << cache.get(2) << "\n";       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cout << cache.get(1) << "\n";       // returns -1 (not found)
cout << cache.get(3) << "\n";       // returns 3
cout << cache.get(4) << "\n";       // returns 4
}
