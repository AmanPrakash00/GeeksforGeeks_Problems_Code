#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        //code here
        
        int total = (n) * (n +1)/ 2;
        int sum = 0;
        int diff = 0;
        for (int i = 0; i < n-1; i++){
            sum = sum + array[i];
        }
        diff = total - sum;
        return diff;
        
    }
};