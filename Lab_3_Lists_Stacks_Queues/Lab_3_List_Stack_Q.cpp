

// Lab_2:
// Objective: Experiment with Lists, Stack, and Queue as follows:
// Assignmnet:
// Using the startup code, implement the following:
// 1-Create List L1 of 10 elements, e.g. L1 = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10; 
// 2-Insert a known value at every other element, such as:  1,100, 2, 200, 3,300, 4,400, ... 10,1000;
// 3-Create another List L2, and extract the inserted elements into this list: i.e. L1 should go back to the original list, L2 should be: 100, 200, 300, ... 1000
// 4-Create a Queue Q1 by extracting L1, and inserting L2 elements: i.e. Q should start with: 1,2,3, ... 10, and (100, 200 ... 1000) will be inserted 
// 5-Create a Stack S1 which by inserting all elements of Q, i.e. 1,2,3, ... 1000
// 6-Pop out all elements of the Stack, i.e. should end up with an empty stack
// 7-Verify the functionality and capture the results in a report form.
//


#include "List.h"
#include "Vector.h"

#include <stdlib.h>
#include <vector>
#include <iostream>



using namespace std;

static const int NUMS_PER_LINE = 14;


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
private:
    List<Object> theList;
};





int main()
{
    int i;
    const int N = 20;
    Vector<List<int>> arr(N);

    List<int> lst1;
    Stack<int> stk1;

    cout << "start" << endl;

    // create the list array as a starting point:
    for (i = N - 1; i >= 0; --i)
    {
        lst1.push_front(i);
    }


    // Stack to be created per the above assignment requirment
    for (i = N - 1; i >= 0; --i)
    {
        stk1.push(i);
        cout << stk1.top() << " " << endl;
    }

   
    while (!stk1.isEmpty())
    {
        cout << stk1.top() << endl;
        stk1.pop(i);
    }

    // Queue, to be created per the above assignment requirment
    //
    //


    return 0;
}
