/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> mat=binaryMatrix.dimensions();//getting dimensions through given function
        //by applying hint 2
        int row=mat[0];//number of rows in a binaryMatrix
        int col=mat[0];//number of column in a binaryMatrix
        if(row==0||col==0)
            return -1;
        int i=0;
        int j=col-1;
        int answer=-1;
        //starting from righttopmost row if it is one we move towards left as we have not check any value
        //for that particular column and if value =0 we have to check for that column downside;
        while(i<row&&j>-1){
            if(binaryMatrix.get(i,j)==1){
                answer=j;
                j--;
            }
            else{
                i++;
            }
        }
        return answer;
    }
};