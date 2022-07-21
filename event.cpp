//Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair

#include "event.h"

// Default constructor
Event::Event() : name(nullptr), description(nullptr), review(nullptr), rating(0), repeatable(0){}

// Deconstructor
Event::~Event()
{
  if (name != nullptr)
    delete [] name;

 if (description != nullptr)
    delete [] description;

 if (review != nullptr)
    delete [] review;
 name = description = review = nullptr;
}

// Allows client program to establish an event by passing information as parameters
// Returns-> 0 if any parameters passed are null valued
//           1 if the event trying to be set is already holding data
//           2 if the event was successfully set
int Event::set_event(char * copy_name, char * copy_description, char * copy_review, int copy_rating, int copy_repeatable)
{
  // Verify no null values being passed
  if (copy_name == nullptr || copy_description == nullptr || copy_review == nullptr)
    return 0;

  // Setting an event should only be conducted on a new event with 
  // default values. These checks are in place in the case that the 
  // client calls set_event(args) on an event that is holding data. 
  if (name != nullptr || description != nullptr || review != nullptr)
    return 1;

  name = new char[strlen(copy_name) + 1];
  strcpy(name, copy_name);

  description = new char[strlen(copy_description) + 1];
  strcpy(description, copy_description);

  review = new char[strlen(copy_review) + 1];
  strcpy(review, copy_review);

  repeatable = copy_repeatable;
  rating = copy_rating;
  return 2;
}

// Copies all values in the event that is passed as an argument
// Returns-> 0 if any value in the argument is set to null
//           1 if the event being copied to is already holding data
//           2 if the event is successfully copied
int Event::copy_event(Event& copy_from)
{
  // Verify no null values being passed
  if (copy_from.get_name() == nullptr || copy_from.get_description() == nullptr || copy_from.get_review() == nullptr)
    return 0;

  // Verify no data already stored in event
  if (name != nullptr || description != nullptr || review != nullptr)
    return 1;

  // Copy data from copy_from
  name = new char[strlen(copy_from.get_name()) + 1];
  strcpy(name, copy_from.get_name());

  description = new char[strlen(copy_from.get_description()) + 1];
  strcpy(description, copy_from.get_description());

  review = new char[strlen(copy_from.get_review()) + 1];
  strcpy(review, copy_from.get_review());

  repeatable = copy_from.get_repeatable();
  rating = copy_from.get_rating();
  return 1;
}

// Displays data stored in the event
// Returns-> 1 if function runs to completion
int Event::display(void)
{
  cout << "                                       Event name: " << name << endl;
  cout << "                                       Event description: " << description << endl;
  cout << "                                       Event review: " << review << endl;
  cout << "                                       Event rating: " << rating << endl;
  cout << "                                       Event repeatability: ";
  if (repeatable)
    cout << "Yes" << endl;
  else
   cout << "No" << endl;
  return 1;
}

// Resets all values to default values
// Returns-> 1 if function runs to completion
int Event::reset_event()
{
  if(name != nullptr)
    delete [] name;

  if(description != nullptr)
    delete [] description;

  if(review != nullptr)
    delete [] review;

  name = description = review = nullptr;
  
  rating = repeatable = 0;
  return 1;
}

// Getters
char* Event::get_name()
{
  return name;
}

char* Event::get_description()
{
  return description;
}

char* Event::get_review()
{
  return review;
}

int Event::get_rating()
{
  return rating;
}

int Event::get_repeatable()
{
  return repeatable;
}



