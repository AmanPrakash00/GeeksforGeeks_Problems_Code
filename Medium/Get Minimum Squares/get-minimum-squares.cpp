//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int bottomup(int n){
        vector<int> dp(n+1,0);
        //base case
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int ans = INT_MAX;
            int end = sqrt(i);
            for(int j = 1;j<=end;j++){
                int square = j*j;
                int numofPerfect = 1 + dp[i-square];
                if(numofPerfect<ans){
                    ans = numofPerfect;
                }
            }
            dp[i] = ans;
        }
        return dp[n];
    }
	int MinSquares(int n)
	{
	    // Code here
	    
	    return bottomup(n)-1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends