//
// Created by Misha on 31.07.2026.
//
#include "raylib.h"
#include "Vec2d.h"
#include "CNaovigator.h"
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
        Vec2d r =cn.math_line(pos,fd);
        DrawLineEx({pos.xcor(),pos.ycor()},{r.xcor(),r.ycor()},thick,cp);
    }
    void backward(float fd) {
        Dforward(-fd);
    }
    Color color_ret() {
        return cp;
        
    }

};
