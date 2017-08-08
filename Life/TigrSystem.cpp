#include "TigrSystem.h"
#include "tigr.h"
 #include "TigrRenderer.h"

TigrSystem::TigrSystem(int windowWidth, int windowHeight)
: mScreen(tigrWindow(windowWidth, windowHeight, "Game of Life", TIGR_2X))
{
    
}

TigrSystem::~TigrSystem() {
    tigrFree(mScreen);
}

TigrRenderer* TigrSystem::makeRenderer() const {
    return new TigrRenderer(mScreen);
}

void TigrSystem::update() {
    tigrUpdate(mScreen);
}

float TigrSystem::getDelta() const {
    return tigrTime();
}

bool TigrSystem::moveLeft() const {
    return tigrKeyHeld(mScreen, TK_LEFT);
}

bool TigrSystem::moveRight() const {
    return tigrKeyHeld(mScreen, TK_RIGHT);
}

bool TigrSystem::moveUp() const {
    return tigrKeyHeld(mScreen, TK_UP);
}

bool TigrSystem::moveDown() const {
    return tigrKeyHeld(mScreen, TK_DOWN);
}

bool TigrSystem::isRunning() const {
    return !( tigrClosed(mScreen) || tigrKeyDown(mScreen, TK_ESCAPE) );
}
