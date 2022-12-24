#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int start = 0;
        int end = n-1;
        int mid = (start + end )/2;
        while (start<= end){
            if(arr[mid] == k){
                return mid;
            }
            if(k>arr[mid]){
                //right search
                start = mid +1;
            }
            else{
                end = mid -1;
            }
            mid = (start + end )/2;
        }
        return -1;
    }
};