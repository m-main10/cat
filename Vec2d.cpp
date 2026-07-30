//
// Created by Misha on 30.07.2026.
//

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