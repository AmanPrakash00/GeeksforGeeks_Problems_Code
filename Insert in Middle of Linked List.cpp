#include<bits/stdc++.h>
using namespace std;
Node* insertInMiddle(Node* head, int x)
{
	// Code here
	int cnt = 0;
	Node* temp = head;
	while(temp!= NULL){
	    cnt++;
	    temp = temp -> next;
	}
	int cntt = 0;
	Node* temp2 = head;
	if(cnt%2==0){
	    while(cntt<(cnt/2)-1){
	    temp2 = temp2 -> next; 
	    cntt++;
	    }
	    }else{
	while(cntt<cnt/2){
	    temp2 = temp2 -> next; 
	    cntt++;
	    
	}
	}
	Node* insertt = new Node(x);
	insertt->next = temp2 -> next;
	temp2 -> next = insertt;
	return head;
}