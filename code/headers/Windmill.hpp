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

#ifndef WINDMILL_BOX2DANIMATION
#define WINDMILL_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "RotationTorque.hpp"


namespace Box2DAnimation
{


    class World;
    class Body;

    /*
    * Se encarga de crear un molino
    */
    class Windmill
    {

    private:


        b2Vec2 center; ///< Centro del molino

        float torqueSpeed; ///< Velocidad de giro

        std::vector<RotationTorque *> torques; ///< Motor de giro

        Body * stick; ///< Palo del molino

        bool eneabled; ///< Si esta funcionando

        float time = 0; ///< Tiempo que lleva activado

        float animationTime = 6.0f; ///< Duracion de la animacion

    public:

        /*
        * Crea el molino
        */
        Windmill(b2Vec2 center, Body * Stick, std::vector<Body *> Bodies);

        /*
        * Ciclo de render
        */
        void render(sf::RenderWindow& renderWindow);

        /*
        * Ciclo de update
        */
        void update(float time);

        /*
        * EMpieza a girar
        */
        void startTorque();

        /*
        * Para de girar
        */
        void stopTorque();

        /*
        * Determina la velocidad de giro
        */
        void setTorqueSpeed(float speed);

        /*
        * Determina si esta funcionando o no
        */
        inline bool isEneabled() { return eneabled; };

    };


}

#endif