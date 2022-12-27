#include<bits/stdc++.h>
using namespace std;

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node* temp;
    Node* curr = head;
    while(curr!=NULL && curr -> next != NULL){
        if(curr-> data == curr ->next -> data){
            
            temp = curr -> next;
            curr -> next = curr -> next -> next;
            
            delete temp ;
        }else{
            curr = curr -> next;
        }
    }
    return head;
}