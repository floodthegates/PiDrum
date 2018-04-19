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
    vector<int> sounds;

public:
    SaveLoad();
    SaveLoad(int si, vector<int> ss);


    int get_save_ind();
    bool get_empty();
    string get_save_name();
    vector<SaveLoad> vectSaves();

    void set_save_ind(int newSI);
    void set_empty(bool newE);
    void set_save_name(string newN);

    void save();
    void load();
    void delete_save(int si);

    void initialize_save();
};

#endif //PIDRUM_SAVELOAD_H
