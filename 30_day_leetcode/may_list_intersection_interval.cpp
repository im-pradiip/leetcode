class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        //applying merge sort technique
        //checking croosly if A[i][0]>B[j][1] means array B is not in arnge and array B values are lacking hence         //incresing j;
        // similarly checking for array A if its value lack behind we simply increment i;
        // if not then check the ending value of both array the ending value which finished earlier comes into           //intersection interval and starting interval value we get is maximum of two start interval
        int i=0;
        int j=0;
        vector<vector<int>>res;
        while(i<A.size()&&j<B.size()){
            if(A[i][0]>B[j][1])
                j++;
            else if(B[j][0]>A[i][1])
                i++;
            else if(A[i][1]<B[j][1]){
                res.push_back({max(A[i][0],B[j][0]),A[i][1]});
                i++;
            }
            else{
                res.push_back({max(A[i][0],B[j][0]),B[j][1]});
                j++;
            }
        }
        return res;
    }
};