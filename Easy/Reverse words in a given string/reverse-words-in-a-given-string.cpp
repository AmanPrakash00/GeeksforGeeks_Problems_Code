//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string output ="";
        string str = "";
        for(int i = 0;i<S.length();i++){
            if(S[i] == '.'){
                output.insert(0,str);
                str = "";
                output.insert(0,".");
            }else{
                str += S[i];
            }
        }
        output.insert(0,str);
        return output;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends