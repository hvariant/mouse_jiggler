#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

void jiggle(int dx, int dy);

int main(void)
{
   std::cout << "Sending good vibrations..." << std::endl;

   while (true)
   {
      using namespace std::chrono_literals;

      jiggle(1, 1);
      std::this_thread::sleep_for(10ms);
      jiggle(-1, -1);
      std::this_thread::sleep_for(10ms);
   }

   return 0;
}

void jiggle(int dx, int dy)
{
   auto mouse_input = std::make_unique<INPUT>();
   mouse_input->type = INPUT_MOUSE;
   mouse_input->mi.dx = dx;
   mouse_input->mi.dy = dy;
   mouse_input->mi.mouseData = 0;
   mouse_input->mi.dwFlags = MOUSEEVENTF_MOVE;
   mouse_input->mi.time = 0;
   mouse_input->mi.dwExtraInfo = 0;

   // info on the third argument:
   //    The size, in bytes, of an INPUT structure.
   //    If cbSize is not the size of an INPUT structure, the function fails.
   SendInput(1, mouse_input.get(), sizeof(INPUT));
}
