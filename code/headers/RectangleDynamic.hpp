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

#ifndef RECTANGLEDYNAMIC_BOX2DANIMATION
#define RECTANGLEDYNAMIC_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "DynamicBody.hpp"


namespace Box2DAnimation
{
   


    class World;

    /**
    * Crea un Rectangulo dinamica en el mundo de box2d
    */
    class RectangleDynamic : public DynamicBody
    {
        
    public:

        /**
        * Crea un rectangulo dinamica en el mundo de box2d
        */
        RectangleDynamic(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb, bool isSensor = false);

        /**
        * Renderiza la bola en especifico
        */
        virtual void render(sf::RenderWindow& renderWindow) override;

        /**
        * Ciclo de update
        */
        virtual void update(float time) override;

        /**
        * Modifica la fixture del body
        */
        void modifyFixture(b2PolygonShape newFixture);

        /**
        * Actualiza la fixture
        */
        virtual void updateFixture(b2FixtureDef fixture) override;



    };


}

#endif