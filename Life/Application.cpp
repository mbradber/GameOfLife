#include "Application.h"
#include "TigrSystem.h"
#include "TigrRenderer.h"
#include "Simulation.h"
#include <vector> // TODO: remove me

Application::Application(TigrSystem *system)
: mSystem(system)
{
    mRenderer = mSystem->makeRenderer();
}

Application::~Application() {
    delete mSystem;
    delete mRenderer;
}

void Application::run(Simulation* sim) {
    float elapsed = 0.f;
    
    while (mSystem->isRunning()) {
        float delta = mSystem->getDelta();
        elapsed += delta;
        
        if (elapsed >= 0.2f) {
            mRenderer->clear(80, 180, 255);
            
            sim->step();
            elapsed = 0.f;
            
            std::vector<CellLocation> cellLocations = sim->getCells();
            mRenderer->renderCells(cellLocations);
        }
        
        mSystem->update();
    }
}
