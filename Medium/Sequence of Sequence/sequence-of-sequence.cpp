//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[101][101];
    int fun(int n,int m)
    {
        if(n==0)
        {
            return 1;
        }
        if(m<n)
        {
            return 0;
        }
        if(t[m][n] != -1)
        {
            return t[m][n];
        }
        else 
        {
            return t[m][n] = fun(n-1,m/2) + fun(n,m-1);
        }
        
    }
    int numberSequence(int m, int n){
        
        memset(t,-1,sizeof(t));
        return fun(n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends