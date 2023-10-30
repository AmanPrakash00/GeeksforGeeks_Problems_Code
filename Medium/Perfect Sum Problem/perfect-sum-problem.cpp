//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int recSolve(int arr[],int n,int sum){
	    if(n<0 ){
	        if(sum == 0){
	            return 1;
	        }
	        return 0;
	    }
	    //exclusion
	    int ans1 = recSolve(arr,n-1,sum);
	    //inclusion
	    int ans2 = 0;
	    if(sum>=0){
	        ans2 = recSolve(arr,n-1,sum-arr[n]);
	    }
	    int ans = ans1 + ans2;
	    return ans;
	}
	int mod = 1e9+7;
	int topdown(int arr[],int n,int sum,vector<vector<int>> &dp){
	    if(n==0 ){
	        if(sum==0 && arr[0]==0) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            else return 0;
	    }
	    if(dp[n][sum] != -1){
	        return dp[n][sum];
	    }
	    //exclusion
	     int ans1 = topdown(arr,n-1,sum,dp);
	    //inclusion
	     int ans2 = 0;
	     if(arr[n]<=sum){
	        ans2 = topdown(arr,n-1,sum-arr[n],dp);
	     }
	    
	    dp[n][sum] = (ans1%mod + ans2%mod)%mod;
	    return dp[n][sum];
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // return recSolve(arr,n-1,sum);
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return topdown(arr,n-1,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends