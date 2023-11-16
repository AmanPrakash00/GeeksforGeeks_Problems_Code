//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestCommonSubsequence(string &text1,string &text2){
        // vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        vector<int>curr(text2.size()+1,0);
        vector<int>next(text2.size()+1,0);
        for(int i = text1.size()-1;i>=0;i--){
            for(int j = text2.size()-1;j>=0;j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + next[j+1];
                }else{
                    ans = 0 + max(curr[j+1],next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestPalinSubseq(string A) {
        //code here
        string text1 = A;
        reverse(A.begin(),A.end());
        string text2 = A;
        
        return longestCommonSubsequence(text1,text2);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends