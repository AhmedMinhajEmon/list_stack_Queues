#include "List.h"
#include <stdlib.h>
#include <iostream>
#include<queue>

using namespace std;

template <typename Object>

class Stack
{
public:
    bool isEmpty() const
    {
        return theList.empty();
    }
    const Object& top() const
    {
        return theList.front();
    }
    void push(const Object& x)
    {
        theList.push_front(x);
    }

    void pop(Object& x)
    {
        x = theList.front(); theList.pop_front();
    }
    void Stackaddnprint() {                       //a function to add elements in the stack and the first 
                                                 // added element will be in the bottom
        if (theList.empty()) {
            cout << "Stack is empty" << endl;
        }
        cout <<" "<< theList.front() <<" ";
    }

private:
    List<Object> theList;
};


template <typename Object>
class Queue
{
public:
    bool isEmpty() const
    {
        return theList.empty();
    }
    const Object& getFront() const
    {
        return theList.front();
    }
    void enqueue(const Object& x)
    {
        theList.push_back(x);
    }
    void dequeue(Object& x)
    {
        x = theList.front(); theList.pop_front();
    }
    int size() {
        return theList.size();          //added funtion to get the size
    }
    
    
    void print() {
        for (int i = 0; i < theList.size(); i++)
        {   
                                                        // to print the Queue
            cout << theList.front()<<" ";
            theList.push_back(theList.front());
            theList.pop_front();
        }
     }
    int give_Q_member() {


        int x = theList.front();     //return the queue member it will help us to add elements in stack

        theList.push_back(theList.front());
        theList.pop_front();
        return x;

    }
private:
    List<Object> theList;
};




int main() {
    int i;

    const int N = 10;

    List<int>  L1;
    Stack<int> S1;
    Queue<int> Q1;
    List<int>::iterator node; 

    //Q1
    // create the list array as a starting point:
    for (i = N; i > 0; --i)
    {   
        L1.push_front(i);
    }

    // show L1 with an iterator
    cout << "Create List L1 of 10 elements:\nList L1 is: ";
    for (auto it = L1.begin(); it != L1.end(); ++it) { cout << *it << ' '; }



    //Q2
    node = L1.begin(); //Set the position to the head of List 1

    for (i = 1; i <= N; i++) {

        node++;
        L1.insert(node, i * 100);

    }

    cout << endl << "\n2-Insert a known value at every other element:\nList L1 after insertion is: ";
    for (auto it = L1.begin(); it != L1.end(); ++it) { cout << *it << ' '; }
    cout << endl;

    
    List<int> L2;
    int length = L1.size();
    node = L1.begin();
   

    while (node != L1.end()) {
        node++;
        L2.push_back(*node);
        cout << "Value to be deleted is " << *node << endl;
        node = L1.erase(node);
    }


    cout << endl << "\nTask 3\nList L1 after deletion is: ";
    for (auto it = L1.begin(); it != L1.end(); ++it) { cout << *it << ' '; }

    cout << endl << "\nList L2 after insertion is: ";
    for (auto it = L2.begin(); it != L2.end(); ++it) { cout << *it << ' '; }
    cout << endl;

    
    node = L1.begin();
    length = L1.size();                         
  
    for (i = 0; i < length; i++) {                      //adding 1..2....10 into aqueue
            Q1.enqueue(*node);
            node++;
    }
    cout << endl;
    cout << "Task-4" << endl;

    cout <<"After adding l1 to Queue(Q1): ";
    Q1.print();
    cout << endl;
    cout << endl;


    node = L2.begin();
    length = L2.size();

    for (i = 0; i < length; i++) {                  //adding 100...200..300
        Q1.enqueue(*node);
        node++;
    }
    cout << "After adding l2 to Queue(Q1): ";
    Q1.print();
    cout << endl;
    cout <<"\nTask-5" <<endl;
    cout << "Stack building with Queue" << endl;
    cout << endl;
    for (int i = 0; i < Q1.size(); i++) {
        S1.push(Q1.give_Q_member());

        cout << " Adding ";
        S1.Stackaddnprint();
        cout << " to the Stack ";
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;


    for (int i = 0; i < Q1.size(); i++) {
        int x = S1.top();
        cout << "Poping the current top " << x << "  from the stack" << endl;   //poping elements 
                                                                        //first in last out
        S1.pop(x);

    }

    cout << endl;

    S1.Stackaddnprint();  //empty stack


     
     

    

    return 0;
}