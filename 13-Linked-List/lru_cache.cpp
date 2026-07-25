#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 
class LRUCache{
public:
    class Node{
        public:
            Node* prev;
            Node* next;
            int key,val;
            
            Node(int k, int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> m;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode){
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity){
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key){
        if(m.find(key) == m.end()){
            return -1;
        }
        int ans = m[key]->val;
        Node* ansNode = m[key]; 
        deleteNode(ansNode);
        addNode(ansNode);
    return ans;
    }
    
    void put(int key, int value){

        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
            delete oldNode;
        }

        if(m.size() == limit){
            Node* lru = tail->prev;
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
            delete lru;
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main(){

    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << lRUCache.get(1) << endl;    
    lRUCache.put(3, 3);                 
    cout << lRUCache.get(2) << endl;    
    lRUCache.put(4, 4);                 
    cout << lRUCache.get(1) << endl;    
    cout << lRUCache.get(3) << endl;    
    cout << lRUCache.get(4) << endl;    

return 0;
}