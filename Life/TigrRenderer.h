#ifndef TigrRenderer_h
#define TigrRenderer_h

#include <vector>
#include "Types.h"

class Tigr;

class TigrRenderer {
public:
    TigrRenderer(Tigr *screen);
    void clear(unsigned char r, unsigned char g, unsigned char b);
    void renderCells(const std::vector<CellLocation>& cellLocations);
private:
    Tigr *mScreen;
    static const size_t CELL_SIZE;
};


#endif /* TigrRenderer_h */
