//#bt
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class node{
public:
    int val;
    node *left, *right;
    node(int x):val(x), left(NULL), right(NULL){}
};


node* bt_to_graph(node *r, int k, unordered_map<node*, vector<node*>>& g){
    if(r == NULL) return NULL;

    if(r->left){  
        g[r].push_back(r->left);
        g[r->left].push_back(r);
    }
    if(r->right){
        g[r].push_back(r->right);
        g[r->right].push_back(r);
    }
    node *ret_l, *ret_r;

    ret_l = bt_to_graph(r->left,  k, g);
    ret_r = bt_to_graph(r->right, k, g);

    if(r->val == k) return r;
    else return (ret_l!=NULL)?ret_l:ret_r;
}

node* closest_leaf(node *r, int k){
    unordered_map<node*, vector<node*>> graph;
    unordered_set<node*> visited;
    queue<node*> q;

    //from r do dfs to create the graph, and mark n
    node* target = bt_to_graph(r, k, graph); 


    //from n do bfs and return the first node
    visited.insert(target);
    q.push(target);
    while(!q.empty()){
        target = q.front(); q.pop();
        for(auto i: graph[target]){
            if(visited.count(i)<=0){
                if(!i->left &&!i->right) return i;
                visited.insert(i);
                q.push(i);
            }
        }
    }
    return NULL;
}

int main(){

//(1,3,2),  1 return 2 or 3
    node *r, *n, *a; 
    r = n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    a = closest_leaf(r, 2); 
    cout << a->val << "\n";

//(1,2,3,4,5,6), 2 return 3
    n = r->left;
    n->left = new node(4);
    n->left->left = new node(5);
    n->left->left->left = new node(6);
    a = closest_leaf(r, 2); 
    cout << a->val << "\n";
}


