//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long int>sum,maxi(n);
        sum.push_back(a[0]);
        for(long long int i=1;i<n;++i)sum.push_back(sum.back()+a[i]);
        maxi[n-1]=sum[n-1];
        for(long long int i=n-2;i>=0;--i){
            maxi[i]=max(maxi[i+1],sum[i]);
        }
        
        long long int ans=-1e30;
        --k;
        for(int i=k;i<n;++i){
            long long int possible=maxi[i];
            if(i>k)possible-=sum[i-k-1];
            ans=max(ans,possible);
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends