//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solveRec(int n ,int x,int y ,int z){
        if(n < 0){
            return INT_MIN;
        }
        
        if(n==0){
            return 0;
        }
        
        int ans1 = solveRec(n-x,x,y,z) + 1;
        int ans2 = solveRec(n-y,x,y,z) + 1;
        int ans3 = solveRec(n-z,x,y,z) + 1;
        
        int ans = max(ans1,max(ans2,ans3));
        return ans;
    }
    
    int topdown(int n,int x,int y,int z,vector<int> &dp){
        if(n < 0){
            return INT_MIN;
        }
        
        if(n==0){
            return 0;
        }
        //check if ans is exist
        if(dp[n] != INT_MIN){
            return dp[n];
        }
        int ans1 = topdown(n-x,x,y,z,dp) + 1;
        int ans2 = topdown(n-y,x,y,z,dp) + 1;
        int ans3 = topdown(n-z,x,y,z,dp) + 1;
        
        dp[n] = max(ans1,max(ans2,ans3));
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        // return solveRec(n,x,y,z);
        
        vector<int> dp(n+1,INT_MIN);
        int ans = topdown(n,x,y,z,dp);
        
        if(ans<0){
            return 0;
        }else{
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends