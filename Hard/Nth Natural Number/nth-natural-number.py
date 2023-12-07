#User function Template for python3

class Solution:
    def findNth(self,N):
        #code here
          t = 1
          res = 0
          base = 9
          while(N>0):
            res = res+(N%base)*t
            N = N//base
            t = t*10
          return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t=int(input())
for i in range(0,t):
    n=int(input())
    obj=Solution()
    s=obj.findNth(n)
    print(s)
# } Driver Code Ends