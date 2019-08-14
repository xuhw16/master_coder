
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