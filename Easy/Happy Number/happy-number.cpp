//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    int recSolve(int n){
        if(n == 0){
            return 0;
        }

        int rem = n%10;
        int square = rem * rem;

        int ans = recSolve(n/10);

        int total = ans + square;

        return total;
    }
    int isHappy(int n) {
        unordered_set<int> set;
        while( n != 1 && !set.count(n)){
            set.insert(n);
            n = recSolve(n);
        }
        if(n==1){
            return true;
        }else{
            return false;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends