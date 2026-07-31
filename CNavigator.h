//
// Created by Misha on 30.07.2026.
//

#ifndef M_CNAVIGATOR_H
#define M_CNAVIGATOR_H
class CNavigator {
private:
    float ygol;
public:
    // Конструктор
    CNavigator(float start_ygol = 90.0f);

    // Расчет линии движения
    Vec2d math_line(Vec2d pos, float fd);

    // Повороты
    void left(float new_ygol);
    void right(float new_ygol);
};
#endif
