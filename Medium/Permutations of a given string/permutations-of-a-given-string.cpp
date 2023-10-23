//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    unordered_map<string,int> m;
	    void solve(string &str,int i,vector<string> &ans ){
        if(i>=str.length()){
            if(m.find(str) != m.end()){
                return;
            }else{
                ans.push_back(str);
                m[str]++;
            }
            return;
        }
        
        
        for(int j = i;j<str.length();j++){
            //swap
            swap(str[i],str[j]);
            //recursive
            solve(str,i+1,ans);
            //backtrack
            swap(str[i],str[j]);
        }
    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		     int i = 0;
        
        vector<string> ans;
        solve(S,i,ans);
        sort(ans.begin(),ans.end());
        return ans;
		}
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends