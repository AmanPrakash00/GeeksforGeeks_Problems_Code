//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(int arr[], int n, int k) {
	    // code here
	    for(int i=0;i<=n;i++){
	        if(k==arr[i]){
	            return i+1;
	        }
	    }
	    return -1;
	}
};

