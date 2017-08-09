#include "Camera.h"


Camera::Camera(int x, int y, int width, int height, float speed, int zoom)
: mX(x)
, mY(y)
, mWidth(width)
, mHeight(height)
, mSpeed(speed)
, mZoom(zoom)
{
    
}

void Camera::move(Direction d, float dt) {
    // TODO: move integer steps at a time since float won't scale to 64 bit range
    switch (d) {
        case Direction::LEFT:
            mX -= dt * mSpeed;
            break;
        case Direction::RIGHT:
            mX += dt * mSpeed;
            break;
        case Direction::UP:
            mY += dt * mSpeed;
            break;
        case Direction::DOWN:
            mY -= dt * mSpeed;
    }
}

CellLocation Camera::toScreenSpace(const CellLocation& cell) const {
    life_t cell_x = cell.first;
    life_t cell_y = cell.second;
    
    // subtract camera position...
    cell_x -= mX;
    cell_y -= mY;
    
    // add origin offset
    cell_x += (mWidth / 2) / mZoom;
    cell_y += (mHeight / 2) / mZoom;
    
    // flip y
    cell_y = (mHeight / mZoom) - cell_y;
    
    // multiply by scale
    cell_x *= mZoom;
    cell_y *= mZoom;
    
    return std::make_pair(cell_x, cell_y);
}


