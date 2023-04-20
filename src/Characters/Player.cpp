#include "Player.h"
#include "TextureManager.h"
#include "Animation.h"
#include "InputHandler.h"

Player::Player(Properties* props) : Character(props)
{
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 6, 100, SDL_FLIP_NONE);
}

void Player::Draw()
{
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Player::Update(float dt)
{
    m_Animation->SetProps("wizard", 1, 6, 150);

    m_RigidBody->UnsetForce();

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_J)) {
        m_Animation->SetProps("attack", 1, 8, 100);
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_SPACE)) {
            m_RigidBody->ApplyForceY(5*UPWARD);
            m_Animation->SetProps("jump", 1, 2, 100);

        }
    //
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
        m_RigidBody->ApplyForceX(3*FORWARD);
        m_Animation->SetProps("run", 1, 8, 200);
    }

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
        m_RigidBody->ApplyForceX(3*BACKWARD);
        m_Animation->SetProps("run", 1, 8, 200, SDL_FLIP_HORIZONTAL);
    }

    m_RigidBody->Update(dt);


    m_Transform->TranslateX( m_RigidBody->Position().X);

   m_Animation->Update();
}

void Player::Clean()
{
    TextureManager::GetInstance()->Clean();
}
