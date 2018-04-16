//
// Created by Kevin Flood on 4/16/18.
//

#include "SaveLoad.h"

// SaveLoad constructors
SaveLoad::SaveLoad() {
    saveInd = 10;
}
SaveLoad::SaveLoad(int si, bool e) {
    saveInd = si;
    empty = e;
}

// SaveLoad getters
int SaveLoad::get_save_ind() {
    return saveInd;
}
bool SaveLoad::get_empty() {
    return empty;
}
vector<int> SaveLoad::get_sounds() {
    return sounds;
}

// SaveLoad setters
void SaveLoad::set_save_ind(int newSI) {
    saveInd = newSI;
}
void SaveLoad::set_empty(bool newE) {
    empty = newE;
}
void SaveLoad::set_sound(int si, int newS) {
    sounds[si] = newS;
}
void SaveLoad::set_sounds(vector<int> newS) {
    for (int i=0; i<sounds.size(); ++i) {
        sounds[i] = newS[i];
    }
}