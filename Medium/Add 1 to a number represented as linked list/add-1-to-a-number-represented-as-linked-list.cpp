//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* &prev,Node* &curr){
        if(curr == NULL){
            return prev;
        }
        
        Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        return reverse(prev,curr);
        
    }
    void insertAtTail(Node* &newHead,Node*&newTail,int data){
        if(newHead == NULL){
            Node* temp = new Node(data);
            newHead = temp ;
            newTail = temp ;
        }else{
            Node* temp = new Node(data);
            newTail -> next = temp;
            newTail = temp;
        }
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* prev = NULL;
        Node* curr = head;
        head = reverse(prev,curr);
        Node* newHead = NULL;
        Node* newTail = NULL;
        int carry = 1;
        Node* temp = head;
        while(temp != NULL){
            //curr data
            int data = temp -> data;
            // total sum
            int tsum = data + carry;
            
            //last digit
            int digit = tsum%10;
            insertAtTail(newHead,newTail,digit);
            carry = tsum / 10;
            temp = temp -> next;
        }
        if(carry>0){
            insertAtTail(newHead,newTail,carry);
        }
        prev = NULL;
        curr = newHead;
        newHead = reverse(prev,curr);
        return newHead;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends