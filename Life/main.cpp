#include <iostream>
#include <fstream>
#include "Simulation.h"
#include "Types.h"
#include "Application.h"
#include "TigrSystem.h"

using namespace std;

#define HEADLESS 0

int main(int argc, const char * argv[]) {
    ifstream inf("state.in");
    if (!inf) {
        cerr << "Could not open state.in for reading" << endl;
    }
    
    Simulation sim;
    
    while (inf) {
        string s;
        if (!getline(inf, s)) break;
        
        if (!s.empty()) {
            life_t x = 0, y = 0;
            sscanf(s.c_str(), "%lld,%lld", &x, &y);
            sim.addCell(x, y);
        }
    }
    
#if HEADLESS
    cout << "Live cells at generation 0" << endl;
    sim.printState();
    
    // execute N generations...
    size_t numGenerations = 1;
    for (size_t i = 0; i < numGenerations; ++i) {
        sim.step();
        
        // next generation has been simulated
        cout << "Live cells at generation " << i+1 << endl;
        sim.printState();
    }
#else
    Application(new TigrSystem(400, 300)).run(&sim);
#endif
    
    return 0;
}
