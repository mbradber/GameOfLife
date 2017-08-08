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
    TigrSystem *mSystem;
    TigrRenderer *mRenderer;
    Camera *mCamera;
};


#endif /* Application_h */
