#include "TigrRenderer.h"
#include "tigr.h"

TigrRenderer::TigrRenderer(Tigr *screen)
: mScreen(screen)
{
    
}

void TigrRenderer::clear(unsigned char r, unsigned char g, unsigned char b) {
    tigrClear(mScreen, tigrRGB(r, g, b));
}
