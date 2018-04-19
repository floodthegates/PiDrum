//
// Created by Kevin Flood on 4/12/18.
//

#include "Screens.h"

// Button constructors
Button::Button() {
    pos.x = 0;
    pos.y = 0;
    siz.height = 50;
    siz.width = 100;
    col.r = 1.0;
    col.g = 1.0;
    col.b = 1.0;
    text = "default";
}
Button::Button(position p, bsize s, color c, string t) {
    pos.x = p.x;
    pos.y = p.y;
    siz.height = s.height;
    siz.width = s.width;
    col.r = c.r;
    col.g = c.g;
    col.b = c.b;
    text = t;
}

// Button getters
position Button::get_position() const {
    return pos;
}
bsize Button::get_size() const {
    return siz;
}
color Button::get_color() const {
    return col;
}
string Button::get_text() const {
    return text;
}

// Button setters
void Button::set_position(position newP) {
    pos.x = newP.x;
    pos.y = newP.y;
}
void Button::set_size(bsize newS) {
    siz.height = newS.height;
    siz.width = newS.width;
}
void Button::set_color(color newC) {
    col.r = newC.r;
    col.g = newC.g;
    col.b = newC.b;
}
void Button::set_text(string newT) {
    text = newT;
}

// Button methods
void Button::draw() const {
    glColor3f(col.r, col.g, col.b);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(pos.x, pos.y);
    glColor3f(col.r - .25, col.g - .25, col.b - .25);
    // bottom left corner
    glVertex2i(pos.x, pos.y + siz.height);
    glColor3f(col.r - .5, col.g - .5, col.b - .5);
    // bottom right corner
    glVertex2i(pos.x + siz.width, pos.y + siz.height);
    glColor3f(col.r - .25, col.g - .25, col.b - .25);
    // top right corner
    glVertex2i(pos.x + siz.width, pos.y);
    glEnd();

    glColor3f(1 - col.r, 1 - col.g, 1 - col.b);
    glRasterPos2i(pos.x + siz.width * .5 - text.length() * 5, pos.y + siz.height * .6);
    for (int i = 0; i < text.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

bool Button::overlap(int x, int y) const {
    return (x >= pos.x && x <= (pos.x + siz.width) &&
            y >= pos.y && y <= (pos.y + siz.height));
}