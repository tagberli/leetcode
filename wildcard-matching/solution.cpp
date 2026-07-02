class Solution {
public:
    // 0-star sub-problem
    bool isMatch0(string & s, string & p){
        if(s.size() != p.size()){
            return 0;
        }
        for(int i = 0; i < s.size(); i++){
            if('a' <= p[i] && p[i] <= 'z' && p[i] != s[i])
                return 0;
        }
        return 1;
    }
    bool isMatch(string s, string p) {
        int stars = 0;
        for(int i = 0; i < p.size(); i++) {
            if(p[i] == '*') {
                stars++;
            }
        }
        if(stars == 0){
            return isMatch0(s, p);
        }
        vector<vector<int>> m(p.size() + 1, vector<int>(s.size() + 1, 0));

        m[0][0] = (s[0] == p[0]) | (p[0] == '?') | (p[0] == '*');
        for(int i = 1; i <= p.size(); i++)
            m[i][0] = (p[i - 1] == '*') & m[i - 1][0]; 
        
        for(int i = 1; i <= p.size(); i++){
            for(int j = 1; j <= s.size(); j++){
                if(p[i - 1] == '*'){
                    m[i][j] = m[i - 1][j] | m[i][j - 1];
                }
                
                if(p[i - 1] == '?' || p[i - 1] == s[j - 1]){
                    m[i][j] = m[i - 1][j - 1];
                }
            }
        }
        return m[p.size()][s.size()];
    }
};