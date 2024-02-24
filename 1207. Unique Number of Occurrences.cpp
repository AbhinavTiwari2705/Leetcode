class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mep;

        for(auto i: arr){
            mep[i]++;
        }
        
        unordered_set<int> s;

        for(auto& pair : mep){
            if(s.find(pair.second) != s.end()) 
                return false;
            s.insert(pair.second); 
        }

        return true;
    }
};
