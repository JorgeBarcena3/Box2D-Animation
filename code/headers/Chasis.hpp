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
    * Abstraccion de la clase de b2World de box2D
    */
    class Chasis : public RectangleDynamic
    {

    private:

        struct CHASIS_PART_ELEMENTS
        {

            b2FixtureDef fixtureDefinition;
            b2Fixture * fixture;
            b2Vec2 positionOffset;
            b2PolygonShape b2_shape;
            std::shared_ptr<sf::Shape> sfml_shape;

            void update(b2Body * body)
            {

                sfml_shape->setPosition(
                    body->GetPosition().x * World::getInstance()->getWorldScale() + positionOffset.x,
                    body->GetPosition().y * World::getInstance()->getWorldScale() + positionOffset.y
                );

                sfml_shape->setRotation(
                    body->GetAngle() * 180 / b2_pi
                );
            }

            void draw(sf::RenderWindow& window)
            {
                window.draw(*sfml_shape);
            }
        };
      

    private:

        CHASIS_PART_ELEMENTS back_elements;

        CHASIS_PART_ELEMENTS front_elements;

    public:

        Chasis(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb);
        
        void update(float time);

        void render(sf::RenderWindow& window) override;

        void configChasis(Body::BOX2D_LOCATION_ATTRBUTES location, Body::SMLF_SHAPES_ATIBUTES attrb);


    };


}

#endif