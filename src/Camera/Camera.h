#ifndef CAMERA_H
#define CAMERA_H

#include "SDL.h"
#include "Point.h"
#include "Vector_2D.h"

class Camera
{
    public:
        static Camera* GetInstance() {return s_Instance = (s_Instance != nullptr)? s_Instance : new Camera();}
        void Update(float dt);
        SDL_Rect GetViewBox() { return m_ViewBox; }
        Vector2D GetPosition() { return m_Position; }
        void SetTarget(Point * target) { m_Target = target;}

    private:
        Camera() { m_ViewBox = {0, 0, SCREEN_HEIGHT, SCREEN_WIDTH}; }

        Point *m_Target;
        Vector2D m_Position;
        SDL_Rect m_ViewBox;
        static Camera* s_Instance;
};

#endif // CAMERA_H
