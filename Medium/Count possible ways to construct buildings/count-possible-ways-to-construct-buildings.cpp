//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
    int TotalWays(int N)
    {
        long long first = 1,num1,num2,num3;
        long long second = 2;
        if(N==1)
        {
            return 4;
        }
        for(int i=2;i<=N;i++)
        {
            num1 = (first%mod + second%mod)%mod;
            first = second;
            second = num1;
            
        }
        return (second%mod * second%mod);
    }


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends