#include <map>
using namespace std;
 
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = NULL;
        next = NULL;
    }
};
 
class LRUCache{
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mp.clear();
        size = 0;
    }
     
    int get(int key) {
        if (mp.find(key) == mp.end()) { // not found
            return -1;
        }
        else { // found
            Node* cur = mp.find(key)->second;
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            moveToFirst(cur);
            return cur->val;
        }
    }
     
    void set(int key, int value) {
        if (capacity == 0) return;
        if (mp.find(key) == mp.end()) { // not found
            if (size >= capacity) {
                // remove last one
                Node* deltmp = tail->prev;
                deltmp->prev->next = tail;
                tail->prev = deltmp->prev;
                unordered_map<int, Node*>::iterator it = mp.find(deltmp->key);
                mp.erase(it);
                delete deltmp;                
                size--;
            }
            Node* addtmp = new Node(key, value);
            moveToFirst(addtmp);
            mp[key] = addtmp;
            size++;
        }
        else { // found
            Node* cur = mp.find(key)->second;
            cur->val = value;
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            moveToFirst(cur);
        }
    }
     
private:
    unordered_map<int, Node*> mp;
    int capacity = 0;
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
     
    void moveToFirst(Node* cur) {
        cur->next = head->next;
        cur->prev = cur->next->prev;
        head->next = cur;
        cur->next->prev = cur;
    }
};