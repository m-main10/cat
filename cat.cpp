//
// Created by Misha on 11.08.2026.
//
#pragma once

#include "main.cpp"
class Cat:public  CatSys {
    Cat(float thinc =3,float x=0,float y=0,Color c=WHITE) {
        NewThickness(thinc);
        NewColor(c);
        move(x,y);


    }
    void forward(float distanse) {
        BeginDrawing();
        sforward((int)distanse);
        EndDrawing();
        BeginDrawing();
        sforward((int)distanse);
        EndDrawing();

    }
    void backward(float distanse) {
        BeginDrawing();
        sbackward((int)distanse);
        EndDrawing();
        BeginDrawing();
        sbackward((int)distanse);
        EndDrawing();
    }
    void circle(float radius) {
        BeginDrawing();
        scircle(radius);
        EndDrawing();
        BeginDrawing();
        scircle(radius);
        EndDrawing();
    }
    void square(float radius) {
        BeginDrawing();
        for (int i=0;i<4;i++) {
            forward(radius);
            right(90);
        }
        EndDrawing();
        BeginDrawing();
        for (int i=0;i<4;i++) {
            forward(radius);
            right(90);
        }
        EndDrawing();


    }
    
};