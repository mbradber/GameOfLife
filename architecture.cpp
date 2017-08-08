
main() {
    Application app(new TigrSystem(), new TigrRenderer());
    app.run();
    
    return 0;
}

Application

    - Simulation sim;
    - IRenderer renderer;
    - ISystem system;
    - Camera camera;

    Application(ISystem* system, IRenderer* renderer) {
        renderer->init(camera);
    }

    ~Application() {
        delete renderer;
        delete system;
    }

    run() {
        
        while (isOpen()) {
            renderer->clear(RGB);
            
            float dt = system->getDelta();

            if (system->moveLeft())
                camera->moveLeft(dt);
            if (system->moveRight())
                camera->moveRight(dt);
            if (system->moveUp()) camera->moveUp(dt);
            if (system->moveDown()) camera->moveDown(dt);

            float accum += dt;
            if (accum >= SIM_RATE) {
                sim->step();
            }

            SomeCollection<2d coords> cells = sim->getCells();
            
            renderer->drawQuads(camera, cells);
            renderer->update();
        }

    }

    isOpen() {
        return renderer->windowOpen() && !system->exited()
    }

