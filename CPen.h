//
// Created by Misha on 31.07.2026.
//

#ifndef M_CPEN_H
#define M_CPEN_H
#include  "raylib.h"
#include "CNaovigator.h"
#include "Vec2d.h"
class CPen {
private:
    CNavigator cn;
    Vec2d pos;
    Color cp;
    float  thick;
public:
    void NewColor(Color color) {
        cp = color;

    }
    CPen() {
        cp = BLACK;
    }
    void NewThickness(float thick_new) {
        thick = thick_new;
    }
    void Dforward(float fd) {
    }
    void Dbackward(float fd) {
    }
    Color color_ret() {
        

    }

};
#endif //M_CPEN_H
