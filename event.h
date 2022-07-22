// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair

// EVENT CLASS 
// ========================
// An event object has 5 private data fields. 
// - Integers
//           Rating -> A 1-10 scale on how good or bad a given event was.
//           Repeatable -> An integer that evaluates to true or false. Indicates whether an event is worth doing twice. 
// - Character Arrays
//           Name -> Character array containing the name of th event
//           Review -> Character array containing a short review of the event based on the users experience
//           Description -> Character array containing a short description of the event. 


#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using std::cout;
using std::endl;

class Event
{
  public:
    // Constructors
    Event(void);
    ~Event(void);

// METHODS 
// ----------------------
// set_event - accept user input from the client application in order to establish values for all data fields for an event.  
//    Arguments -> takes 5 arguments and places the values into the private fields
//        EXAMPLE 
//        Initialize event ----   Event event; 
//        Call function    ----   int returns = event.set_event(name, description, review, rating, count);
//
//    Returns -> 3 potential return values that indicate one of the following.
//         0 if any parameters passed are null valued
//         1 if the event trying to be set is already holding data
//         2 if the event was successfully set

    int set_event(char * name, char * description, char * review, int rating, int count);
    

// ----------------------
// copy_event - takes all values from event passed as an argument and puts them into the event the method is being called with 
//    Arguments -> takes one argument, another event object
//        EXAMPLE 
//        Initialize event ----   Event event; 
//        Call function    ----   int returns = event.copy_event(data_filled_event);
//
//// Returns-> 0 if any value in the argument is set to null
//             1 if the event being copied to is already holding data
//             2 if the event is successfully copied
    int copy_event(Event& copy_from);


// ----------------------
// display - outputs the data fields of an event object 
//    Arguments ->  none
//        EXAMPLE 
//        Call function    ----   int returns = event.display(void);
//
//    Returns -> 1 if function runs successfully.
//
    int display(void);


// ----------------------
// reset_event - sets all character arrays to null and all integers to 0
//    Arguments ->  none
//        EXAMPLE 
//        Call function    ----   int returns = event.reset_event();
//
//    Returns -> 1 if function runs successfully.
    int reset_event();


// ----------------------
// get_member - returns a copy of the desired data member
//    Arguments ->  none
//        EXAMPLE 
//        Call function    ----   char * name = event.get_name();
//
//    Returns -> 1 if function runs successfully.

    // Getters
    char* get_name();
    char* get_description();
    char* get_review();
    int get_rating();
    int get_repeatable();

  private:
    char * name;
    char * description;
    char * review;
    int rating;
    int repeatable;
};

#endif
