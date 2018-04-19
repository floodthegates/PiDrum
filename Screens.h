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

    position get_position() const;
    bsize get_size() const;
    color get_color() const;
    string get_text() const;

    void set_position(position newP);
    void set_size(bsize newS);
    void set_color(color newC);
    void set_text(string newT);

    void draw() const;
    bool overlap(int x, int y) const;
};

#endif //PIDRUM_SCREENS_H
