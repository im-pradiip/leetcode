class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string>res;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            if(i%3==0&&i%5!=0)
                res.push_back("Fizz");
            else if(i%5==0&&i%3!=0)
                res.push_back("Buzz");
            else if(i%5==0&&i%3==0)
                res.push_back("FizzBuzz");
            else
                res.push_back(s);
        }
        return res;
    }
};