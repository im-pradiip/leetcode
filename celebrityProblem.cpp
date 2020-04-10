#include <bits/stdc++.h> 
using namespace std;
//geeksforgeeksproblem leetcode ques available for premium account
bool celebrityCheck(int i,int j,vector<vector<int> >nums){
    return nums[i][j];
}
int celebrityProblem(vector<vector<int> > nums){
    //using two pointer algorithm
    int start=0;
    int end=nums[0].size();
    while(start<end){
        if(celebrityCheck(start,end,nums))
            start++;
        else
            end--;
    }

    for(int i=0;i<nums[0].size();i++){
        if(i!=start&&celebrityCheck(start,i,nums)||!celebrityCheck(i,start,nums))
            return -1;
    }
    return start;
}
 int main(){
     int t;
     cout<<"testcase";
     cin>>t;
     while(t--){
         int person;
         cin>>person;
         vector<vector<int> >nums;
         vector<int>res;
         int num;
         for(int i=0;i<person;i++){
             for(int j=0;j<person;j++){
                 cin>>num;
                 res.push_back(num);
             }
             nums.push_back(res);
         }
         cout<<celebrityProblem(nums);
         cout<<endl;
     }
     return 0;
 }