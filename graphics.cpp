//
// Created by Kevin Flood on 4/12/18.
//

#include "graphics.h"
#include "SaveLoad.h"
#include "Screens.h"

enum screen_type {
    mainMenu, newKit, openKit, deleteKit, sounds, play
};
screen_type screen = mainMenu;
int currentKit = 10;
color white = {1.0, 1.0, 1.0};
color black = {0.0, 0.0, 0.0};
color red   = {1.0, 0.5, 0.5};
color green = {0.5, 1.0, 0.5};

GLdouble width, height;
int wd;
string mainTitle = "Welcome to Pi Drum";
string newKitTitle = "New Kit Screen";
string openKitTitle = "Open Kit Screen";
string deleteKitTitle = "Delete Kit Screen";
string soundsTitle = "Sounds Screen";
string playTitle = "Play Screen";
// Main Menu Buttons
Button mainButt1({45, 250}, {50, 200}, black, "Create New Kit");
Button mainButt2({45, 310}, {50, 200}, black, "Open Existing Kit");
Button mainButt3({255, 250}, {50, 200}, black, "Delete a Kit");
Button mainButt4({255, 310}, {50, 200}, black, "Sounds...");
// Sound Menu Buttons
Button soundButt1({100, 270}, {50, 300}, black, "Upload Sound");
Button soundButt2({100, 330}, {50, 300}, black, "Delete Sound");
// Save/Load Buttons
Button slButt0({150, 100}, {30, 200}, black, "Empty Save Slot");
Button slButt1({150, 140}, {30, 200}, black, "Empty Save Slot");
Button slButt2({150, 180}, {30, 200}, black, "Empty Save Slot");
Button slButt3({150, 220}, {30, 200}, black, "Empty Save Slot");
Button slButt4({150, 260}, {30, 200}, black, "Empty Save Slot");
Button slButt5({150, 300}, {30, 200}, black, "Empty Save Slot");
Button slButt6({150, 340}, {30, 200}, black, "Empty Save Slot");
Button slButt7({150, 380}, {30, 200}, black, "Empty Save Slot");
Button slButt8({150, 420}, {30, 200}, black, "Empty Save Slot");
Button slButt9({150, 460}, {30, 200}, black, "Empty Save Slot");
// Exit Button
Button exitButt({25, 425}, {50, 100}, black, "Exit");

void init() {
    width = 500;
    height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    switch (screen) {
        case mainMenu:
            displayMainMenu();
            break;
        case newKit:
            displayNewKit();
            break;
        case openKit:
            displayOpenKit();
            break;
        case deleteKit:
            displayDeleteKit();
            break;
        case sounds:
            displaySounds();
            break;
        case play:
            displayPlay();
            break;
    }

    glFlush();  // Render now
}

void displayMainMenu() {
    mainButt1.draw();mainButt2.draw();mainButt3.draw();mainButt4.draw();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(165, 50);
    for (int i = 0; i < mainTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, mainTitle[i]);
    }
}

void displayNewKit() {

    exitButt.draw();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(185, 50);
    for (int i = 0; i < newKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, newKitTitle[i]);
    }
}

void displayOpenKit() {
    slButt0.draw();slButt1.draw();slButt2.draw();slButt3.draw();slButt4.draw();
    slButt5.draw();slButt6.draw();slButt7.draw();slButt8.draw();slButt9.draw();

    exitButt.draw();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(180, 50);
    for (int i = 0; i < openKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, openKitTitle[i]);
    }
}

void displayDeleteKit() {
    slButt0.draw();slButt1.draw();slButt2.draw();slButt3.draw();slButt4.draw();
    slButt5.draw();slButt6.draw();slButt7.draw();slButt8.draw();slButt9.draw();

    exitButt.draw();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(180, 50);
    for (int i = 0; i < deleteKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, deleteKitTitle[i]);
    }
}

void displaySounds() {
    soundButt1.draw();soundButt2.draw();

    exitButt.draw();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < soundsTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, soundsTitle[i]);
    }
}

void displayPlay() {

    exitButt.draw();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < playTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, playTitle[i]);
    }
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(175, 250);
    for (int i = 0; i < form_play_string(currentKit).length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, form_play_string(currentKit)[i]);
    }
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    } else if (key == 'w') { // move up
    } else if (key == 's') { // move down
    } else if (key == 'a') { // move left
    } else if (key == 'd') { // move right
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {


    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    switch (screen) {
        case mainMenu:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainButt1.overlap(x, y)) {
                // button 1 function
                screen = newKit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainButt2.overlap(x, y)) {
                // button 2 function
                screen = openKit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainButt3.overlap(x, y)) {
                // button 3 function
                screen = deleteKit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainButt4.overlap(x, y)) {
                // button 4 function
                screen = sounds;
            }
            break;
        case newKit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && exitButt.overlap(x, y)) {
                // button X function
                screen = mainMenu;
            }
            break;
        case openKit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && exitButt.overlap(x, y)) {
                // button X function
                screen = mainMenu;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt0.overlap(x, y)) {
                // load kit 0
                screen = play;
                currentKit = 0;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt1.overlap(x, y)) {
                // load kit 1
                screen = play;
                currentKit = 1;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt2.overlap(x, y)) {
                // load kit 2
                screen = play;
                currentKit = 2;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt3.overlap(x, y)) {
                // load kit 3
                screen = play;
                currentKit = 3;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt4.overlap(x, y)) {
                // load kit 4
                screen = play;
                currentKit = 4;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt5.overlap(x, y)) {
                // load kit 5
                screen = play;
                currentKit = 5;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt6.overlap(x, y)) {
                // load kit 6
                screen = play;
                currentKit = 6;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt7.overlap(x, y)) {
                // load kit 7
                screen = play;
                currentKit = 7;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt8.overlap(x, y)) {
                // load kit 8
                screen = play;
                currentKit = 8;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt9.overlap(x, y)) {
                // load kit 9
                screen = play;
                currentKit = 9;
            }
            break;
        case deleteKit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && exitButt.overlap(x, y)) {
                // button X function
                screen = mainMenu;
            }
            break;
        case sounds:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && soundButt1.overlap(x, y)) {
                // button 1 function
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && soundButt2.overlap(x, y)) {
                // button 2 function
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && exitButt.overlap(x, y)) {
                // button X function
                screen = mainMenu;
            }
            break;
        case play:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && exitButt.overlap(x, y)) {
                // button X function
                screen = mainMenu;
            }
    }

    glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

string form_play_string(int si) {
    string play = "Playing Kit ";
    play += to_string(si + 1);
    return play;
}

/* Main function: GLUT runs as a console application starting at main()  */
int graphicsPlay(int argc, char **argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int) width, (int) height);
    glutInitWindowPosition(400, 150); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("PiDrum" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}