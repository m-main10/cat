//
// Created by Misha on 11.08.2026.
//
#pragma once
#include "raylib.h"
#include <thread>
using namespace std;
using namespace std::chrono;
class Vec2d {
private:
    float x,y;

public:
    void move(float x,float y) {
        this->x=x;
        this->y=y;

    }
    float xcor() {
        return this->x;
    }
    float ycor() {
        return this->y;
    }

};
#include<cmath>
#define pi 3.1415926
class CNavigator {
public:
    float ygol=0.0f;

    Vec2d math_line(Vec2d pos,float fd) {
        float rd = ygol*(pi/180);
        float xnew=pos.xcor()+fd*cosf(rd);
        float ynew=pos.ycor()+fd*sinf(rd);
        Vec2d r;
        r.move(xnew,ynew);
        return r;
    }
    CNavigator(float start_ygol = 90.0f) : ygol(start_ygol) {}
    void left(float new_ygol) {
        ygol+=new_ygol;
        ygol = fmodf(ygol, 360.0f);
        if (ygol < 0.0f) {
            ygol += 360.0f;
        }
    }

    void right(float new_ygol){
        ygol-=new_ygol;
        ygol = fmodf(ygol, 360.0f);
        if (ygol < 0.0f) {
            ygol += 360.0f; // Переводим отрицательный угол в положительный эквивалент
        }
    }

};

class CPen {
public:
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
        pos=r;
    }
    void Dbackward(float fd) {
        Dforward(-fd);
    }
    Color color_ret() {
        return cp;

    }


};
class Screen {

public:
    Screen(int width, int height, const char * name) {
        InitWindow(width, height, name);

        // Очищаем экран цветом

    }
    void ScreenUpdate() {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    ~Screen() {
        CloseWindow();

    }

};
class RawCat : public CPen, public  CNavigator,public  Vec2d {
public:
    void circle(float radius) {
        DrawCircle((int)xcor(),(int)ycor(),radius,color_ret());

    }
    void forward(int fd) {
        float steps = (float)fd / 10.0f;
        for (int i=0;i<fd/10;i++) {
            Dforward(steps);

        }

        move(pos.xcor(),pos.ycor());


    }
    void backward(int fd) {
        forward(-fd);

    }

};
class CatSys:public RawCat {
public:
    Cat(float thinc =3,float x=0,float y=0,Color c=WHITE) {
        NewThickness(thinc);
        NewColor(c);
        move(x,y);


    }
    void Update() {
        DrawCircle((int)xcor(),(int)ycor(),3.2f,color_ret());
    }
};
