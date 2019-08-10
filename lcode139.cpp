class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set_p;
        for(auto &it:wordDict)set_p.insert(it);
        vector<bool> dp(s.size()+1,false);;
        dp[0]=true;
        for(int i=0;i<s.size();i++)
        {
            if(!dp[i])continue;
            string tmp;
            for(int j=i;j<s.size();j++){
                tmp+=s[j];
                if(set_p.count(tmp))
                    dp[j+1]=true;
            }
        }
        return dp[s.size()];
    }
};