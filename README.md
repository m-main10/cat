# Cat Graphics System

Простая графическая система на C++ для рисования с использованием библиотеки **raylib**. Проект предоставляет классы для управления "черепашьей графикой" (turtle graphics), где объект `Cat` перемещается по экрану и рисует линии.

## Описание

Этот проект реализует систему классов для создания графики:

- **Vec2d** — базовый класс для работы с 2D координатами
- **CNavigator** — управляет направлением и углом движения
- **CPen** — отвечает за рисование линий с настройкой цвета и толщины
- **Screen** — управление окном приложения
- **RawCat** — наследует возможности рисования и навигации
- **CatSys** — основной класс для использования в программах

## Требования

- Компилятор C++ (g++, clang++)
- Библиотека [raylib](https://www.raylib.com/)
- CMake (опционально)

## Установка зависимостей

### Linux (Ubuntu/Debian)
```bash
sudo apt-get install libraylib-dev
```

### Windows
Скачайте raylib с официального сайта или используйте vcpkg:
```bash
vcpkg install raylib
```

### macOS
```bash
brew install raylib
```

## Сборка

### С помощью g++
```bash
g++ -o main main.cpp -lraylib -lopengl32 -lgdi32 -lwinmm  # Windows
g++ -o main main.cpp -lraylib -lpthread -ldl -lrt -lX11   # Linux
g++ -o main main.cpp -framework OpenGL -framework Cocoa -lraylib  # macOS
```

### С помощью CMake
```bash
mkdir build
cd build
cmake ..
make
```

## Использование

```cpp
#include "main.cpp"

int main() {
    // Создание окна
    Screen screen(800, 600, "Cat Graphics");
    
    // Создание объекта Cat
    CatSys cat(3.0f, 400.0f, 300.0f, BLACK);
    
    // Основной цикл
    while (!WindowShouldClose()) {
        screen.ScreenUpdate();
        
        // Рисование
        cat.forward(100);
        cat.left(90);
        cat.forward(100);
        cat.Update();
        
        BeginDrawing();
        EndDrawing();
    }
    
    return 0;
}
```

## Основные методы класса CatSys

| Метод | Описание |
|-------|----------|
| `forward(int distance)` | Движение вперед на указанное расстояние |
| `backward(int distance)` | Движение назад |
| `left(float angle)` | Поворот влево на указанный угол (в градусах) |
| `right(float angle)` | Поворот вправо |
| `NewColor(Color color)` | Установка цвета пера |
| `NewThickness(float thickness)` | Установка толщины линии |
| `circle(float radius)` | Рисование круга |
| `Update()` | Отрисовка текущего положения |

## Примеры фигур

### Квадрат
```cpp
for (int i = 0; i < 4; i++) {
    cat.forward(100);
    cat.right(90);
}
```

### Треугольник
```cpp
for (int i = 0; i < 3; i++) {
    cat.forward(100);
    cat.left(120);
}
```

### Круг
```cpp
for (int i = 0; i < 360; i++) {
    cat.forward(1);
    cat.left(1);
}
```

## Лицензия

Проект распространяется под лицензией, указанной в файле [LICENSE](LICENSE).

## Авторы

- Misha (создатель проекта)

## Примечания

- Углы измеряются в градусах
- Начальное направление — 90 градусов (вверх)
- Координатная система: X вправо, Y вверх
