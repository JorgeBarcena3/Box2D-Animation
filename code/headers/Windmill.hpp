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
    * Abstraccion de la clase de b2World de box2D
    */
    class Windmill
    {

    private:

        b2Vec2 center;

        float torqueSpeed; 

        std::vector<RotationTorque *> torques;

        Body * stick;

        bool eneabled;

        float time = 0;

        float animationTime = 6.0f;

    public:

        Windmill(b2Vec2 center, Body * Stick, std::vector<Body *> Bodies);

        void render(sf::RenderWindow& renderWindow);

        void update(float time);

        void startTorque();

        void stopTorque();

        void setTorqueSpeed(float speed);

        inline bool isEneabled() { return eneabled; };

    };


}

#endif