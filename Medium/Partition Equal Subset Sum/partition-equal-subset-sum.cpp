//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool recSolve(int arr[],int index ,int target){
        if(index < 0){
            return false;
        }
        if(target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }
        //exclusion 
        bool ans1 = recSolve(arr,index-1,target);
        bool ans2 = recSolve(arr,index-1,target - arr[index]);
        
        bool ans = (ans1 || ans2);
        
        return ans;
    }
    bool topdown(int arr[],int index ,int target,vector<vector<int>> &dp){
        if(index < 0){
            return false;
        }
        if(target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        //exclusion 
        bool ans1 = topdown(arr,index-1,target,dp);
        bool ans2 = topdown(arr,index-1,target - arr[index],dp);
        
        dp[index][target] = (ans1 || ans2);
        
        return dp[index][target];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        
        int target = sum/2;
        
        if(sum%2 != 0){
            return false;
        }
        
        // bool ans = recSolve(arr,N-1,target);
        // return ans;
        
        vector<vector<int>> dp (N+1,vector<int> (target+1,-1));
        return topdown(arr,N-1,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends