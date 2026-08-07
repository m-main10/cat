//
// Created by Misha on 31.07.2026.
//

#include "raylib.h"
class Screen {

   public:
   Screen(int width, int height, char * name) {
      InitWindow(width, height, name);


   }
   ~Screen() {
      CloseWindow();

   }
};
