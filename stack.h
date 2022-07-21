// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair

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
    int push(Event & _event);
    int pop(Event & _event);
    int peek(Event & _event);
    int display(void);

  private:
    int display(s_node * & head, int top_index);
    s_node * head;
    int top_index;
};

#endif


