//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getShortestLength(vector<int> &v){
        int len = max({v[0], v[1], v[2]}) - min({v[0], v[1], v[2]}) + 1;
        return len;
    }
    
    int smallestSubstring(string s) {
        int len = INT_MAX;
        
        vector<int> v(3,-1);
        
        int n = s.length();
        
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='2') v[s[i]-'0']=i;
            
            if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1){ 
                len = min(len, getShortestLength(v));
            }
        }
        
        return len==INT_MAX ? -1 : len;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends