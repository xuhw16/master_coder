/*The idea is based on finding the longest palindrome in O(n^2) time, which is to expand around each character to check for the longest even 
and odd sized palindrome.

The DP statement can be expressed as: dp[j] = min(dp[j], dp[j-i-1] + 1), for all i such that dp[i ... j] is a palindrome. Thus, we can go through 
the string from left to right, and then continuously update future positions based on the longest palindrome we can find at current character.

For example, if we have string s = aaaba, and we are at index 1, we can expand to left and right, and see that the longest odd palindrome centered
 at 1 is 3, so we update dp[3]. We also see the longest even is aa, so we update dp[2]. This is better than simply calculating the "isPalindrome" matrix,
 because we skip over unnecessary checks (if s[i ... j] is not a palindrome, then s[i-1 ... j+1] is also not a palindrome, etc.)

In my code, I need to increase indexing into dp by 1, since I define the dp array to mean min cuts required for up to and including jth character.
 Based on this, I set dp[0] = -1 because it saves us the trouble of having to check if we are at the 0th character, for which a palindrome would require 0 cuts. 
 Instead, we add 1 as usual, and -1 + 1 = 0, so it works out.
*/
class Solution {
public:
    
    int minCut(string s) {
        int n=s.size();
        int temp=0;;
        if(n<=0) return 0;
        vector<int> dp(n+1,0);
        for(int i=0;i<n+1;i++)
            dp[i]=i-1;
        for(int i=0;i<n;i++){
            for(int j=0;i-j>=0&&i+j<n&&s[i-j]==s[i+j];j++)
                dp[i+j+1]=min(dp[i+j+1],dp[i-j]+1);
            for(int j=0;i-j-1>=0&&i+j<n&&s[i-j-1]==s[i+j];j++)
                dp[i+j+1]=min(dp[i+j+1],dp[i-j-1]+1);
        }
        return dp[n];
    }
};