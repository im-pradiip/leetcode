class Solution {
public:
    static bool sortByVal( pair<char, int> a, 
                pair<char, int> b){
    return (a.second > b.second);} 
    string frequencySort(string s) {
        //Given a string, sort it in decreasing order based on the frequency of characters.
        map<char, int> _map; 
        for(char c:s){
            _map[c]++;
        }
        string str="";
         vector<pair<char,int>> vec;

	    // copy key-value pairs from the map to the vector
        map<char,int> :: iterator it2;
        for (it2=_map.begin(); it2!=_map.end(); it2++){
            vec.push_back(make_pair(it2->first, it2->second));
        }

	    // // sort the vector by increasing order of its pair's second value
        sort(vec.begin(), vec.end(), sortByVal); 

	    for (int i = 0; i < vec.size(); i++){
		    int temp=vec[i].second;
            while(temp--){
                str+=vec[i].first;
            }
	    }
        return str;
    }
};