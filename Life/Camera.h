#ifndef Camera_h
#define Camera_h

#include "Types.h"

enum class Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Camera {
public:
    Camera(float x, float y, life_t width, life_t height, float speed);
    void move(Direction d, float dt);
    
private:
    float mX;
    float mY;
    life_t mWidth;
    life_t mHeight;
    float mSpeed;
};


#endif /* Camera_h */
