//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n) 
    {
        // Your code goes here
        for(int i=0;i<n;i++){
            if(1==a[i]){
                return i;
            }
        }
        return -1;
    }
};

