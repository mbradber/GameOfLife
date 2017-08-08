#include "TigrRenderer.h"
#include "tigr.h"

const size_t TigrRenderer::CELL_SIZE = 1;

TigrRenderer::TigrRenderer(Tigr *screen)
: mScreen(screen)
{
    
}

void TigrRenderer::clear(unsigned char r, unsigned char g, unsigned char b) {
    tigrClear(mScreen, tigrRGB(r, g, b));
}


void TigrRenderer::renderCells(const std::vector<CellLocation>& cellLocations) {
    for (CellLocation cell : cellLocations) {
        int cell_x = (int)cell.first * CELL_SIZE;
        int cell_y = (int)cell.second * CELL_SIZE;
        
        cell_x += 160;
        cell_y += 120;
        
        tigrFill(mScreen, cell_x, cell_y, CELL_SIZE, CELL_SIZE, tigrRGB(255, 255, 255));
    }
}
