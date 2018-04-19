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
}
SaveLoad::SaveLoad(int si, vector<int> ss) {
    saveInd = si;
    sounds = ss;
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

void SaveLoad::save() {
    ofstream f_out1("pidrumsaves.txt");
    if (f_out1) {
        f_out1 << "Pi Drum Saves" << endl;
    }
    f_out1.close();
}

void SaveLoad::load() {
    // start streaming the file
    ifstream piDrumFile("pidrumsaves.txt");
    //initialize variables
    string info;
    string junk;

    // clear junk at top of list
    getline(piDrumFile, info);

    while (piDrumFile) {
        // get values from file
        getline(piDrumFile, junk, ';');
    }
    cout << "Save " << saveInd << " has been loaded" << endl;
}

void SaveLoad::delete_save(int si) {

}

void SaveLoad::initialize_save() {
    ofstream f_out1("pidrumsaves.txt");
    if (f_out1) {
        for (int i=0; i<10; ++i) {
            f_out1 << i << " 0 0 0 0 0" << endl;
        }
    }
    f_out1.close();
}