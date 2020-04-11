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

#ifndef CHASIS_BOX2DANIMATION
#define CHASIS_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "RectangleDynamic.hpp"
#include "World.hpp"


namespace Box2DAnimation
{

    /*
    * Chasis del coche
    */
    class Chasis : public RectangleDynamic
    {

    private:

        /*
        * Define las partes del coche
        */
        struct CHASIS_PART_ELEMENTS
        {

            b2FixtureDef fixtureDefinition; ///< Definicion de la fixture
            b2Fixture * fixture; ///< Fixture
            b2Vec2 positionOffset; ///< Offser respecto al centro
            b2PolygonShape b2_shape; ///< Shape box2D

        };
      

    public:

        /*
        * Elemento trasero
        */
        CHASIS_PART_ELEMENTS back_elements;

        /*
        * Elemento delantero
        */
        CHASIS_PART_ELEMENTS front_elements;

    public:

        /*
        * Crea el chasis del coche
        */
        Chasis(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb);
        
        /*
        * Ciclo de update del chasis
        */
        void update(float time);

        /*
        * Renderiza todas las fixtures del chasis (Que son varias)
        */
        void render(sf::RenderWindow& window) override;

        /*
        * Configura el chasis del coche
        */
        void configChasis(Body::BOX2D_LOCATION_ATTRBUTES location, Body::SMLF_SHAPES_ATIBUTES attrb);


    };


}

#endif