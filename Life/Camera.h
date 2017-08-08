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
    Camera(int x, int y, int width, int height, float speed, int zoom);
    void move(Direction d, float dt);
    CellLocation toScreenSpace(const CellLocation& cell) const;
    int getZoom() const { return mZoom; }
    
private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    float mSpeed;
    int mZoom;
};


#endif /* Camera_h */
