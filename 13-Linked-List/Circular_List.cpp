#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){
        head = tail = NULL;
    }
    void InsertAtHead(int val){
        Node* newNode = new Node(val);
        if(tail == NULL){
            head = tail = newNode; 
            tail->next = head;
            return;
        }
        else{
            newNode->next = head;  // Here head can be replaced by tail->next.
            head = newNode;
            tail->next = head;
        }

    }
    void InsertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode; 
            tail->next = head;
            return;
        }
        else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteAtHead(){
        if(head == NULL){
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void DeleteAtTail(){
        if(head == NULL){
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* prev = head;
            Node* temp = tail;
            while(prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            
            temp->next = NULL;
            delete temp;
        }
    }

    void print(){
        if(head == NULL){
            return ;
        }
        cout<<head->data<<"->";
        
        Node* temp = head->next;

        while(temp != head){
            cout<<temp->data<<"->";
            temp = temp->next;
        }

        cout<<temp->data<<endl;
    }
};
 
int main()
{
    CircularList cll;
    cll.InsertAtHead(1);
    cll.InsertAtHead(2);
    cll.InsertAtHead(3);

    cll.InsertAtTail(2);
    cll.InsertAtTail(3);

    cll.DeleteAtHead();

    cll.DeleteAtTail();

    cll.print();
return 0;
}