#include "TextureManager.h"
#include <iostream>
#include "Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if(surface == nullptr) {
        std::cout << "Failed to load texture: " << filename.c_str() << SDL_GetError();
            return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
    if(texture==nullptr) {
        std::cout << "Failed to create texture from surface: " << SDL_GetError();
        return false;
    }

    m_TextureMap[id] = texture;
    return true;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(),m_TextureMap[id], &srcRect, &dstRect, 0 /*rotate*/, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame,  SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {width*frame, height*(row-1), width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(),m_TextureMap[id], &srcRect, &dstRect, 0 /*rotate*/, nullptr, flip);
}

void TextureManager::DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip)
 {
     SDL_Rect dstRect = { x, y, tileSize, tileSize} ;
     SDL_Rect srcRect = { tileSize*frame, tileSize*(row-1), tileSize, tileSize};
     SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[tilesetID], &srcRect, &dstRect, 0, 0 , flip);
 }

void TextureManager::Drop(std::string id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}
void TextureManager::Clean()
{
    std::map <std::string, SDL_Texture*>::iterator it;
    for(it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
    SDL_DestroyTexture(it->second);

    m_TextureMap.clear();
    SDL_Log("texture map cleaned!");
}
