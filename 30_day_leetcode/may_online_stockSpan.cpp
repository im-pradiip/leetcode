class StockSpanner {
public:
    /*
    vector<int>prices;
    stack<int>stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int count=1;
        int i=prices.size()-1;
        for(int j=i-1;(j>=0)&&(prices[i]>=prices[j]);j--)
                count++;
        return count;
    }
    */
    
    //approach 2
    //using pair
    stack<pair<int,int>>stk;
    StockSpanner(){
        
    }
    
    int next(int price){
        
        int cnt=1;`
        while(!stk.empty()&&stk.top().first<=price){
            cnt+=stk.top().second;
            stk.pop();
        }
        stk.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */