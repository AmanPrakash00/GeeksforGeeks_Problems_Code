//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
int knapSack(int W, int wt[], int val[], int N) 
    { 
       // Your code here
        int dp[N + 1][W + 1];
        
        //Set all elements in first column to zero
        for (int i = 0; i <= N; ++i)
        {
            dp[i][0] = 0;
        }
        //set all elements in first row to zero
        for (int i = 0; i <= W; ++i)
        {
            dp[0][i] = 0;
        }
        //Solve the problem by Dynamic Programming
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= W; ++j)
            {   
                if (wt[i - 1] <= j)
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        //return the answer.
        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends