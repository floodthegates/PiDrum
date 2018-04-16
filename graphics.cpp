//
// Created by Kevin Flood on 4/12/18.
//

#include "graphics.h"
#include "SaveLoad.h"
#include "Screens.h"

enum screen_type {
    mainMenu, newKit, openKit, deleteKit, sounds
};
screen_type screen = mainMenu;
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
// Main Menu Buttons
Button mainButt1({100, 210}, {50, 300}, white, "Create New Kit");
Button mainButt2({100, 270}, {50, 300}, white, "Open Existing Kit");
Button mainButt3({100, 330}, {50, 300}, white, "Delete a Kit");
Button mainButt4({100, 390}, {50, 300}, white, "Sounds...");
// Sound Menu Buttons
Button soundButt1({100, 270}, {50, 300}, white, "Upload Sound");
Button soundButt2({100, 330}, {50, 300}, white, "Delete Sound");
// Save/Load Buttons
Button slButt0({150, 100}, {30, 200}, white, "Save Slot 1");
Button slButt1({150, 140}, {30, 200}, white, "Save Slot 2");
Button slButt2({150, 180}, {30, 200}, white, "Save Slot 3");
Button slButt3({150, 220}, {30, 200}, white, "Save Slot 4");
Button slButt4({150, 260}, {30, 200}, white, "Save Slot 5");
Button slButt5({150, 300}, {30, 200}, white, "Save Slot 6");
Button slButt6({150, 340}, {30, 200}, white, "Save Slot 7");
Button slButt7({150, 380}, {30, 200}, white, "Save Slot 8");
Button slButt8({150, 420}, {30, 200}, white, "Save Slot 9");
Button slButt9({150, 460}, {30, 200}, white, "Save Slot 10");
// Exit Button
Button exitButt({25, 425}, {50, 100}, white, "Exit");

void init() {
    width = 500;
    height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // White
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
    }

    glFlush();  // Render now
}

void displayMainMenu() {
    mainButt1.draw();mainButt2.draw();mainButt3.draw();mainButt4.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(150, 50);
    for (int i = 0; i < mainTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mainTitle[i]);
    }
}

void displayNewKit() {

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < newKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, newKitTitle[i]);
    }
}

void displayOpenKit() {
    slButt0.draw();slButt1.draw();slButt2.draw();slButt3.draw();slButt4.draw();
    slButt5.draw();slButt6.draw();slButt7.draw();slButt8.draw();slButt9.draw();

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < openKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, openKitTitle[i]);
    }
}

void displayDeleteKit() {
    slButt0.draw();slButt1.draw();slButt2.draw();slButt3.draw();slButt4.draw();
    slButt5.draw();slButt6.draw();slButt7.draw();slButt8.draw();slButt9.draw();

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < deleteKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, deleteKitTitle[i]);
    }
}

void displaySounds() {
    soundButt1.draw();soundButt2.draw();

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < soundsTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, soundsTitle[i]);
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
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                && x > mainButt1.get_position().x && x < mainButt1.get_position().x + mainButt1.get_size().width
                && y > mainButt1.get_position().y && y < mainButt1.get_position().y + mainButt1.get_size().height) {
                // button 1 function
                screen = newKit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                       && x > mainButt2.get_position().x && x < mainButt2.get_position().x + mainButt2.get_size().width
                       && y > mainButt2.get_position().y &&
                       y < mainButt2.get_position().y + mainButt2.get_size().height) {
                // button 2 function
                screen = openKit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                       && x > mainButt3.get_position().x && x < mainButt3.get_position().x + mainButt3.get_size().width
                       && y > mainButt3.get_position().y &&
                       y < mainButt3.get_position().y + mainButt3.get_size().height) {
                // button 3 function
                screen = deleteKit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                       && x > mainButt4.get_position().x && x < mainButt4.get_position().x + mainButt4.get_size().width
                       && y > mainButt4.get_position().y &&
                       y < mainButt4.get_position().y + mainButt4.get_size().height) {
                // button 4 function
                screen = sounds;
            }
            break;
        case newKit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                && x > exitButt.get_position().x && x < exitButt.get_position().x + exitButt.get_size().width
                && y > exitButt.get_position().y && y < exitButt.get_position().y + exitButt.get_size().height) {
                // button X function
                screen = mainMenu;
            }
            break;
        case openKit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                && x > exitButt.get_position().x && x < exitButt.get_position().x + exitButt.get_size().width
                && y > exitButt.get_position().y && y < exitButt.get_position().y + exitButt.get_size().height) {
                // button X function
                screen = mainMenu;
            }
            break;
        case deleteKit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                && x > exitButt.get_position().x && x < exitButt.get_position().x + exitButt.get_size().width
                && y > exitButt.get_position().y && y < exitButt.get_position().y + exitButt.get_size().height) {
                // button X function
                screen = mainMenu;
            }
            break;
        case sounds:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                && x > soundButt1.get_position().x && x < soundButt1.get_position().x + soundButt1.get_size().width
                && y > soundButt1.get_position().y && y < soundButt1.get_position().y + soundButt1.get_size().height) {
                // button 1 function
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                       && x > soundButt2.get_position().x && x < soundButt2.get_position().x + soundButt2.get_size().width
                       && y > soundButt2.get_position().y && y < soundButt2.get_position().y + soundButt2.get_size().height) {
                // button 2 function
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
                       && x > exitButt.get_position().x && x < exitButt.get_position().x + exitButt.get_size().width
                       && y > exitButt.get_position().y && y < exitButt.get_position().y + exitButt.get_size().height) {
                // button X function
                screen = mainMenu;
                break;
            }
    }

    glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
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