#include <iostream>
#include <vector>

using namespace std;

// reference of this definition:
// https://leetcode.com/problems/reverse-linked-list-ii/description/

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
}; 

void loopme(ListNode * h){
    cout<<endl<<"{ ";
    while(h!=nullptr){
	cout<<h->val<<" ";
	h=h->next;
    }
    cout<<"}"<<endl;
}

int main()
{
    ListNode * head = nullptr;
    vector<int> v = {5,2,9,11,3,24};
    for(int i=0;i<v.size();i++){
	ListNode * n = new ListNode(v[i]);
	if(!head){
	    head = n;
	}else{
	    n->next=head;
	    head=n;
	}
    }
    // loop me
    loopme(head);    
    return 0;
}

