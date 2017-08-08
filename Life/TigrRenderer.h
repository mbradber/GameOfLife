#ifndef TigrRenderer_h
#define TigrRenderer_h

class Tigr;

class TigrRenderer {
public:
    TigrRenderer(Tigr *screen);
    void clear(unsigned char r, unsigned char g, unsigned char b);
private:
    Tigr *mScreen;
};


#endif /* TigrRenderer_h */
