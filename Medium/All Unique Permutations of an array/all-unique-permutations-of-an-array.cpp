//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void permutations(vector<int>&arr,int i,set<vector<int>>&s){
        if(i>=arr.size()){
            s.insert(arr);
            return;
        }
        for(int j = i;j<arr.size();j++){
            swap(arr[i],arr[j]);
            permutations(arr,i+1,s);
            //backtrack
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> s;
        vector<vector<int>>ans;
        permutations(arr,0,s);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
        
        //         vector<vector<int>>ans;
        // sort(arr.begin(),arr.end());
        // do{
        //      ans.push_back(arr);
        // } while(next_permutation(arr.begin(),arr.end()));
        // return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends