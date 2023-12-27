//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int> temp;
        
        int m=matrix.size();
        int n = matrix[0].size();
        
        //first part
        for(int j=0;j<n;j++)
        {
            int y = j;
            for(int x=0;y>-1 and x<m;x++,y--)
            {
                temp.push_back(matrix[x][y]);
            }
        }
        //second part
        for(int i=1;i<m;i++)
        {
            int x=i;
            for(int y=n-1;y>-1 and x<m;x++,y--)
            {
                temp.push_back(matrix[x][y]);
            }
        }
        
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends