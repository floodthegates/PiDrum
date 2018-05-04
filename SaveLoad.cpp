//
// Created by Kevin Flood on 4/16/18.
//

#include "SaveLoad.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

// SaveLoad constructors
SaveLoad::SaveLoad() {
    saveInd = 10;
    pad0 = "";
    pad1 = "";
    pad2 = "";
    pad3 = "";
    pad4 = "";
}
SaveLoad::SaveLoad(int si) {
    saveInd = si;
    pad0 = "";
    pad1 = "";
    pad2 = "";
    pad3 = "";
    pad4 = "";
}
SaveLoad::SaveLoad(int si, string p0, string p1, string p2, string p3, string p4) {
    saveInd = si;
    pad0 = p0;
    pad1 = p1;
    pad2 = p2;
    pad3 = p3;
    pad4 = p4;
}

// SaveLoad getters
int SaveLoad::get_save_ind() {
    return saveInd;
}
bool SaveLoad::get_empty() {
    return empty;
}
string SaveLoad::get_save_name() {
    return saveName;
}
string SaveLoad::get_sound(int ind) {
    switch (ind) {
        case 0:
            return pad0;
        case 1:
            return pad1;
        case 2:
            return pad2;
        case 3:
            return pad3;
        case 4:
            return pad4;
    }
    return "error";
}

/*
vector<SaveLoad> SaveLoad::vectSaves(){

    //Creates vector
    vector<SaveLoad> a;

    //Opens in-file
    ifstream saveFile("SaveData.txt");

    if (!saveFile){

        initialize_save();
        //open infile again since it failes the first time
        ifstream saveFile("SaveData.txt");

    }

    //Initialize variables
    int si = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    vector<int> ss;
    string junk;

    //loops through each line of the file and inserts the Player object into a vector
    while (saveFile && saveFile.peek()!= EOF) {
        saveFile >> si >> s0 >> s1 >> s2 >> s3 >> s4;
        ss.push_back(s0); ss.push_back(s1); ss.push_back(s2); ss.push_back(s3); ss.push_back(s4);
        //Inserts the current variable values into a vector
        a.push_back(SaveLoad(si, ss));
        getline(saveFile, junk);
    }
    //closes file
    saveFile.close();

    //Return the vector so that it can be presented to the user
    return a;


}
*/

// SaveLoad setters
void SaveLoad::set_save_ind(int newSI) {
    saveInd = newSI;
}
void SaveLoad::set_empty(bool newE) {
    empty = newE;
}
void SaveLoad::set_save_name(string newN) {
    saveName = newN;
}
void SaveLoad::set_sound(int ind, string s) {
    switch (ind) {
        case 0:
            pad0 = s;
        case 1:
            pad1 = s;
        case 2:
            pad2 = s;
        case 3:
            pad3 = s;
        case 4:
            pad4 = s;
    }
}

void SaveLoad::save() {

    vector<SaveLoad> b;

    //Opens in-file
    ifstream saveFile("pidrumsaves.txt");

    //Initialize variables
    int si;
    string p0, p1, p2, p3, p4;
    string junk;

    //loops through each line of the file and inserts the Player object into a vector
    while (saveFile && saveFile.peek()!= EOF) {
        saveFile >> si >> p0 >> p1 >> p2 >> p3 >> p4;

        //Inserts the current variable values into a vector
        b.push_back(SaveLoad(si, p0, p1, p2, p3, p4));
        getline(saveFile, junk);
    }
    //closes file
    saveFile.close();

    //change vector to include new save information
    for (int i = 0; i < b.size(); i++) {
        if (saveInd == b[i].get_save_ind()) {
            b[i].set_sound(0, pad0);
            b[i].set_sound(1, pad1);
            b[i].set_sound(2, pad2);
            b[i].set_sound(3, pad3);
            b[i].set_sound(4, pad4);
        }
    }

    ofstream f_out1("pidrumsaves.txt");
    for(int i = 0; i < 10; i++){
        f_out1 << i << " " << b[i].pad0 << " " << b[i].pad1 << " " << b[i].pad2
               << " " << b[i].pad3 << " " << b[i].pad4 << endl;
    }
    f_out1.close();
    cout << saveInd << " has been saved" << endl;
}

SaveLoad SaveLoad::load(int ind) {
    // start streaming the file
    ifstream piDrumFile("pidrumsaves.txt");

    //Initialize variables
    int si;
    string p0, p1, p2, p3, p4;
    SaveLoad a(ind);

    //loops through each line of the file and inserts the Player object into a vector
    while (piDrumFile && piDrumFile.peek()!= EOF) {
        piDrumFile >> si >> p0 >> p1 >> p2 >> p3 >> p4;
        if (si == ind) {
            a.set_sound(0, p0);
            a.set_sound(1, p1);
            a.set_sound(2, p2);
            a.set_sound(3, p3);
            a.set_sound(4, p4);
        }
    }
    cout << "Save " << a.saveInd << " has been loaded" << endl;
    return a;
}

void SaveLoad::delete_save(int si) {

}

void SaveLoad::save_current_kit(int ind) {
    ofstream f_out1("currentkit.txt");
    if (f_out1) {
        f_out1 << "Sounds/" << get_sound(0) << ".ogg" << endl
               << "Sounds/" << get_sound(1) << ".ogg" << endl
               << "Sounds/" << get_sound(2) << ".ogg" << endl
               << "Sounds/" << get_sound(3) << ".ogg" << endl
               << "Sounds/" << get_sound(4) << ".ogg";
    }
    f_out1.close();
}

void SaveLoad::initialize_save() {
    ofstream f_out1("pidrumsaves.txt");
    if (f_out1) {
        for (int i=0; i<10; ++i) {
            f_out1 << i << " pad0 pad1 pad2 pad3 pad4" << endl;
        }
    }
    f_out1.close();

    ofstream f_out2("currentkit.txt");
    if (f_out2) {
        for (int i=0; i<5; ++i) {
            f_out2 << "pad" << i << endl;
        }
    }
    f_out2.close();
}

void SaveLoad::refresh() {
    saveInd = 10;
    pad0 = "";
    pad1 = "";
    pad2 = "";
    pad3 = "";
    pad4 = "";
}