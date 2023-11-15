//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    // void count(int n){
    //     if(n==0){
    //         return;
    //     }
    //     int digit = n % 10;
        
    //     if()
        
    // }
    int evenlyDivides(int N){
        //code here
        int count = 0;
        int n = N;
        while(n != 0)
        {
            int lastNum = n % 10; // 2
            
            if(lastNum !=0 && N%lastNum == 0)
            {
                count ++;
            }
            
            n = n / 10;
        }
        return count;
        
    
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
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends