// © Copyright (C) 2020  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef ROTATIONTORQUE_BOX2DANIMATION
#define ROTATIONTORQUE_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "StaticBody.hpp"


namespace Box2DAnimation
{


    class World;
    class Body;

    /*
    * Motor de rotacion
    */
    class RotationTorque
    {

    private:

        float radius; ///< Radio del motor

        b2CircleShape circle; ///< Figura que representa el motor

        b2RevoluteJoint* torqueJoin; ///< Motor de giro

        World * world; ///< Mundo al que pertenece

        sf::Shape * sfml_shape; ///< Shape de SFML

    public:

        /*
        * Creacion de motor de rotacion
        */
        RotationTorque(float r, Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb);

        /*
        * Ciclo de render
        */
        void render(sf::RenderWindow& renderWindow);

        /*
        * CIclo de update
        */
        void update(float time);

        /*
        * Une los cuerpos
        */
        void setJointBodies(Body& A, Body& B, b2Vec2 center);

        /*
        * Determina la velocidad de giro
        */
        inline void setSpeed(float speed)
        {
            torqueJoin->SetMotorSpeed(speed);
        }
        
        /*
        * ACtiva el motor
        */
        inline void eneableMotor(bool eneable)
        {
            torqueJoin->EnableMotor(eneable);
        }

        /*
        * Devuelve el palo
        */
        inline b2Body * getDynamicBody()
        {
            return torqueJoin->GetBodyB();
        }

    };


}

#endif