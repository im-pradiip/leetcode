// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start=0;
        int end=n;
        int mid;
        //here version is first starting bad inversion 
        //output is version number which we gave input
        //here n is total inversion good+bad
        //by using binary search we perform in logn times
        //if we find the bad inversion(mid) we have to check its previous one(mid-1) is also bad if bad then we             have to check in left part by making end=mid, if true then simply break and return mid 
        //if mid is not bad inversion then we make start as mid+1 as first bad inversion is in right part
        while(start<=end){
            mid=start+(end-start)/2;
            if(isBadVersion(mid)){
                if(isBadVersion(mid-1)==false)
                    break;
                else
                    end=mid;
            }
            else
                start=mid+1;
        }
        return mid;
    }
};