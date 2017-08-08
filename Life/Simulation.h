#ifndef Simulation_h
#define Simulation_h

#include "Types.h"

class Simulation {
public:
    void addCell(life_t x, life_t y);
    void printState() const;
    void step();
    
private:
    void addCell(CellSet& cs, life_t x, life_t y);
    void removeCell(CellSet& cs, life_t x, life_t y);
    
    CellSet mLiveSet;
};



#endif /* Simulation_h */
