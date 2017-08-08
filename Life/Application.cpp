#include "Application.h"
#include "TigrSystem.h"
#include "TigrRenderer.h"
#include "Simulation.h"
#include "Camera.h"
#include <vector> // TODO: remove me

Application::Application(TigrSystem *system)
: mSystem(system)
, mRenderer(nullptr)
, mCamera(nullptr)
{
    int windowWidth, windowHeight;
    mSystem->getWindowDimensions(windowWidth, windowHeight);
    mCamera = new Camera(0, 0, windowWidth, windowHeight, 1.f, 2);
    mRenderer = mSystem->makeRenderer(mCamera);
}

Application::~Application() {
    delete mRenderer;
    delete mCamera;
    delete mSystem;
}

void Application::run(Simulation* sim) {
    float elapsed = 0.f;
    
    while (mSystem->isRunning()) {
        float delta = mSystem->getDelta();
        elapsed += delta;
        
        if (elapsed >= 1.f) {
            mRenderer->clear(80, 180, 255);
            
            sim->step();
            elapsed = 0.f;
            
            std::vector<CellLocation> cellLocations = sim->getCells();
            mRenderer->renderCells(cellLocations);
        }
        
        mSystem->update();
    }
}
