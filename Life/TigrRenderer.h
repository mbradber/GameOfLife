#ifndef TigrRenderer_h
#define TigrRenderer_h

#include <vector> // TODO: remove me
#include "Types.h"

class Tigr;
class Camera;

class TigrRenderer {
public:
    TigrRenderer(Tigr *screen, Camera *camera);
    void clear(unsigned char r, unsigned char g, unsigned char b);
    void renderCells(const std::vector<CellLocation>& cellLocations);
private:
    Tigr *mScreen;
    Camera *mCamera;
};


#endif /* TigrRenderer_h */
