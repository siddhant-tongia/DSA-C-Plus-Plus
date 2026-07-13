#include<iostream>
#include<vector>
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

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;

        }
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){
        if(pos < 0){
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i=0 ; i<pos-1 ; i++){
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printll(){
        Node* temp = head;

        while(temp != NULL){
            cout<< temp->data << ",";
            temp = temp->next;
        }
    }
};
 
int main() {
    List myList;

    cout << "1. Testing push_front (Adding 10, then 20):" << endl;
    myList.push_front(10);
    myList.push_front(20);
    myList.printll(); 
    cout << "\n\n";

    cout << "2. Testing push_back (Adding 30, then 40 to the end):" << endl;
    myList.push_back(30);
    myList.push_back(40);
    myList.printll(); 
    cout << "\n\n";

    cout << "3. Testing insert (Adding 99 at Position 2):" << endl;
    myList.insert(99, 2);
    myList.printll(); 
    cout << "\n\n";

    cout << "4. Testing pop_front (Removing the first element):" << endl;
    myList.pop_front();
    myList.printll(); 
    cout << "\n\n";

    cout << "5. Testing pop_back (Removing the last element):" << endl;
    myList.pop_back();
    myList.printll(); 
    cout << "\n";

    return 0;
}