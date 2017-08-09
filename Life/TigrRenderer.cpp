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
        
        tigrFill(mScreen, (int)screenCell.first, (int)screenCell.second, zoom, zoom, tigrRGB(255, 255, 255));
    }
}

void TigrRenderer::renderText(int x, int y, const char *text) {
    tigrPrint(mScreen, tfont, x, y, tigrRGBA(0xff,0xff,0xff,0xff), text);
}
