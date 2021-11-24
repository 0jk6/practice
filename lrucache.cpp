class LRUCache {
private:
    //store the key value pairs in the doubly linked list
    list<pair<int, int>> dll;
    //store the key and an iterator to the key in the map
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int size;

public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        //if the key is in map, then we can access it
        if(mp.find(key) == mp.end())
            return -1;

        //if key is present in map
        //then we have to move that node in doubly linked list to the front
        
        //let's move the node to the front of dll
        dll.splice(dll.begin(), dll, mp[key]);

        //once we move it to the front, we can access the value
        int ans = mp[key]->second;

        return ans;
    }

    void set(int key, int val) {
        //if this key is already present, then we have to modify it's value
        //in the list
        if(mp.find(key) != mp.end()){
            //this key is already present in the list
            //so move it to the front of the list
            dll.splice(dll.begin(), dll, mp[key]);

            mp[key]->second = val;
            return;
        }
        //if it was not found in the map, then we should insert it
        //before we insert something into the list
        //we need to check if the size of the list is not greater than the
        //capacity. If it is greater, then we should remove the back element
        //and we should also remove the key from the
        if(dll.size() == size){
            int key = dll.back().first;
            mp.erase(key);
            dll.pop_back();
        }

        dll.push_front({key, val});
        mp[key] = dll.begin();
    }
};