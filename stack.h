// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair


// STACK CLASS 
// ========================
// An Stack instance has 2 memebers. 
// - S_node -> struct that holds an array of event objects as well as a pointer to another s_node.
//           head -> pointer to the first node in the linear linked list
// 
// - This class uses a linear linked list of arrays as the data structure. It utilizes the principle
// of "last in, first out". The top index is used to keep track of the next available free space for 
// an event object. This means that no event exists at the top index. It is a space for an event to be
// set into. If removing, the top index must be carefully managed depending on its position. 

#ifndef STACK_H
#define STACK_H

#include "event.h"

struct s_node
{
  Event * events;
  s_node * next;
};

// Used for the array size for entries in the stack.
const int MAX = 4;

// Linear linked list of arrays implementation
class Stack
{
  public:
    Stack(void);
    ~Stack(void);


// METHODS 

// ----------------------------------------------------------------------------------------
// push - takes an event object as an argument and adds it to the top of the stack.  
//    Arguments -> event object
//        EXAMPLE 
//        Initialize queue ----   Stack stack; 
//        Call function    ----   int returns = stack.push(event);
//
// Returns-> 0 if any field in the object is set to nullptr
//           1 if it is the first time pushing an object to the stack
//           2 if a new s_node is created in order to make more space in the stack
//           3 if adding an object to an existing node
    int push(Event & _event);


// ----------------------------------------------------------------------------------------
// pop - removes the event that is at the top of the stack.  
//    Arguments -> event object into which the data will be copied. Should be a 
//                 new instance of an event without established data fields.
//        EXAMPLE 
//        Call function    ----   int returns = stack.pop(copy_of_top_event);

// Returns-> 0 if the stack is empty
//           1 if the pop removed a s_node
//           2 if the the current s_node remains intact and the top index was decremented
    int pop(Event & _event);


// ----------------------------------------------------------------------------------------
// peek - Fills the event argument with the data from the event at the top of the stack.
//        Leaves the stack unchanged.
//    Arguments -> event object into which the data will be copied. Should be a 
//                 new instance of an event without established data fields.
//        EXAMPLE 
//        Call function    ----   int returns = stack.peek(copy_of_top_event);
//
// Returns-> 0 if the list is empty
//           1 if the list is not empty
    int peek(Event & _event);


// ----------------------------------------------------------------------------------------
// display - displays all events stored in the stack using a wrapper function and a private recursive function
//     Arguments -> None
//        EXAMPLE 
//        Call function    ----   int returns = stack.display();
//
// Returns-> An integer count of the number of items in the list
    int display(void);


  private:
    int display(s_node * & head, int top_index);
    s_node * head;
    int top_index;
};

#endif


