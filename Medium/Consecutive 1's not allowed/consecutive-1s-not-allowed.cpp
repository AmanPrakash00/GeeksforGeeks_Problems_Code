//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    ll C=1e9+7;
	ll solve(int n,vector<ll>&dp) {
	    if(n==0){
	        return 0;
	    }
	    if(n==1){
	        return 2;
	    }
	    ll solv = solve(n-1,dp)%C;
	    ll ans = (2*solv-dp[n])%C;
	    while(ans<0){
	        ans+=C;
	    }
	    return ans%C;
	}
	ll countStrings(int n) {
	    if(n==1){
	        return 2;
	    }
	    else if(n==2){
	        return 3;
	    }
	    vector<ll>dp(n+1,0);
	    dp[1]=dp[2]=dp[3]=1;
	    for(int i=4;i<=n;i++){
	        dp[i] = (dp[i-1]+dp[i-2])%C;
	    }
	    return solve(n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends