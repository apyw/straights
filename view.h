/*
 * Straights card game implementation
 * References MVC lecture code example
 *
 * View class.  Is responsible for player commands.
 *
 */

 #ifndef VIEW_H
#define VIEW_H

#include "observer.h"

class Controller;
class Model;

class View : public Observer {
    // Observer Pattern: to access Model accessors without having to downcast subject
    Model *model;
	
    // Strategy Pattern member (plus signal handlers)
    Controller *controller;

    int seed; 
    // User Input
    void nextCommand();
     
  public:
    View( int, Controller*, Model*);
    virtual ~View();
    virtual void update();	// Observer Pattern: concrete update() method

}; // View

#endif 
