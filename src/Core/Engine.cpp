#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"

#include "Player.h"
#include "InputHandler.h"
#include "Timer.h"
#include "MapParser.h"

Engine* Engine::s_Instance = nullptr;
Player* P = nullptr;

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) logSDLError(std::cout, "SDL_Init", true);

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

        window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

//load anh
    if(MapParser::GetInstance()->Load()) {
        std::cout << "Failed to load map" <<std::endl;
    }
    m_LevelMap = MapParser::GetInstance()->GetMaps("forest");

    TextureManager::GetInstance()->Load("wizard", "Asset/Wizard Pack/Idle.png");
    TextureManager::GetInstance()->Load("run", "Asset/Wizard Pack/Run.png");
    TextureManager::GetInstance()->Load("attack", "Asset/Wizard Pack/Attack2.png");
    TextureManager::GetInstance()->Load("jump", "Asset/Wizard Pack/Jump.png");
    TextureManager::GetInstance()->Load("fall", "Asset/Wizard Pack/Fall.png");

    P = new Player(new Properties("wizard", 1, 1, 231, 190));


    //TextureManager::GetInstance()->Load("bg", "Asset/Mockup.png");

    Transform tf;
    tf.Log();
   return m_IsRunning = true;
}

void Engine::Update()
{
    float dt = Timer::GetInstance()->GetDeltaTime();
    m_LevelMap->Update();
    P->Update(dt);
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(renderer, 174, 218, 254, 255);
    SDL_RenderPresent(renderer);

    //TextureManager::GetInstance()->Draw("bg", 0 , 0, 1600, 400);
    m_LevelMap->Render();
    P->Draw();

    SDL_RenderPresent(renderer);
}

void Engine::Events()
{
    Input::GetInstance()->Listen();
}
bool Engine::Clean()
{
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit()
{
    m_IsRunning = false;
}
