//
// Created by Kevin Flood on 4/16/18.
//

#include <string>
#include <vector>
using namespace std;

#ifndef PIDRUM_SAVELOAD_H
#define PIDRUM_SAVELOAD_H


class SaveLoad {
private:
    int saveInd;
    bool empty;
    string saveName;
    string pad0;
    string pad1;
    string pad2;
    string pad3;
    string pad4;

public:
    SaveLoad();
    SaveLoad(int si);
    SaveLoad(int si, string p0, string p1, string p2, string p3, string p4);

    int get_save_ind();
    bool get_empty();
    string get_save_name();
    string get_sound(int ind);

    void set_save_ind(int newSI);
    void set_empty(bool newE);
    void set_save_name(string newN);
    void set_sound(int ind, string s);

    void save();
    SaveLoad load(int ind);
    void delete_save(int si);
    void save_current_kit(int ind);

    void initialize_save();
    void refresh();
};

#endif //PIDRUM_SAVELOAD_H
