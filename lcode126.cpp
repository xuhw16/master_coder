class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int n=wordList.size();
        unordered_set<string> st1;
        for(auto &it:wordList)st1.insert(it);
        queue<vector<string>> qs;
        qs.push({beginWord});
        int level=1;
        int minlevel=2147438647;
        vector<string> erastring;
        while(!qs.empty())
        {
            vector<string> path=qs.front();
            qs.pop();
            int npsize=path.size();
            if(npsize>minlevel)
                    break;
            if(npsize>level)
            {
              
                if(npsize>minlevel)
                    break;
                else
                    level=npsize;
                 for(auto &it:erastring)st1.erase(it);
                  erastring.clear();
            }
            string last=path.back();
            int m=last.size();
            for(int i=0;i<m;i++)
            {
                char ctemp=last[i];
                for(char j='a';j<='z';j++)
                {
                    last[i]=j;
                    if(st1.find(last)!=st1.end())
                    {
                        vector<string> newpath=path;
                        newpath.push_back(last);
                        if(last==endWord)
                        {
                            res.push_back(newpath);
                            minlevel=level;
                        }
                        else
                        {
                            qs.push(newpath);
                            erastring.push_back(last);
                        }
                    }
                }
                last[i]=ctemp;
            }    
        }
        return res;
    }
};