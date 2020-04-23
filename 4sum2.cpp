class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        vector<int> vec;
		//Merge A,B and store result in vector v
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                vec.push_back(A[i]+B[j]);
            }
        }
        //here vector vec contain :- -1 0 0 1
        unordered_map<int,int> m;
		//Merge C,D and store count in map m
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                m[C[i]+D[j]]++;
            }
        }
        //here map contain :- -1->1  ...adding to answer
        // 1->1//adding to answer
        // 2->1
        // 4->1
        //Iterate over every element in Merged vector and find the number of elements that sum up to zero
        int ans=0;
        for(int i=0;i<vec.size();i++){
            ans+=m[-vec[i]];  // here find negative of that vector number in map if exist means sum = 0 and adding the frequency
        }
        return ans;  //return the final answer
    }
};