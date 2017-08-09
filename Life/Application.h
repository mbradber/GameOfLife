#ifndef Application_h
#define Application_h

class TigrSystem;
class TigrRenderer;
class Simulation;
class Camera;

class Application {
public:
    Application(TigrSystem *system);
    ~Application();
    void run(Simulation *sim);
    
private:
    // TODO: replace with ISystem & IRender interface to allow for different backends
    TigrSystem *mSystem;
    TigrRenderer *mRenderer;
    Camera *mCamera;
    int mWindowWidth;
    int mWindowHeight;
};


#endif /* Application_h */
