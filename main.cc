/*
 * Straights card game implementation - Text-based view
 * References MVC lecture code example
 *
 */


#include "model.h"
#include "controller.h"
#include "view.h"
#include <chrono>
#include <string>

int main( int argc, char * argv[] ) {
    
    try{
        int seed;
        if (argc == 1) {
            seed = std::chrono::system_clock::now().time_since_epoch().count();
        } else {
            seed = std::stoi(argv[1]);
        }
    
        Model       model;		                    // Create model
        Controller  controller( &model );           // Create controller
        View        view( seed, &controller, &model);    // Create view
    }
    catch (int e) {
        return e;
    }
} // main

