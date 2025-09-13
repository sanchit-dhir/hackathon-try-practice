#include <iostream>
using namespace std;
//DOUBLY LINKLIST
class Node{
    public :
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
class doublell{
    public:
    Node* head;
    Node* tail;
    doublell(){
        head = nullptr;
        tail = nullptr;
    }
    void push_front(int data){
        Node* temp = new Node(data);
        if(head==nullptr){
            head = tail= temp;
        }else{
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
    }
    void push_back(int data){
        Node* temp = new Node(data);
        if(head==nullptr){
            head = tail= temp;
        }else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    void pop_front(){
        if(head==nullptr) return;
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    void pop_back(){
        if(head==nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    void insert(int data, int idx){
        if(idx==0) return push_front(data);
        Node* temp = head;
        int i = 0;
        while(temp){
            if(i==idx) break;
            temp = temp->next;
            i++;
        }
        if(i<idx) return push_back(data);
        Node* num = new Node(data);
        num->prev = temp->prev;
        num->next = temp;
        temp->prev->next = num;
        temp->prev = num;
    }
    void delete_By_Value(int key) {
        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Value " << key << " not found in list\n";
            return;
        }
        if (temp == head) {
            head = head->next;
            if (head) head->prev = NULL;
        }
        else if (temp == tail) {
            tail = tail->prev;
            if (tail) tail->next = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    void get_val(){
        int key;
        cout << "Enter the value of Node which you want to delete ";
        cin >> key;
    }
    void print(){
        Node* temp= head;
        while(temp!=nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    // void fromTail(){
    //     Node* temp = tail;
    //     while(temp){
    //         cout<< temp->data << " ";
    //         temp = temp->prev;
    //     }
    // }
};
int main(){
    doublell ll;
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.print();
    cout << endl;
    cout << "List after Insertion: " << endl;
    ll.insert(4,3);
    ll.print();
    cout << endl;
    int key;
    cout << "\nEnter the value which you want to delete: ";
    cin >> key;
    ll.delete_By_Value(key);
    cout << "\nList after Deletion: " << endl;
    ll.print();
    return 0;
}