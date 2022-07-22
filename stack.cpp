// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair

#include "stack.h"
#include <algorithm>


// Default constructor
Stack::Stack() : head(nullptr), top_index(0){}


// Deconstructor
Stack::~Stack() 
{
  if (!head)
    return;
  s_node * temp = head;
  while(head)
  {
    temp = head->next;
    delete [] head->events;
    delete head;
    head = temp;
  }
  return;
}


// Adds an object to the stack
// Returns-> 0 if any field in the object is set to nullptr
//           1 if it is the first time pushing an object to the stack
//           2 if a new s_node is created in order to make more space in the stack
//           3 if adding an object to an existing node
int Stack::push(Event & event)
{
  int success = 3;

  if (event.get_name() == nullptr || event.get_description() == nullptr || event.get_review() == nullptr)
    return 0;

  if (!head)
  {
    head = new s_node;
    head->events = new Event[MAX];
    success =  1;
  }

  if (top_index >= MAX)
  {
    s_node * temp = head;
    head = new s_node;
    head->events = new Event[MAX];
    head->next = temp;
    top_index = 0;
    success = 2;
  }

  head->events[top_index].copy_event(event);
  top_index++;
  return success;
}


// Used to retrieve the last event on the stack. 
// Returns-> 0 if the stack is empty
//           1 if the pop removed a s_node
//           2 if the the current s_node remains intact and the top index was decremented
int Stack::pop(Event & popped_event)
{
  // Empty stack
  if(!head)
    return 0;

  if(top_index <= 0)
  {
    if(!head->next)
      return 0;

    s_node *temp = head->next;
    delete [] head->events;
    delete head;
    head = temp;
    top_index = MAX;
  }

  popped_event.copy_event(head->events[top_index - 1]);
  head->events[top_index - 1].reset_event();
  top_index--;
  return 1;
}


// Retrieves the top event of the stack. Does not alter the stack.
// Returns-> 0 if the stack is empty
//           1 if the stack holds 1 event or more
int Stack::peek(Event & retrieved_event)
{
  // Empty list
  if (!head)
    return 0;

  int temp_index = top_index;

  s_node * temp = head;
  if (top_index <= 0)
  {
    temp = head->next;
    if (!temp)
      return 0;
    temp_index = MAX;
  }
  retrieved_event.copy_event(temp->events[temp_index - 1]);
  return 1;
}


// Displays all events in the stack. 
// Wrapper function for recursive call to diplay function.
// Returns-> the count of events in the stack
int Stack::display(void)
{
  if(!head)
    return 0;

  int initial_top_index = top_index;
  cout << "                                       STACK" << endl;
  return display(head, initial_top_index);
}


// Displays all events in the stack recursively. 
// Recursive call to display function.
// Returns-> the count of events in the stack
int Stack::display(s_node * & head, int top_index)
{
  if(!head)
    return 0;

  int count = 0;
  for(int i = top_index; i > 0 ; i--)
  {
    cout << endl;
    cout << "                                       ==================================" << endl;
    head->events[i - 1].display();
    count++;
  }
  top_index = MAX;

  return count + display(head->next, top_index);
}



