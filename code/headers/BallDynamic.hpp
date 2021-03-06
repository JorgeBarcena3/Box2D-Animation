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

#ifndef BALL_BOX2DANIMATION
#define BALL_BOX2DANIMATION

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
    * Crea una bola dinamica en el mundo de box2d
    */
    class BallDynamic : public DynamicBody
    {

    private:

        float radius; ///< Radio de la esfera


    public:

        /**
        * Crea la pelota con un radio determinado
        */
        BallDynamic(float r, Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb);


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
        void modifyFixture(b2CircleShape newShape, b2FixtureDef newFixture);

        /**
        * Actualiza la fixture
        */
        virtual void updateFixture(b2FixtureDef fixture) override;

    };


}

#endif