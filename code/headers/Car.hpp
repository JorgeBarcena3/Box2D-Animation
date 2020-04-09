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

#ifndef CAR_BOX2DANIMATION
#define CAR_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "DynamicBody.hpp"
#include "Chasis.hpp"
#include "Wheel.hpp"


namespace Box2DAnimation
{
   
    class World;

    /*
    * Abstraccion de la clase de b2World de box2D
    */
    class Car
    {

    public:

        struct CAR_ATTRBUTES
        {
            b2Vec2 position;
            float rotation;
            b2Vec2 size;

        };

    private:

        std::shared_ptr<Chasis> chasis;

        std::shared_ptr<Wheel> front_wheel;

        std::shared_ptr<Wheel> back_wheel;
        
    public:

        Car(CAR_ATTRBUTES location,  Body::SMLF_SHAPES_ATIBUTES attrb, std::string tag = "");
        
        void update(float time);

        void render(sf::RenderWindow& window);


    };


}

#endif