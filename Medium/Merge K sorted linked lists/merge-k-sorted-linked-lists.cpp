//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    void insertAtTail(vector<int>&v,Node* &head,Node*&tail){
        for(int i = 0;i<v.size();i++){
            if(head == NULL){
                Node* temp = new Node(v[i]);
                head = temp;
                tail = temp;
            }else{
                Node* temp = new Node(v[i]);
                tail -> next = temp;
                tail = temp;
            }
        }
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           vector<int> v;
        for(int i = 0;i<K;i++){
            Node* tempHead = arr[i];
            while(tempHead != NULL){
                v.push_back(tempHead->data);
                tempHead = tempHead -> next;
            }
        }
        sort(v.begin(),v.end());
        Node* head = NULL;
        Node* tail = NULL;
        insertAtTail(v,head,tail);
        return head;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends