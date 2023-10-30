//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	void recSolve(vector<int> &arr,int s,int e,long long int &maxi){
	    if(e >= arr.size()){
	        return ;
	    }
	    
	    //ek case solve
	    long long int product = 1;
	    for(int i=s;i<=e;i++){
	        product *= arr[i];
	    }
	    maxi = max (maxi,product);
	    
	    recSolve(arr,s,e+1,maxi);
	}
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long int maxi = INT_MIN;
	    for(int s = 0;s<arr.size();s++){
	        int e = s;
	        recSolve(arr,s,e,maxi);
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends