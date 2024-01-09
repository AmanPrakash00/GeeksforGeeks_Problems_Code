//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> g;
    void insertHeap(int &x)
    {
        if(s.empty()!=false || x < s.top()){
            s.push(x);
        }else{
            g.push(x);
        }
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(s.size()==g.size()){
            return;
        }else if(s.size()>g.size() && (s.size()-g.size())>1){
            g.push(s.top());
            s.pop();
        }else if(s.size()<g.size()){
            s.push(g.top());
            g.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(s.size()!=g.size()){
            return s.top();
        }else{
            return (s.top()+g.top())/2.0;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends