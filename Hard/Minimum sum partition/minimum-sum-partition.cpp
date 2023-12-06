//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

  public:
    
    int ans=INT_MAX;
    void solve(int arr[], int n, int sum, int subsetsum, vector<vector<int>> &dp){
        if(dp[subsetsum][n]!=-1){
            return;
        }
        if(n<=0){
            return;
        }
        ans=min(ans,abs(sum-2*subsetsum));
        solve(arr,n-1,sum,subsetsum+arr[n-1],dp);
        solve(arr,n-1,sum,subsetsum,dp);
        dp[subsetsum][n]=1;
    }
	int minDifference(int arr[], int n)  { 
	   int sum=0;
	   for(int i=0;i<n;i++){
	       sum+=arr[i];
	   }
	   vector<vector<int>> dp(sum+1,vector<int>(n+1,-1));
	   solve(arr, n, sum,0,dp);
	   return ans;
	}  
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends