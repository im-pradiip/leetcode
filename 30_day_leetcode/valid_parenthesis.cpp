class Solution {
public:
    bool checkValidString(string s) {
        stack<int>stk1,stk2;
        //craeting two stack to store index of occurence of '(' and '*'......
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){//ifn s[i]=='(' simply push the index
                stk1.push(i);
            }
            else if(s[i]=='*'){//same as above
                stk2.push(i);
            }
            else{//else remove one of them if '(' is present removee from this stack
                //else remove from * stack by assuming star is left parenthesis
                if(stk1.size()>0)
                    stk1.pop();
                else if(stk2.size()>0)
                    stk2.pop();
                else
                    return false;
            }
        }
        while(!stk1.empty()&&!stk2.empty()){
            if(stk1.top()>stk2.top())//this is to check whether star cames before or after
                //if before then it is false as it act as a right parentheisis or null 
                //and we have more left paranthesis
                return false;
            stk1.pop();
            stk2.pop();
        }
        
        //
        if(stk1.size()>0)
            return false;//if left parenthesis remains in the stack
        return true;
    }
};