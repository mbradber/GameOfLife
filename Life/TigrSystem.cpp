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

TigrRenderer* TigrSystem::makeRenderer(Camera *camera) const {
    return new TigrRenderer(mScreen, camera);
}

void TigrSystem::update() {
    tigrUpdate(mScreen);
}

float TigrSystem::getDelta() const {
    return tigrTime();
}

bool TigrSystem::moveLeft() const {
    return tigrKeyHeld(mScreen, 'A');
}

bool TigrSystem::moveRight() const {
    return tigrKeyHeld(mScreen, 'D');
}

bool TigrSystem::moveUp() const {
    return tigrKeyHeld(mScreen, 'W');
}

bool TigrSystem::moveDown() const {
    return tigrKeyHeld(mScreen, 'S');
}

bool TigrSystem::isRunning() const {
    return !( tigrClosed(mScreen) || tigrKeyDown(mScreen, TK_ESCAPE) );
}

void TigrSystem::getWindowDimensions(int& outWidth, int& outHeight) const {
    outWidth = mScreen->w;
    outHeight = mScreen->h;
}
