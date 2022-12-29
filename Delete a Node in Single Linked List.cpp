#include<bits/stdc++.h>
using namespace std;
Node* deleteNode(Node *head,int x)
{
   if(x==1){
       Node* temp = head;
       head = head -> next;
       delete temp ;
       return head;
   }
   int cnt =1;
   Node* temp = head;
   while(cnt<x-1){
       temp = temp -> next;
       cnt++;
   }
   Node* deleteNode = temp -> next;
   temp -> next = temp -> next -> next;
   delete deleteNode;
   return head;
}