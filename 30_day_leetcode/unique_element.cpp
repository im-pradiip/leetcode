class FirstUnique {
public:
    queue<int>q;//for ordering who comes first unique element 
    unordered_map<int,int>map;//stores element and its frequency 
    FirstUnique(vector<int>& nums) {//initiliase
        for(int num:nums)
            add(num);
    }
    
    int showFirstUnique() {
        while(!q.empty()&&map[q.front()]>1)//if the queue front element frequency greater than 1 means not distint so just pop that from the queue
            q.pop();
        if(q.empty())//if empty return -1 means no unique
            return -1;
        else
            return q.front();//else unique
    }
    
    void add(int value) {
        if(map.find(value)==map.end()){ // if not present just simplly add to the queue and initialise key with 1
            q.push(value);
            map.insert(make_pair(value,1));
            
        }
        else{ //if already present simply increase the frequency
            map[value]++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */