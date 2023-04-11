#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"

Engine* Engine::s_Instance = nullptr;

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

        window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    TextureManager::GetInstance()->Load("Mockup", "Asset/Mockup.png");


   return m_IsRunning = true;
}

bool Engine::Clean()
{
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}


void Engine::Update()
{
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(renderer, 174, 218, 254, 255);
    SDL_RenderPresent(renderer);
    TextureManager::GetInstance()->Draw("Mockup", 0, 0, 1600, 400);
    SDL_RenderPresent(renderer);
}

void Engine::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        Quit(); break;
    }

}
void Engine::Quit()
{
    m_IsRunning = false;
}
