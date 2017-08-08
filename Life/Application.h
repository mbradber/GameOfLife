#ifndef Application_h
#define Application_h

class TigrSystem;
class TigrRenderer;
class Simulation;

class Application {
public:
    Application(TigrSystem *system);
    ~Application();
    void run(Simulation *sim);
    
private:
    TigrSystem *mSystem;
    TigrRenderer *mRenderer;
};


#endif /* Application_h */
