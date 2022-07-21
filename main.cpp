// Tyler Taormina CS163
// June, 2022
// Program 2- Stack and queues at the Fair


// Requirements for test plan
//
// GITHUB : https://github.com/till-t/Program-2.git

// Tests Ideas
// ===================================================================================================
// Test for event class
// - check setting an event with user provided input (passed)
// - check display (passed)
// - check copying from another event into an event (unchecked)
//

#include "event.h"
#include "stack.h"
#include "queue.h"
#include <iostream>

int displayMenu();
int validate_menu_choice();
void processChoice (int& flag, int menu_choice, Stack & stack, Queue & queue);
int get_input(char* & _value);
void make_event(Event & _event);
int convert_character_array_to_int(char * arr, int & num);
int convert_yes_no(char * arr, int & num);

const int SIZE = 100;

int main()
{
  Stack stack;
  Queue queue;

  int flag = 1;
  
  while(flag > 0)
    {
      displayMenu();
      int menu_choice_int = validate_menu_choice();
      processChoice(flag, menu_choice_int, stack, queue);
    }
  return 0;
}

// Function definitions that may go into a header file.
// ======================================================================================


// Displays the menu of functions for the user to choose from.
// Returns-> the integer value for the menu choice 
int displayMenu() {
    std::cout << "==================================================================\n";
    std::cout << "                         MENU" << std::endl;
    std::cout << "==================================================================\n";

    std::cout << "1) Add an Event and display.\n";
    std::cout << "2) Push an event onto the stack..\n";
    std::cout << "3) Pop an event from the stack..\n";
    std::cout << "4) Display the stack..\n";
    std::cout << "5) Enqueue an event..\n";
    std::cout << "6) Dequeue an event..\n";
    std::cout << "7) Display queue..\n";
    std::cout << "8) Exit.\n";
    std::cout << "Enter: ";
    return 0;
}

int validate_menu_choice()
{
  char * menu_choice = new char[SIZE];
  int menu_choice_int = 0;
  get_input(menu_choice);
  int check = convert_character_array_to_int(menu_choice, menu_choice_int);
  if (menu_choice_int > 8 || menu_choice_int < 1) 
    check = 0;

  while(!check)
  {
    delete [] menu_choice;
    menu_choice_int = 0;
    menu_choice = new char[SIZE];
    cout << "Only numbers are accepted." << endl << "Please enter a valid number: ";
    get_input(menu_choice);
    check = convert_character_array_to_int(menu_choice, menu_choice_int);
    if (menu_choice_int > 8 || menu_choice_int < 1) 
      check = 0;
  }

  delete [] menu_choice;
  return menu_choice_int;
}

// Provides option processing for the menu 
void processChoice (int& flag, int menu_choice, Stack & stack, Queue & queue)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      case 1:
        {
          Event event;
          make_event(event);

          int success = event.display();
          if (!success)
            std::cout << "Error encountered." << std::endl;
          break;
        }

      case 2: 
        {
          Event event;
          make_event(event);
          int success = stack.push(event);
          if (!success)
            std::cout << "Error encountered." << std::endl;
          break;
        }

      case 3:
        {
          Event returned_event;
          int success = stack.pop(returned_event);
          if (success)
            returned_event.display();
          else
            std::cout << "Error encountered." << std::endl;
          break;
        }

      case 4: 
        {
          int success = stack.display();
          if(!success)
            std::cout << "Error encounterd." << std::endl;
          break;
        }

      case 5: 
        {
          Event event;
          make_event(event);
          int success = queue.enqueue(event);
          break;
        }

      case 6: 
        {
          Event next_event;
          int success = queue.dequeue(next_event);
          break;
        }


      case 7: 
        {
          int success = queue.display();
          break;
        }

      case 8:
        {
          std::cout << "Are you sure you want to exit?" << std::endl;
          proceed = no;
          break;
        }

      default:
          break;
    }

    if (proceed == no)
    {
      std::cout << "Enter 0 to end program.\n" << std::endl;
      std::cout << "Enter any other number to continue program.\n" << std::endl;
      std::cin >> flag;
      std::cin.ignore(SIZE, '\n');
    }
}

void make_event(Event & event)
{
  // All local variables that will be used to gather input
  char* name = new char[SIZE];
  char* description = new char[SIZE];
  char* review = new char[SIZE];
  char* rating = new char[SIZE];
  char* repeatable = new char[SIZE];
  int rating_int = 0;
  int repeatable_int = 0;

  // Gather input from the user
  std::cout << "Please enter the name of the event: ";
  get_input(name);
  std::cout << "Please enter a description of the event: ";
  get_input(description);
  std::cout << "Please enter a review of the event: ";
  get_input(review);

  // Character array conversion to integers begins here
  std::cout << "Please enter your rating of the event: ";
  get_input(rating);
  int check = convert_character_array_to_int(rating, rating_int);
  while(!check)
  {
    delete [] rating;
    rating = new char[SIZE];
    cout << "Please enter a rating 1 - 10. 1 being the worst ever and 10 being the best: ";
    get_input(rating);
    rating_int = 0;
    check = convert_character_array_to_int(rating, rating_int);
  }

  std::cout << "Would you do this event again? (y/n): ";
  get_input(repeatable);
  check = convert_yes_no(repeatable, repeatable_int);
  while(!check)
  {
    delete [] repeatable;
    repeatable = new char[SIZE];
    cout << "Please enter a Y/y or N/n: ";
    get_input(repeatable);
    repeatable_int = 0;
    check = convert_yes_no(repeatable, repeatable_int);
  }

  event.set_event(name, description, review, rating_int, repeatable_int);
  delete [] name;
  delete [] description;
  delete [] review;
  delete [] rating;
  delete [] repeatable;
}

// Converts character array to integer 
// Returns-> 0 if the array contains characters other than integers 0-9
//           1 if the array only contains digits 0-9 and was successfully converted
int convert_character_array_to_int(char * arr, int & num)
{ 
  for (int i = 0; i < strlen(arr); i++)
  {
    if (int(arr[i]) < 48 || int(arr[i]) > 57)
      return 0;
    num = num * 10 + (int(arr[i]) - 48);
  }
  return 1;
}

// Converts characters Y/y to 1 and N/n to 0 
// Returns-> 0 if the array is greater than 1 character in length or the character is neither Y/y or N/n
//           1 if a Y/y is entered
//           2 if a N/n is entered
int convert_yes_no(char * arr, int & num)
{
  int success = 0;
  if (strlen(arr) > 1)
    return 0;

  int i = 0;

  // ASCII values for Y = 89 and y = 121
  if (int(arr[i]) == 89 || int(arr[i]) == 121)
  {
    num = 1;
    success = 1;
  }
  // ASCII values for N = 78 and n = 110
  if (int(arr[i]) == 78 || int(arr[i]) == 110)
  {
    num = 0;
    success = 2;
  }
  return success;
}

int get_input(char* & value)
{
  std::cin.get(value, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
  return 1;
}

