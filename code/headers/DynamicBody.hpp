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

    /**
    * Abstraccion de un cuerpo dinamico de box2D
    */
    class DynamicBody : public Body
    {


    public:

        /**
        * Establece el cuerpo como dinamico
        */
        DynamicBody(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world);

        /**
        * Renderiza el Body. Se debe implementar en las clases hijas
        */
        virtual void render(sf::RenderWindow& renderWindow) = 0;

        /**
        * Ciclo de update. Se debe implementar en las clases hijas
        */
        virtual void update(float time) = 0;

        /**
        * Actualiza la fixture del body. Se debe implementar en las clases hijas
        */
        virtual void updateFixture(b2FixtureDef fixture) = 0;


    };


}

#endif