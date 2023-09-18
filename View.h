#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Engine.h" 

class View {
public:
    View(Engine& e); 
    void displayGame() const;
    
private:
    Engine& engine; 
};

#endif 