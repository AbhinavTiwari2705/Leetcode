class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int N =arr.size();
        sort(arr.begin(),arr.end()); 
        string first = arr[0];
        string last = arr[N - 1]; 
        string res = "";

        

        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) break;
                res.push_back(first[i]);
        }
        return res;
    }
};
