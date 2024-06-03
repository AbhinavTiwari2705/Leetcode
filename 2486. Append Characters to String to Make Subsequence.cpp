class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int sl=s.size();
        int tl = t.size();
        int i=0,p=0;
        int cnt=0;
        while(i<sl){
            if(s[i]==t[p]){
                i++;
                p++;
                
            }
            else{
                i++;
                
            }
        }
            
        return abs(p-tl);
    }
};
