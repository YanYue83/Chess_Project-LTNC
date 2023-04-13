#include "Engine.h"
#include "Timer.h"

using namespace std;

// const int SCREEN_WIDTH = 1080;
// const int SCREEN_HEIGHT = 800;
// const string WINDOW_TITLE = "Forest";

int main(int argc, char* argv[])
{

    Engine::GetInstance()->Init();
    while(Engine::GetInstance()->IsRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        Timer::GetInstance()->Tick();
    }
    Engine::GetInstance()->Clean();

    return 0;
}
