//
// Created by Kevin Flood on 4/16/18.
//

#include <vector>
using namespace std;

#ifndef PIDRUM_SAVELOAD_H
#define PIDRUM_SAVELOAD_H


class SaveLoad {
private:
    int saveInd;
    bool empty;
    vector<int> sounds;

public:
    SaveLoad();
    SaveLoad(int si, bool e);

    int get_save_ind();
    bool get_empty();
    vector<int> get_sounds();

    void set_save_ind(int newSI);
    void set_empty(bool newE);
    void set_sound(int si, int newS);
    void set_sounds(vector<int> newS);

    void save();
    void delete_save()
};

#endif //PIDRUM_SAVELOAD_H
