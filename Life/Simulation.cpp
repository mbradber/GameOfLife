#include "Simulation.h"
#include <iostream>

using namespace std;

template <typename T>
bool cellSetContains(const T& cs, life_t x, life_t y) {
    auto x_itr = cs.find(x);
    if (x_itr != cs.end()) {
        auto y_itr = x_itr->second.find(y);
        return y_itr != x_itr->second.end();
    } else {
        return false;
    }
}

void Simulation::addCell(CellSet& cs, life_t x, life_t y) {
    cs[x].insert(y);
}

void Simulation::addCell(life_t x, life_t y) {
    addCell(mLiveSet, x, y);
}

void Simulation::removeCell(CellSet &cs, life_t x, life_t y) {
    auto x_itr = cs.find(x);
    if (x_itr != cs.end()) {
        unordered_set<life_t>& y_set = x_itr->second;
        auto y_itr = y_set.find(y);
        if (y_itr != y_set.end()) {
            y_set.erase(y);
        }
        
        // if there are no more y values for this x, remove entry
        if (y_set.empty()) {
            cs.erase(x);
        }
    }
}

void Simulation::printState() const {
    for (CellSet::const_iterator x_itr = mLiveSet.begin(); x_itr != mLiveSet.end(); ++x_itr) {
        unordered_set<life_t> y_set = x_itr->second;
        for (unordered_set<life_t>::const_iterator y_itr = y_set.begin(); y_itr != y_set.end(); ++y_itr) {
            life_t lx = x_itr->first;
            life_t ly = *y_itr;
            
            cout << lx << "," << ly << endl;
        }
    }
}

void Simulation::step() {
    CellSet deadSet;
    CellMap candidateMap;
    
    // iterate live cells
    for (CellSet::iterator x_itr = mLiveSet.begin(); x_itr != mLiveSet.end(); ++x_itr) {
        for (unordered_set<life_t>::iterator y_itr = x_itr->second.begin(); y_itr != x_itr->second.end(); ++y_itr) {
            // this cell's coords
            life_t x = x_itr->first;
            life_t y = *y_itr;
            
            // iterate neighbors
            size_t neighborCount = 0;
            life_t dv[] = {-1, 0, 1};
            for (life_t dx = 0; dx < 3; ++dx) {
                for (life_t dy = 0; dy < 3; ++dy) {
                    if (!dv[dx] && !dv[dy]) continue;
                    
                    life_t nx = x + dv[dx];
                    life_t ny = y + dv[dy];
                    
                    // if there is a live neighbor this generation, increment count
                    //if (cellSetContains(liveSet, nx, ny) || cellSetContains(deadSet, nx, ny)) {
                    if (cellSetContains(mLiveSet, nx, ny)) {
                        neighborCount++;
                    } else {
                        // increment the ref count of this neighbor, needs 3 to become alive
                        if (cellSetContains(candidateMap, nx, ny)) {
                            candidateMap[nx][ny]++;
                        } else {
                            candidateMap[nx][ny] = 1;
                        }
                    }
                }
            } // end of neighbor iteration
            
            // decide if this cell dies
            if (neighborCount < 2 || neighborCount > 3) {
                addCell(deadSet, x, y);
            }
        }
    } // end of live cell iteration
    
    // prune live cells
    for (CellSet::iterator x_itr = deadSet.begin(); x_itr != deadSet.end(); ++x_itr) {
        for (unordered_set<life_t>::iterator y_itr = x_itr->second.begin(); y_itr != x_itr->second.end(); ++y_itr) {
            life_t x = x_itr->first;
            life_t y = *y_itr;
            
            removeCell(mLiveSet, x, y);
        }
    }
    
    // add newly born cells
    // TODO: implement another set tracking 'candidate' alive cells when counts hit 3, removing when they hit 4...
    for (CellMap::const_iterator x_itr = candidateMap.begin(); x_itr != candidateMap.end(); ++x_itr) {
        unordered_map<life_t, size_t> y_map = x_itr->second;
        for (unordered_map<life_t, size_t>::const_iterator y_itr = y_map.begin(); y_itr != y_map.end(); ++y_itr) {
            life_t x = x_itr->first;
            life_t y = y_itr->first;
            size_t count = y_itr->second;
            
            if (count == 3) {
                addCell(mLiveSet, x, y);
            }
        }
    }
}
