#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
class Stack {
private:
    Node* top;
public:
    Stack(){
        top = nullptr;
    }
    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout<< value << " pushed into stack\n";
    }
    void pop(){
       if(top == nullptr){
        cout << "Stack Underflow\n";
        return;
       }
       Node* temp = top;
       cout << top->data << " popped from stack\n";
       top = top->next;
       delete temp;
    }
    void peek(){
        if(top == nullptr){ 
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    void display(){
        if (top == nullptr){
            
        }
    }

}