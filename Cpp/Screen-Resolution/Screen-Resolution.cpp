﻿#include "Screen-Resolution.h"

void set_resolution(int width, int height)
{
    //定义DEVMODE结构体变量
    DEVMODE NewDevMode;

    //EnumDisplaySettings函数得到显示设备的一个图形模式设备，通过对该函数一系列的调用可以得到显示设备所有的图形模式信息。
    EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);

    std::cout << "Current: " << NewDevMode.dmPelsWidth << "x" << NewDevMode.dmPelsHeight << "    " << NewDevMode.dmDisplayFrequency << "Hz\n" << std::endl;

    //修改下DEVMODE相关成员变量的值
    NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    NewDevMode.dmPelsWidth = width;
    NewDevMode.dmPelsHeight = height;
    NewDevMode.dmDisplayFixedOutput = 0;
    std::cout << "Target: " << NewDevMode.dmPelsWidth << "x" << NewDevMode.dmPelsHeight << std::endl;
    ChangeDisplaySettings(&NewDevMode, 0);
    std::cout << "\nSetting done." << std::endl;
}

int main(int argc, char** argv)
{
    int w, h;
    std::cout << "" << std::endl;
    if (argc == 3)
    {
        w = atoi(argv[1]);
        h = atoi(argv[2]);
        set_resolution(w, h);
    }
    else
    {
        std::cout << "Invalid arguments, have nothing to do...\nUseage: [Width] [Height]" << std::endl;
    }
    std::cout << "\nPress any key to exit..." << std::endl;
    system("pause>nul");
    return 0;
}
