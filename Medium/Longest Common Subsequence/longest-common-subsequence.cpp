//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int bottomupSO(string &text1,string &text2){
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
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        string text1 = s1;
        string text2 = s2;
        return bottomupSO(text1,text2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends