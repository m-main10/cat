//
// Created by Misha on 30.07.2026.
//
#include  "Vec2d.h"
#include<cmath>
#define pi 3.1415926
class CNavigator {
private:
  float ygol;
  Vec2d math_line(Vec2d pos,float fd) {
      float rd = ygol*(pi/180);
      float xnew=pos.xcor()+fd*cosf(rd);
      float ynew=pos.ycor()+fd*sinf(rd);
      Vec2d r;
      r.move(xnew,ynew);
      return r;

  }
   public:
    
};