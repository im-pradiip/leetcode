class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>temp;// initialise max heap
        for(auto s: stones){
            temp.push(s);      //filling values in temp priority_queue
        }
        while(temp.size()>=2){  //till the size>=2
            int x=temp.top();   //first greater ele
            temp.pop();         
            int y=temp.top();   //second greater ele
            temp.pop();
            if(x!=y)            //if both are equal nothing to do else subtract and push
                temp.push(x-y);
        }
        if(temp.size()==1)      //if any element remains in the priority_queue that is the ans 
            return temp.top();
        else                    //else return 0 no elem left
            return 0;
    }
};