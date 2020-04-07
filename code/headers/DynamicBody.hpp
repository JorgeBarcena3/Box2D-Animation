// � Copyright (C) 2020  Jorge B�rcena Lumbreras

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

#ifndef DYNAMICBODY_BOX2DANIMATION
#define DYNAMICBODY_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "Body.hpp"


namespace Box2DAnimation
{


    class World;

    /*
    * Abstraccion de la clase de b2World de box2D
    */
    class DynamicBody : public Body
    {


    public:

        DynamicBody(float x, float y, float size_x, float size_y, World& world);

        virtual void render(sf::RenderWindow& renderWindow) override;

        virtual void update(float time) override;

    };


}

#endif