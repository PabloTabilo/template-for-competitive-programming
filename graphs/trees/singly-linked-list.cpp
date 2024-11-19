#include <iostream>
#include <vector>

using namespace std;

 // * Definition for singly-linked list.
struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
 };
 
 class LinkedList
 {
    Node * head = nullptr;
    public:
        
        LinkedList():head(nullptr){}
        
        void insert_front(int val){
            Node * n = new Node(val);
            if(head == nullptr){
                head = n;
            }else{
                n->next = head;
                head = n;
            }
        }
        
        void insert_after(int val){
            Node * n = new Node(val);
            Node * after = head;
            while(after!=nullptr && after->val!=val){
                after = after->next;
            }
            
            if(after->next){
                n->next = after->next;
            }
            
            after->next = n;
        }
        
        void insert(int val){
            Node * n = new Node(val);
            if(head){
                Node * t = head;
                while(t->next!=nullptr){
                    t=t->next;
                }
                t->next = n; 
            }else{
                head = n;
            }
            
        }
        
        bool search(int val){
            Node * t = head;
            while(t!=nullptr){
                if(t->val == val){
                    return true;
                }
                t = t->next;
            }
            return false;
        }
        
        void loop(){
            Node * c = head;
            cout<<"{ ";
            while(c!=NULL){
                cout<<c->val<<" ";
                c = c->next;
            }
            cout<<"}"<<endl;
        }
 };

int main()
{
    LinkedList l;
    vector<int> v = {5,2,9,11,3,24};
    for(int i=0;i<v.size();i++){
        l.insert(v[i]);
    }
    // loop me
    l.loop();
    
    // insert a node post node with val 9
    
    // eliminate node with val 11

    // insertar en head
    
    // eliminar head

    return 0;
}

