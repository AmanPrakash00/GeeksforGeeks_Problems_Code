//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    int prevTerm = 0, currentTerm = 1;

        // Iterate through the sequence to find the nth term
            for (int i = 1; i <= n; ++i) {
                // Update terms using the Fibonacci recurrence relation
                int temp = currentTerm;
                currentTerm = (prevTerm + currentTerm) % (1000000007);
                prevTerm = temp;
            }
    
            // Return the calculated nth term
            return currentTerm;
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
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends