#include "Camera.h"


Camera::Camera(float x, float y, life_t width, life_t height, float speed)
: mX(x)
, mY(y)
, mWidth(width)
, mHeight(height)
, mSpeed(speed)
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

