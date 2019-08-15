
class LRUCache {
      typedef struct lair{
        int key;
        int val;
          bool operator ==(const lair & in){
              return in.key==key;
          }
    }air;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        for(auto it=lru.begin();it!=lru.end();it++){
            if((*it).key==key){
                int val=(*it).val;
                air now={key,val};
                lru.remove(now);
                lru.push_front(now);
                return val;
            }
                
        }
        return -1;
    }
    
    void put(int key, int value) {
        air now={key,value};
        lru.remove(now);
        if(lru.size()<cap){
            lru.push_front(now);
        }
        else{
           lru.pop_back(); 
            lru.push_front(now);
        }
        return;
    }
   
    list<air> lru;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 
 class Dlink {
public:
	int key;
	int val;
	Dlink *pre;
	Dlink* next;
	Dlink() :key(0), val(0), pre(nullptr), next(nullptr) {}
	Dlink(int i, int j, Dlink *c, Dlink *d) :key(i), val(j), pre(c), next(d) {}
};
class LRUCache {
public:
	int capacit;
	map<int, Dlink*> dl;
	Dlink *tail;
	Dlink *pre;

	LRUCache(int capacity) {
		capacit = capacity;
		tail = new Dlink();
		pre = new Dlink();
		tail->pre = pre;
		pre->next = tail;
	}
	void outt() {
		Dlink*a = pre;
		while (a)
		{
			cout << a->key<<" ";
			a = a->next;
		}
	}
	int get(int key) {
		if (dl.find(key) == dl.end())
			return -1;
		Dlink *now = dl[key];
		update_d(key);
		return now->val;
	}

	void put(int key, int value) {
        if(dl.find(key)!=dl.end())
        {
            dl[key]->val=value;
            update_d(key);
            return;
        }
		if (dl.size() == capacit)
			rem_last();
		Dlink *now = new Dlink(key, value, pre, pre->next);
		pre->next->pre = now;
		pre->next = now;
		dl[key] = now;
	}
	void rem_last() {
		Dlink *now = tail->pre;
		now->pre->next = tail;
		tail->pre = now->pre;
        auto it=dl.find(now->key);
        if(it!=dl.end())
		dl.erase(it);
		return;
	}
	void update_d(int key) {
		Dlink *now = dl[key];
		now->pre->next = now->next;
		now->next->pre = now->pre;
		now->next = pre->next;
		now->pre = pre;
		pre->next->pre = now;
		pre->next = now;

		return;
	}

};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/