// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair

#include "queue.h"


// Default constructor
Queue::Queue() : rear(nullptr) {}

// Deconstructor
Queue::~Queue()
{
  if (!rear)
    return;
  if (rear == rear->next)
  {
    delete rear;
    rear = nullptr;
    return;
  }

  q_node * temp = rear;
  while (rear)
  {
    temp = rear->next;
    delete rear;
    rear = temp;
  }
  return;
}

// Adds an event to the queue
// Returns-> 0 if an item in the event is set to null
//           1 if an event is added to an empty list
//           2 if an event is added to a list with existing elements
int Queue::enqueue(Event & event_to_add)
{
  int success = 0;
  if(!rear)
  {
    rear = new q_node;
    rear->event.copy_event(event_to_add);
    rear->next = rear;
    return 1;
  }

  q_node * temp = rear->next; // holds head
  rear->next = new q_node; // extends list at the rear
  rear = rear->next; // reestablish rear pointer
  rear->event.copy_event(event_to_add); // copy data
  rear->next = temp; // reconnects to the head
  return 2;
}

// Removes the event at the top of the list
// Returns-> 0 if the list is empty
//           1 if removing an event results in an empty list
//           2 if removing an event leaves 1 or more events still in the list
int Queue::dequeue(Event & event_removed)
{
  int success = 0;
  if (!rear)
    return 0;

  if (rear == rear->next)
  {
    event_removed.copy_event(rear->event);
    delete rear;
    rear = nullptr;
    return 1;
  }
  
  q_node * temp = rear->next->next;
  event_removed.copy_event(rear->next->event);
  delete rear->next;
  rear->next = temp;
  return 2;
}

// Creates a copy of the event that is at the top of the queue using an event object passed by reference
// Returns-> 0 if the list is empty
//           1 if the list is not empty
int Queue::peek(Event & next_event)
{
  if (!rear)
   return 0;

  next_event.copy_event(rear->next->event);
  return 1;
}

// Wrapper function to display all objects stored in the queue recursively
// Returns-> the number of items in the queue
int Queue::display(void)
{ 
  // Empty list
  if (!rear)
    return 0;
  q_node * end = rear;
  return 1 + display(rear->next, end);
}

// Recursive function to display all objects in the queue
// Returns-> the number of items in the queue
int Queue::display(q_node * current, q_node * end)
{
  // Base case
  if (current == end)
  {
    current->event.display();
    return 0;
  }

  current->event.display();
  return 1 + display(current->next, end);
}
