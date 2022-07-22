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
//
// set_event  
//    Arguments -> takes 5 arguments and places the values into the private fields
//        EXAMPLE 
//        Initialize event ----   Event event; 
//        Call function    ----   int returns = event.set_event(name, description, review, rating, count);
//
//    Returns -> returns 3 indicators.
//         0 if any parameters passed are null valued
//         1 if the event trying to be set is already holding data
//         2 if the event was successfully set
//
//      Class is designed to accept user input from the client application in order to establish values for all data 
//      fields for an event.  

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
// set_event  
//    Arguments -> takes 5 arguments and places the values into the private fields
//        EXAMPLE 
//        Initialize event ----   Event event; 
//        Call function    ----   int returns = event.set_event(name, description, review, rating, count);
//
//    Returns -> returns 3 indicators.
//         0 if any parameters passed are null valued
//         1 if the event trying to be set is already holding data
//         2 if the event was successfully set
//
//      Class is designed to accept user input from the client application in order to establish values for all data 
//      fields for an event.  
    int set_event(char * name, char * description, char * review, int rating, int count);
    

// ----------------------
// set_event  
//    Arguments -> takes 5 arguments and places the values into the private fields
//        EXAMPLE 
//        Initialize event ----   Event event; 
//        Call function    ----   int returns = event.set_event(name, description, review, rating, count);
//
//    Returns -> returns 3 indicators.
//         0 if any parameters passed are null valued
//         1 if the event trying to be set is already holding data
//         2 if the event was successfully set
//
//      Class is designed to accept user input from the client application in order to establish values for all data 
//      fields for an event.  
    int copy_event(Event& copy_from);



    int display(void);
    int reset_event();

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
