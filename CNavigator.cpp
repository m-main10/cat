//
// Created by Misha on 30.07.2026.
//

#include  "Vec2d.h"
#include<cmath>
#define pi 3.1415926
class CNavigator {
private:
    float ygol;
public:

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
        if (ygol < 0.0f) {
            ygol = fmodf(ygol, 360.0f);
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
