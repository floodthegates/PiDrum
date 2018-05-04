//
// Created by Kevin Flood on 4/12/18.
//

#include "graphics.h"
#include "SaveLoad.h"
#include "Screens.h"

#define STB_IMAGE_IMPLEMENTATION

enum screen_type {
    mainMenu, newKit, padInit, saveNew, openKit, deleteKit, sounds, play
};
screen_type screen = mainMenu;
int currentKit = 10;
int currentPad = 5;
bool pad0init = false;
bool pad1init = false;
bool pad2init = false;
bool pad3init = false;
bool pad4init = false;
bool padError = false;
color white = {1.0, 1.0, 1.0};
color black = {0.0, 0.0, 0.0};
color red   = {1.0, 0.5, 0.5};
color green = {0.5, 1.0, 0.5};
SaveLoad temp;

GLdouble width, height;
int wd;
// Screen Titles
string mainTitle = "Welcome to Pi Drum";
string newKitTitle = "New Kit Screen";
string openKitTitle = "Open Kit Screen";
string deleteKitTitle = "Delete Kit Screen";
string soundsTitle = "Sounds Screen";
string playTitle = "Play Screen";
// Error messages
string padErrorMessage = "Not all pads initialized";
// Sound Strings
string sound1 = "WoodenPiccolo";
string sound2 = "TamaWood";
string sound3 = "SonorForce3000";
string sound4 = "PiccoloSidestick";
string sound5 = "AcousticSnare";
string sound6 = "LooseKick";
string sound7 = "KesKick";
string sound8 = "AcousKick";
string sound9 = "KatsKlass";
string sound10 = "KatsPoodle";
string sound11 = "KatsHalfOp";
string sound12 = "CymbalC";

// Main Menu Buttons
Button mainButt1({45, 250}, {50, 200}, white, "Create New Kit");
Button mainButt2({45, 310}, {50, 200}, white, "Open Existing Kit");
Button mainButt3({255, 250}, {50, 200}, white, "Delete a Kit");
Button mainButt4({255, 310}, {50, 200}, white, "Sounds...");
Button initButt({25, 425}, {50, 200}, white, "Initialize Saves");
// New Kit Buttons
Button newButt1({150, 180}, {30, 200}, white, "Pad 1");
Button newButt2({150, 220}, {30, 200}, white, "Pad 2");
Button newButt3({150, 260}, {30, 200}, white, "Pad 3");
Button newButt4({150, 300}, {30, 200}, white, "Pad 4");
Button newButt5({150, 340}, {30, 200}, white, "Pad 5");
// Pad Init Buttons
Button backButt({25, 425}, {50, 100}, white, "Back");
Button doneButt({375, 425}, {50, 100}, white, "Done");
Button padButt1({45, 100}, {30, 200}, white, sound1);
Button padButt2({45, 140}, {30, 200}, white, sound2);
Button padButt3({45, 180}, {30, 200}, white, sound3);
Button padButt4({45, 220}, {30, 200}, white, sound4);
Button padButt5({45, 260}, {30, 200}, white, sound5);
Button padButt6({45, 300}, {30, 200}, white, sound6);
Button padButt7({45, 340}, {30, 200}, white, sound7);
Button padButt8({255, 100}, {30, 200}, white, sound8);
Button padButt9({255, 140}, {30, 200}, white, sound9);
Button padButt10({255, 180}, {30, 200}, white, sound10);
Button padButt11({255, 220}, {30, 200}, white, sound11);
Button padButt12({255, 260}, {30, 200}, white, sound12);
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
        case padInit:
            displayPadInit();
            break;
        case saveNew:
            displaySaveNew();
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
    initButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(165, 50);
    for (int i = 0; i < mainTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, mainTitle[i]);
    }
}

void displayNewKit() {
    newButt1.draw();newButt2.draw();newButt3.draw();newButt4.draw();newButt5.draw();

    exitButt.draw();doneButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(185, 50);
    for (int i = 0; i < newKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, newKitTitle[i]);
    }
    if (padError) {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2i(145, 100);
        for (int i = 0; i < padErrorMessage.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, padErrorMessage[i]);
        }
    }
}

void displayPadInit() {
    padButt1.draw();padButt2.draw();padButt3.draw();padButt4.draw();padButt5.draw();
    padButt6.draw();padButt7.draw();padButt8.draw();padButt9.draw();padButt10.draw();
    padButt11.draw();padButt12.draw();

    backButt.draw();
}

void displaySaveNew() {
    slButt0.draw();slButt1.draw();slButt2.draw();slButt3.draw();slButt4.draw();
    slButt5.draw();slButt6.draw();slButt7.draw();slButt8.draw();slButt9.draw();
}

void displayOpenKit() {
    slButt0.draw();slButt1.draw();slButt2.draw();slButt3.draw();slButt4.draw();
    slButt5.draw();slButt6.draw();slButt7.draw();slButt8.draw();slButt9.draw();

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(180, 50);
    for (int i = 0; i < openKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, openKitTitle[i]);
    }
}

void displayDeleteKit() {
    slButt0.draw();slButt1.draw();slButt2.draw();slButt3.draw();slButt4.draw();
    slButt5.draw();slButt6.draw();slButt7.draw();slButt8.draw();slButt9.draw();

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(180, 50);
    for (int i = 0; i < deleteKitTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, deleteKitTitle[i]);
    }
}

void displaySounds() {
    soundButt1.draw();soundButt2.draw();

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < soundsTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, soundsTitle[i]);
    }
}

void displayPlay() {

    exitButt.draw();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(175, 50);
    for (int i = 0; i < playTitle.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, playTitle[i]);
    }
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(175, 250);
    for (int i = 0; i < form_play_string(currentKit).length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, form_play_string(currentKit)[i]);
    }
}

void set_pad_init(int i, bool p) {
    switch (i) {
        case 0:
            pad0init = p;
        case 1:
            pad1init = p;
        case 2:
            pad2init = p;
        case 3:
            pad3init = p;
        case 4:
            pad4init = p;
    }
}
void init_pad_init() {
    pad0init = false;
    pad1init = false;
    pad2init = false;
    pad3init = false;
    pad4init = false;
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
                temp.refresh();
                init_pad_init();
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
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && initButt.overlap(x, y)) {
                // initialize button function
                temp.initialize_save();
            }
            break;
        case newKit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && exitButt.overlap(x, y)) {
                // button X function
                screen = mainMenu;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && newButt1.overlap(x, y)) {
                currentPad = 0;
                screen = padInit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && newButt2.overlap(x, y)) {
                currentPad = 1;
                screen = padInit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && newButt3.overlap(x, y)) {
                currentPad = 2;
                screen = padInit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && newButt4.overlap(x, y)) {
                currentPad = 3;
                screen = padInit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && newButt5.overlap(x, y)) {
                currentPad = 4;
                screen = padInit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && doneButt.overlap(x, y)) {
                // done button function
                if (pad0init && pad1init && pad2init && pad3init && pad4init) {
                    padError = false;
                    screen = saveNew;
                } else {
                    // error message "not all pads saved"
                    padError = true;
                }
            }
            break;
        case padInit:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && backButt.overlap(x, y)) {
                // back button function
                screen = newKit;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt1.overlap(x, y)) {
                // sound 1
                screen = newKit;
                temp.set_sound(currentPad, sound1);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt2.overlap(x, y)) {
                // sound 2
                screen = newKit;
                temp.set_sound(currentPad, sound2);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt3.overlap(x, y)) {
                // sound 3
                screen = newKit;
                temp.set_sound(currentPad, sound3);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt4.overlap(x, y)) {
                // sound 4
                screen = newKit;
                temp.set_sound(currentPad, sound4);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt5.overlap(x, y)) {
                // sound 5
                screen = newKit;
                temp.set_sound(currentPad, sound5);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt6.overlap(x, y)) {
                // sound 6
                screen = newKit;
                temp.set_sound(currentPad, sound6);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt7.overlap(x, y)) {
                // sound 7
                screen = newKit;
                temp.set_sound(currentPad, sound7);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt8.overlap(x, y)) {
                // sound 8
                screen = newKit;
                temp.set_sound(currentPad, sound8);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt9.overlap(x, y)) {
                // sound 9
                screen = newKit;
                temp.set_sound(currentPad, sound9);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt10.overlap(x, y)) {
                // sound 10
                screen = newKit;
                temp.set_sound(currentPad, sound10);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt11.overlap(x, y)) {
                // sound 11
                screen = newKit;
                temp.set_sound(currentPad, sound11);
                set_pad_init(currentPad, true);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && padButt12.overlap(x, y)) {
                // sound 12
                screen = newKit;
                temp.set_sound(currentPad, sound12);
                set_pad_init(currentPad, true);
            }
            break;
        case saveNew:
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && exitButt.overlap(x, y)) {
                // button X function
                screen = mainMenu;
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt0.overlap(x, y)) {
                // save and play kit 0
                screen = play;
                currentKit = 0;
                temp.set_save_ind(0);
                temp.save();
                temp.save_current_kit(0);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt1.overlap(x, y)) {
                // save and play kit 1
                screen = play;
                currentKit = 1;
                temp.set_save_ind(1);
                temp.save();
                temp.save_current_kit(1);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt2.overlap(x, y)) {
                // load kit 2
                screen = play;
                currentKit = 2;
                temp.set_save_ind(2);
                temp.save();
                temp.save_current_kit(2);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt3.overlap(x, y)) {
                // load kit 3
                screen = play;
                currentKit = 3;
                temp.set_save_ind(3);
                temp.save();
                temp.save_current_kit(3);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt4.overlap(x, y)) {
                // load kit 4
                screen = play;
                currentKit = 4;
                temp.set_save_ind(4);
                temp.save();
                temp.save_current_kit(4);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt5.overlap(x, y)) {
                // load kit 5
                screen = play;
                currentKit = 5;
                temp.set_save_ind(5);
                temp.save();
                temp.save_current_kit(5);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt6.overlap(x, y)) {
                // load kit 6
                screen = play;
                currentKit = 6;
                temp.set_save_ind(6);
                temp.save();
                temp.save_current_kit(6);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt7.overlap(x, y)) {
                // load kit 7
                screen = play;
                currentKit = 7;
                temp.set_save_ind(7);
                temp.save();
                temp.save_current_kit(7);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt8.overlap(x, y)) {
                // load kit 8
                screen = play;
                currentKit = 8;
                temp.set_save_ind(8);
                temp.save();
                temp.save_current_kit(8);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt9.overlap(x, y)) {
                // load kit 9
                screen = play;
                currentKit = 9;
                temp.set_save_ind(9);
                temp.save();
                temp.save_current_kit(9);
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
                temp = temp.load(0);
                temp.save_current_kit(0);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt1.overlap(x, y)) {
                // load kit 1
                screen = play;
                currentKit = 1;
                temp = temp.load(1);
                temp.save_current_kit(1);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt2.overlap(x, y)) {
                // load kit 2
                screen = play;
                currentKit = 2;
                temp = temp.load(2);
                temp.save_current_kit(2);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt3.overlap(x, y)) {
                // load kit 3
                screen = play;
                currentKit = 3;
                temp = temp.load(3);
                temp.save_current_kit(3);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt4.overlap(x, y)) {
                // load kit 4
                screen = play;
                currentKit = 4;
                temp = temp.load(4);
                temp.save_current_kit(4);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt5.overlap(x, y)) {
                // load kit 5
                screen = play;
                currentKit = 5;
                temp = temp.load(5);
                temp.save_current_kit(5);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt6.overlap(x, y)) {
                // load kit 6
                screen = play;
                currentKit = 6;
                temp = temp.load(6);
                temp.save_current_kit(6);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt7.overlap(x, y)) {
                // load kit 7
                screen = play;
                currentKit = 7;
                temp = temp.load(7);
                temp.save_current_kit(7);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt8.overlap(x, y)) {
                // load kit 8
                screen = play;
                currentKit = 8;
                temp = temp.load(8);
                temp.save_current_kit(8);
            } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && slButt9.overlap(x, y)) {
                // load kit 9
                screen = play;
                currentKit = 9;
                temp = temp.load(9);
                temp.save_current_kit(9);
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