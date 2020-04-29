class Solution {
public:
    int myAtoi(string str) {
         if(!str.size())//if not string answer 0
            return 0;

        int index = 0;
        //move the starting white spaces. skipping
        while( index < str.size()&&  str[index] == ' ')
            index++;
        
        int neg = 0;
        
        //Check if first char is non numeric, or sign symbol.
        if(index == str.size() || (str[index] < '0' ||  str[index] > '9') )
        {
            if(str[index] == '+')
            {
                index++;
            }
            else if(str[index] == '-'){
                neg=1;
                index++;
            }
            else
                return 0;   //if starting with character.
        }
        
        long int num = 0; 
        while(index < str.size())
        {
            //Break if any non numeric character is found.
            if( (str[index] < '0') ||  (str[index] > '9') )
                break;

            num *= 10;            
            num +=  (str[index] - '0');
            
            //Checking overflow
            if(neg && (num > INT_MAX) )
                return INT_MIN;            
            else if (num > INT_MAX)
                return INT_MAX;
            index++;
        }
            
        if(neg)    //if negative answer in neg else positive
            num *= -1;
        
        return num;
    }
};
