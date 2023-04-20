#ifndef ENGINE_H
#define ENGINE_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "GameMap.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 600;
const std::string WINDOW_TITLE = "Forest";

class Engine
{
    public:
     static Engine* GetInstance()
      {
          return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
      }
      bool Init();
      bool Clean();
      void Quit();

      void Update();
      void Render();
      void Events();

      bool IsRunning() { return m_IsRunning;}

      SDL_Renderer* GetRenderer() { return renderer; }

    private:
        Engine(){};
        bool m_IsRunning;

        GameMap *m_LevelMap;
        SDL_Window *window;
        SDL_Renderer *renderer;

        static Engine* s_Instance;
};

#endif // ENGINE_H
