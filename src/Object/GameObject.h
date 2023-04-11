#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "IObject.h"
#include "Transform.h"

struct Properties {
    std::string TextureID;
    float X, Y;
    int Width, Height;
    SDL_RendererFlip Flip;

    Properties(std::string textureID, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
    {
        X =x;
        Y =y;
        Flip = flip;
        Width = width;
        Height = height;
        TextureID = textureID;
    }

};

class GameObject: public IObject
{
    public:
        GameObject(Properties* props) m_TextureID(props->TextureID), m_Width(props->Width),
                                      m_Height(props->Height), m_Flip(props->Flip)
    { m_Transfrom = new Transform(props->X, props->Y); }

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

    protected:
        Transform* m_Transfrom;
        int m_Width, m_Height;
        std::string m_TextureID;
        SDL_RendererFlip m_Flip;
};

#endif // GAMEOBJECT_H
