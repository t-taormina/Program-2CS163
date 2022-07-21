// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair

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

    // Methods
    int set_event(char * name, char * description, char * review, int rating, int count);
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
