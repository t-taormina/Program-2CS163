// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair


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
    int enqueue(Event & event_to_add);
    int dequeue(Event & event_removed);
    int peek(Event & next_event);
    int display(void);

  private:
    int display(q_node * current, q_node * end);
    q_node * rear;
};

#endif


