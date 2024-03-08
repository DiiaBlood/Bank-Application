#include <iostream>
#include "../include/raylib.h"

// We include the windows header in a namespace as to not collide with Raylib
using std::cout, std::endl;
namespace windows{
    #include "windows.h"
}

#include "Core.hpp"

class ItemList{ 
    private:
        // UI
        Rectangle Bounds = {0, 0, 0, 0}; Vector2 Scroll = {0, 0};
        Rectangle ViewBounds = {0, 0, 0, 0}; int Depth = 0;
        Rectangle View = {0, 0, 0, 0}; std::string Title;
        float Button_Height = 30; float Button_ID_Width = 50;
        float Vertical_Distance = 10; float Horizontal_Distance = 10;

        // Backend
        List* Items;
    public:
        void SetBounds(Rectangle _Bounds);
        void SetDepth(int _Depth);
        void SetTitle(std::string _Title);

        int SetData(List* Data);

        int Add_Item(Node NewUser);
        long Render();
};