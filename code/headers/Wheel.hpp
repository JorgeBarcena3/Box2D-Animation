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

#ifndef WHEEL_BOX2DANIMATION
#define WHEEL_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "BallDynamic.hpp"
#include "World.hpp"
#include "RectangleDynamic.hpp"


namespace Box2DAnimation
{
   
    class World;

    /*
    * Crea una rueda
    */
    class Wheel : public BallDynamic
    {

        
    public:

        /*
        * Configura la rueda
        */
        Wheel(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb);
        
        /*
        * Ciclo de update
        */
        void update(float time) override;

        /*
        * Ciclo de render
        */
        void render(sf::RenderWindow& window) override;


    };


}

#endif