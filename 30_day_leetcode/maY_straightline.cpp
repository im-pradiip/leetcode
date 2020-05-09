class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)
            return true;
        float m;
        float x2=coordinates[1][0];
        float x1=coordinates[0][0];
        float y2=coordinates[1][1];
        float y1=coordinates[0][1];
        m=(y2-y1)/(x2-x1);
        //if slope of every two consecutive points are same then these points form a striaght line
        for(int i=2;i<coordinates.size()-1;i+=2){
            x2=coordinates[i+1][0];
            x1=coordinates[i][0];
            y2=coordinates[i+1][1];
            y1=coordinates[i][1];
            float temp_slope=(y2-y1)/(x2-x1);
            cout<<temp_slope<<" ";
            if(temp_slope!=m)
                return false;
        }
        return true;
    }
};