#ifndef TigrSystem_h
#define TigrSystem_h

class Tigr;
class TigrRenderer;

class TigrSystem {
public:
    TigrSystem(int windowWidth, int windowHeight);
    ~TigrSystem();
    
    TigrRenderer* makeRenderer() const;
    void update();
    float getDelta() const;
    bool moveLeft() const;
    bool moveRight() const;
    bool moveUp() const;
    bool moveDown() const;
    bool isRunning() const;
    
private:
    Tigr *mScreen;
};


#endif /* TigrSystem_h */
