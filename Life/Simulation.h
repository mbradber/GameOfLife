#ifndef Simulation_h
#define Simulation_h

#include "Types.h"
#include <vector>

class Simulation {
public:
    void addCell(life_t x, life_t y);
    int printState() const;
    void step();
    
    // TODO: implement proper iterator - quick hack to grab cell locations
    std::vector<CellLocation> getCells() const;
    
private:
    void addCell(CellSet& cs, life_t x, life_t y);
    void removeCell(CellSet& cs, life_t x, life_t y);
    
    CellSet mLiveSet;
};



#endif /* Simulation_h */
