#include "TigrRenderer.h"
#include "tigr.h"
#include "Camera.h"

TigrRenderer::TigrRenderer(Tigr *screen, Camera *camera)
: mScreen(screen)
, mCamera(camera)
{
    
}

void TigrRenderer::clear(unsigned char r, unsigned char g, unsigned char b) {
    tigrClear(mScreen, tigrRGB(r, g, b));
}

void TigrRenderer::renderCells(const std::vector<CellLocation>& cellLocations) {
    for (CellLocation cell : cellLocations) {
        CellLocation screenCell = mCamera->toScreenSpace(cell);
        int zoom = mCamera->getZoom();
        
//        int cell_x = (int)cell.first;
//        int cell_y = (int)cell.second;
//        
//        // subtract camera position...
//        
//        // add origin offset
//        cell_x += 160 / CELL_SIZE;
//        cell_y += 120 / CELL_SIZE;
//        
//        // flip y
//        cell_y = 240 / CELL_SIZE - cell_y;
//        
//        // multiply by scale
//        cell_x *= CELL_SIZE;
//        cell_y *= CELL_SIZE;
        
        tigrFill(mScreen, (int)screenCell.first, (int)screenCell.second, zoom, zoom, tigrRGB(255, 255, 255));
    }
}
