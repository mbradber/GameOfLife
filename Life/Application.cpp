#include "Application.h"
#include "TigrSystem.h"
#include "TigrRenderer.h"
#include "Simulation.h"
#include "Camera.h"
#include <vector> // TODO: remove me
#include <iostream>

Application::Application(TigrSystem *system)
: mSystem(system)
, mRenderer(nullptr)
, mCamera(nullptr)
, mWindowWidth(0)
, mWindowHeight(0)
{
    mSystem->getWindowDimensions(mWindowWidth, mWindowHeight);
    mCamera = new Camera(0, 0, mWindowWidth, mWindowHeight, 20.f, 2);
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
        
        if (mSystem->moveLeft())
            mCamera->move(Direction::LEFT, delta);
        if (mSystem->moveRight())
            mCamera->move(Direction::RIGHT, delta);
        if (mSystem->moveUp())
            mCamera->move(Direction::UP, delta);
        if (mSystem->moveDown())
            mCamera->move(Direction::DOWN, delta);
        
        mRenderer->clear(46, 89, 137);
        
        if (elapsed >= 0.2) {
            sim->step();
            elapsed = 0.f;
        }
        
        // TODO: implement iterator, this copy op is expensive
        std::vector<CellLocation> cellLocations = sim->getCells();
        mRenderer->renderCells(cellLocations);
        
        // render hint text
        float bottomRenderLine = 0.95f * mWindowHeight;
        mRenderer->renderText(10, bottomRenderLine, "WASD Camera");
        
        mSystem->update();
    }
}
