//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        string s = S;
        int k = K;
        deque<char>dq;
         int n=s.length();
         for(int i=0;i<n;i++){
            while(!dq.empty()&& dq.back()>s[i] && k>0){
                if(dq.back()!='0')
                k--;
                dq.pop_back();
            }
            dq.push_back(s[i]);
            
            
         }
        while(k-- && !dq.empty()){
            dq.pop_back();
        }
        while(!dq.empty() &&  dq.front()=='0')dq.pop_front();
        if(dq.size()==0) return "0";
         string ans;
         for(auto &x:dq){
             ans.push_back(x);
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends