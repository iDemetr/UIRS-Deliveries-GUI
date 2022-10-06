//#include "resource.h"
#include "MyForm1.h"
#include <Windows.h>

using namespace Project1;  								//Имя проекта!

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);
    return 0;
}