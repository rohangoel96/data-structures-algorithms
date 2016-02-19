#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
  friend class linkedList;

  private:
    int key;
    Node* next;

  public:
    Node(void):next(NULL){}
    Node(int key):key(key),next(NULL){};
    Node(int key, Node* next):key(key),next(next){};

    int getKey(void){
      return key;
    }

    Node* getNext(){
      return next;
    }

    void setNext(Node* temp){
      next = temp;
    }
};


class LinkedList
{
  private:
    Node *head;

  public:
    LinkedList(void):head(NULL){};
    
    LinkedList(int value){
      head = new Node(value);
    }

    void push(int value){
      
      if (head!=NULL)
      {
        Node* temp = new Node(value,head);
        head = temp;
      }
      else{
        head = new Node(value);
      }
    }

    void append(int value){
      if (head!=NULL)
      {
        Node* temp = new Node(value);
        Node* iter = head;

        while(iter->getNext()!=NULL){
          iter = iter->getNext();
        }
        iter->setNext(temp);
      }
      else{ 
        this->push(value);
      }
    }

    void insert(int value, int index){
      if (head!=NULL)
      {
        Node *iter = head;
        int position = 0;

        if (index==0)
        {
          this->push(value);
        }
        else{

          while(position<index-1){
            iter = iter->getNext();
            position++;
          }

          if (iter->getNext()==NULL)
          {
            cout<<"Give an index <= the list length"<<endl;
          }
          else{
            Node *temp = new Node(value,iter->getNext());
            iter->setNext(temp);
          }
        }
      }
      else cout<<"List is empty"<<endl;
    }


    Node* pop(void){

      if (head!=NULL)
      {
        Node* temp = head;
        head = head->getNext();
        return temp;
      }
      else{
        cout<<"List is already empty!!"<<endl;
        return NULL;
      }
    }

    Node* remove(int index){
      if (head!=NULL)
      {
        Node *iter = head;
        int position = 0;

        if (index==0)
        {
          this->pop();
        }
        else{

          while(position<index-1){
            iter = iter->getNext();
            position++;
          }

          if (iter->getNext()==NULL)
          {
            cout<<"Give an index <= the list length"<<endl;
            return NULL;
          }
          else{
            Node *temp = iter->getNext();
            iter->setNext(iter->getNext()->getNext());
            return temp;
          }
        }
      }
      else {
        cout<<"List is empty"<<endl;
        return NULL;
      }

    }


    void reverseList(void){
      Node* iter = head;
      Node* prev = NULL;
      
      if (head!=NULL)
      {
        while(iter!=NULL){
          Node* temp = iter->getNext();
          iter->setNext(prev);
          prev = iter;
          iter = temp;
        }

        head = prev;
      }

    }

    void printList(void){
      Node* temp = head;

      if (temp==NULL){cout<<"Empty List"<<endl; return;}

      cout<<"Linked List : ";

      while(temp!=NULL){
        cout<<temp->getKey()<<" ";
        temp = temp->getNext();
      }

      cout<<endl;

    }

    void printReverse(Node* head){
      if (head->getNext()!=NULL)
      {
        printReverse(head->getNext());
      }

      cout << head->getKey()<<" ";

    }



};



int main(int argc, const char * argv[])
{

    Node* temp;
    /* Create an empty list */
    // LinkedList list1;
    // cout << "Created an empty list named list1." << endl;
    // list1.printList();
    
    // cout << "--- Pushed 5 6" << endl;
    // list1.push(5);
    // list1.push(6);
    // list1.printList();
    // cout << "--- Pop" << endl;
    // list1.pop();
    // list1.printList();
    // cout << "--- Pop" << endl;
    // list1.pop();
    // list1.printList();
    // cout << "--- Pop" << endl;
    // list1.pop();
    // list1.printList();
    // cout << "--- Pushed 1" << endl;
    // list1.push(1);
    // list1.printList();

    // cout<<endl;

    /* Create a list with only one Node */
    LinkedList list2(10);
    cout << "--- Created a list with only one Node." << endl;
    list2.printList();
    
    // cout << "--- Pushed 20 30 40" << endl;
    // list2.push(20);
    // list2.push(30);
    // list2.push(40);
    // list2.printList();
    // cout << "--- Pop twice" << endl;
    // list2.pop();
    // list2.pop();
    // list2.printList();
    // cout << "--- Pop twice" << endl;
    // list2.pop();
    // list2.pop();
    // list2.printList();
    // cout << "--- Pop again" << endl;
    // list2.pop();
    // list2.printList();
    cout << "--- Appended 20 30 40" << endl;
    list2.append(20);
    list2.append(30);
    list2.append(40);
    list2.printList();
    // cout << "--- Inserted 100 at index 0" << endl;
    // list2.insert(100,0);
    // list2.printList();
    // cout << "--- Inserted 200 at index 3" << endl;
    // list2.insert(200,3);
    // list2.printList();
    // cout << "--- Inserted 300 at index 5" << endl;
    // list2.insert(300,5);
    // list2.printList();
    // cout << "--- Inserted 400 at index 7" << endl;
    // list2.insert(300,7);
    // list2.printList();
    // cout << "--- Delete at index 0" << endl;
    // temp = list2.remove(0);
    // list2.printList();
    // cout << "--- Delete at index 3" << endl;
    // temp = list2.remove(3);
    // list2.printList();
    // cout << "--- Delete at index 4" << endl;
    // temp = list2.remove(4);
    // list2.printList();
    // cout << "--- Delete at index 4" << endl;
    // temp = list2.remove(4);
    // list2.printList();

    // cout << "--- Print Reverse" << endl;
    // cout<<"Linked List : ";
    // list2.printReverse(list2.pop());
    // cout<<endl;


    cout << "--- Reverse List" << endl;
    list2.reverseList();
    list2.printList();

    return 0;
}