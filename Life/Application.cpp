#include "Application.h"
#include "TigrSystem.h"
#include "TigrRenderer.h"
#include "Simulation.h"

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
    while (mSystem->isRunning()) {
        mRenderer->clear(80, 180, 255);
        mSystem->update();
    }
}
