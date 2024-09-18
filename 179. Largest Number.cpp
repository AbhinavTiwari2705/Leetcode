class Solution {
public:
    static bool comp(string&a,string&b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> sor;

        for(int i:nums){
            sor.push_back(to_string(i));
        }

        sort(sor.begin(),sor.end(),comp);

        if(sor[0]=="0") return "0";

        string ans;

        for(auto i:sor){
            ans+=i;
        }
        return ans;

    }
};
