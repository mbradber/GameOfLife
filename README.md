# Conway's Game Of Life

![alt text](http://i1079.photobucket.com/albums/w503/macoberry/Screen%20Shot%202017-08-08%20at%209.56.15%20PM_zpsryf8xrrk.png "4 Corners")
![alt text](http://i1079.photobucket.com/albums/w503/macoberry/Screen%20Shot%202017-08-08%20at%2011.04.52%20PM_zpsjkfxf2nx.png "Gosper Gun")

## Overview
Conway's Game of Life is explained in detail here https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life. This is an implementation of the simulation which runs in 64 bit integer space.
* The program can be run in headless or GUI mode.
* The input data is specified through 'state.in', which is expected to be in the same directory as the executable.
* Included is an Xcode project for building on MacOS. Windows build or cmake configuration is TBD.
* In GUI mode the camera can be moved with WASD keys.
* In headless mode the simulation will run for a specified number of generations.

## Project structure
* `Life` directory houses all the source.
* `config` contains an assortment of interesting GOL configurations. Most of which were found from the GOL Lexicon https://bitstorm.org/gameoflife/lexicon/
* `scripts` contains a couple of useful Python scripts for generating random configurations within a range, and for parsing configuration data pulled from the GOL Lexicon.
* `testing` currently holds a single alternative simple GOL implementation based on a 2D array. This was initially used to run during testing, to help verify correct outputs with the main implementation.

## Simulation Overview
The simulation steps through discrete generations, and only operates on live cells and their immediate neighbors. The coordinates for a cell are 64 bit signed integers and are stored in a nested hash map.
```cpp
typedef std::unordered_map< life_t, std::unordered_set<life_t> > CellSet;
```
When iterating each live cell, the live neighbors are counted, and each dead neighbor is also marked as having been 'seen' by a live cell in order to consider it for life in the next generation. If the current live cell has too many or too few live neighbors it will be added to a separate 'deadSet' to be pruned at the end of this simulation step. Then the set of dead cells that were seen while iterating the current live cells have their 'seen' references checked, if it was seen exactly 3 times it will be added to the 'live' set for the next generation.

## GUI Architecture
The GUI application sits on top of the core simulation. The driver class is `Application.cpp`. The Application class uses several components to tie together the GUI app.
* A `System` object, currently there is only one System class, `TigrSystem`.
* A `Simulation` instance, which has been pre-configured with the cell input data.
* A `Renderer` which is acquired through a factory function provided by the `System`
* A `Camera` class which is initialized with the window size, movement speed, and zoom level.

`Application::run(Simulation* sim)` runs a basic loop which executes the following steps
1. Acquire delta time.
2. Move the camera based on user input.
3. Clear the screen through the `Renderer`.
4. Check if enough time has elapsed to execute a simulation tick.
5. Acquire the location of the live cells this generation from the `Simulation`.
6. Submit the set of locations to the Renderer.
7. Render HUD text.
8. `System` update.

The `System` and `Renderer` implemented by `TigrSystem` and `TigrRenderer` utilizes a lightweight, low dependency 2D drawing framework called `tigr` which can be found here https://bitbucket.org/rmitton/tigr/src
