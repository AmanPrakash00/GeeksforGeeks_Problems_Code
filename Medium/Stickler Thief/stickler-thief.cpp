//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int recSolve(int arr[],int index){
        if(index < 0){
            return 0;
        }
        //inclusion 
        int include = arr[index] + recSolve(arr,index - 2);
        //exclusion
        int exclude = 0 + recSolve(arr,index - 1);
        
        int ans = max(include , exclude);
        return ans;
    }
    
    int topdown(int arr[],int index,vector<int> &dp){
        if(index < 0){
            return 0;
        }
        if(dp[index] != INT_MIN){
            return dp[index];
        }
        //inclusion 
        int include = arr[index] + topdown(arr,index - 2,dp);
        //exclusion
        int exclude = 0 + topdown(arr,index - 1,dp);
        
        dp[index] = max(include , exclude);
        return dp[index];
    }
    
    int bo
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int index = n - 1;
        vector<int> dp(n+1,INT_MIN);
        int ans = topdown(arr,index,dp);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends