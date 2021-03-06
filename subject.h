/*
 * Straights card game implementation
 * References MVC lecture code example
 *
 * Subject class.  Abstract class for Observer Pattern
 *
 */

 #ifndef SUBJECT_H
#define SUBJECT_H

#include <set>

class Observer;

class Subject {
  public:
    void subscribe( Observer* );
    void unsubscribe( Observer* );

  protected:
    void notify();

  private:
    typedef std::set< Observer* > Observers;
    Observers observers;
}; // Subject

#endif
