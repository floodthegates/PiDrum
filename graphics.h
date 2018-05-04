//
// Created by Kevin Flood on 4/12/18.
//

#ifndef PIDRUM_GRAPHICS_H
#define PIDRUM_GRAPHICS_H

#include "dirent.h"
#include <string>

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Initialize OpenGL Graphics
void InitGL(void);

// Callback functions for GLUT */

// Draw the window - this is where all the GL actions are
void display(void);

void displayMainMenu();
void displayNewKit();
void displayPadInit();
void displaySaveNew();
void displayOpenKit();
void displayDeleteKit();
void displaySounds();
void displayPlay();

void set_pad_init(int i, bool p);
void init_pad_init();

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int extra);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

string form_play_string(int si);

int graphicsPlay(int argc, char *argv[]);


#endif //PIDRUM_GRAPHICS_H
