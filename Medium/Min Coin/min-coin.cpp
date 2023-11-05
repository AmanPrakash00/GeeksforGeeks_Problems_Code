//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int recSolve(vector<int>&nums,int amount){
        if(amount == 0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        int maxi = INT_MAX;
        for(int i=0;i<nums.size();i++){
           int  ans = recSolve(nums,amount-nums[i]);
           if(ans!=INT_MAX){
               maxi = min(ans+1,maxi);
           }
        }
        
        return maxi;
        
    }
    
    int bottomup(vector<int>& nums, int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;

        for(int i=1;i<=amount;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0 && dp[i-nums[j]] != INT_MAX){
                    int  ans = dp[i-nums[j]];
                    
                       dp[i] = min(ans+1,dp[i]);
                    
                }
            }
        }
       return  dp[amount];
    }
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int ans = bottomup(nums,amount);
        if(ans == INT_MAX){
            return -1;
        }else
            return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends