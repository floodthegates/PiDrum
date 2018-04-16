//
// Created by Kevin Flood on 4/12/18.
//

#include "graphics.h"
#include <string>
using namespace std;

#ifndef PIDRUM_SCREENS_H
#define PIDRUM_SCREENS_H

struct position {
    int x;
    int y;
};
struct bsize {
    int height;
    int width;
};
struct color {
    double r;
    double g;
    double b;
};


class Button {
private:
    position pos;
    bsize siz;
    color col;
    string text;

public:
    Button();
    Button(position p, bsize s, color c, string t);

    position get_position();
    bsize get_size();
    color get_color();
    string get_text();

    void set_position(position newP);
    void set_size(bsize newS);
    void set_color(color newC);
    void set_text(string newT);

    void draw() const;
};

#endif //PIDRUM_SCREENS_H
