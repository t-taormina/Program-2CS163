// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair


// QUEUE CLASS 
// ========================
// An Queue instance has 1 member. 
// - Q_node -> struct that holds an event object as well as a pointer to another q_node.
//           rear -> pointer to the rear node in a circular linear linked list
// 
// - This class uses a circular linear linked list as its data structure. The rear represents 
// the back of the queue. The rear node holds a pointer that points to the "top" or front of 
// the queue. Nodes are enqueued at the rear and dequeued at the top.


#ifndef QUEUE_H
#define QUEUE_H

#include "event.h"

struct q_node
{
  Event event;
  q_node * next;
};

// Circular linked list implementation
class Queue 
{
  public:
    Queue(void);
    ~Queue(void);

// METHODS 

// ----------------------------------------------------------------------------------------
// enqueue - takes an event object as an argument and adds it to the queue.  
//    Arguments -> event object
//        EXAMPLE 
//        Initialize queue ----   Queue queue; 
//        Call function    ----   int returns = queue.enqueue(event);
//
/// Returns-> 0 if an item in the event is set to null
//            1 if an event is added to an empty list
//            2 if an event is added to a list with existing elements
    int enqueue(Event & event_to_add);


// ----------------------------------------------------------------------------------------
// dequeue - removes the event that is at the top or front of the queue.  
//    Arguments -> event object into which the data will be copied. Should be a 
//                 new instance of an event without established data fields.
//        EXAMPLE 
//        Call function    ----   int returns = queue.dequeue(copy_of_top_event);
//// Returns-> 0 if the list is empty
//           1 if removing an event results in an empty list
//           2 if removing an event leaves 1 or more events still in the list
    int dequeue(Event & event_removed);


// ----------------------------------------------------------------------------------------
// peek - Fills the event argument with the data from the event at the top of the queue.
//        Leaves the queue unchanged.
//    Arguments -> event object into which the data will be copied. Should be a 
//                 new instance of an event without established data fields.
//        EXAMPLE 
//        Call function    ----   int returns = queue.peek(copy_of_top_event);
//
// Returns-> 0 if the list is empty
//             1 if the list is not empty
    int peek(Event & next_event);


// ----------------------------------------------------------------------------------------
// display - displays all events stored in the queue using a wrapper function and a recursive function
//     Arguments -> None
//        EXAMPLE 
//        Call function    ----   int returns = queue.display();
//
// Returns-> An integer count of the number of items in the list
    int display(void);


  private:
    int display(q_node * current, q_node * end);
    q_node * rear;
};

#endif


