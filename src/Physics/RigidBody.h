#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector_2D.h"

const float UNI_MASS = 1.0f;
const float GRAVITY = 9.8f;
const float FORWARD = 1;
const float BACKWARD = -1;
const float UPWARD = -1;
const float DOWNWARD = +1;

class RigidBody
{
    public:
        RigidBody() {
            m_Mass = UNI_MASS;
            m_Gravity = GRAVITY;
        }

        void SetMass(float mass) { m_Mass = mass; }
        void SetGravity(float grav) { m_Gravity = grav;}
        //Luc
        void ApplyForce(Vector2D F) { m_Force = F;}
        void ApplyForceX(float Fx ) { m_Force.X = Fx;}
        void ApplyForceY(float Fy ) { m_Force.Y = Fy;}
        void UnsetForce() { m_Force = Vector2D(0,0);}

        //Friction
        void ApplyFriction(Vector2D Fr) { m_Friction = Fr;}
        void UnsetFriction() { m_Friction = Vector2D(0,0);}

        //update changes
        float GetMass() {return m_Mass;}
        Vector2D Position() { return m_Position;}
        Vector2D Velocity() { return m_Velocity;}
        Vector2D Accelaration() { return m_Accelaration;}

        //calculate
        void Update(float const dt) {
            m_Accelaration.X = (m_Force.X+ m_Friction.X)/m_Mass;
            m_Accelaration.Y = m_Gravity + m_Force.Y/m_Mass;
            m_Velocity = m_Accelaration*dt;
            m_Position = m_Velocity*dt;
        }

    private:
        float m_Mass;
        float m_Gravity;

        Vector2D m_Force;
        Vector2D m_Friction;

        Vector2D m_Position;
        Vector2D m_Velocity;
        Vector2D m_Accelaration;
};

#endif // RIGIDBODY_H
