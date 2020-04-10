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
    * Abstraccion de la clase de b2World de box2D
    */
    class Wheel : public BallDynamic
    {

    private:

        struct WHEEL_PARTS_ELEMENTS
        {

            std::shared_ptr<RectangleDynamic> body;
            b2Vec2 positionOffset;
            std::shared_ptr<sf::Shape> sfml_shape;

            void update(float time)
            {
                body->update(time);

                sfml_shape->setPosition(
                    body->body->GetPosition().x * World::getInstance()->getWorldScale() + positionOffset.x,
                    body->body->GetPosition().y * World::getInstance()->getWorldScale() + positionOffset.y
                );

                sfml_shape->setRotation(
                    body->body->GetAngle() * 180 / b2_pi
                );
            }

            void draw(sf::RenderWindow& window)
            {
                body->render(window);

                window.draw(*sfml_shape);
            }

            b2Body * getb2Body()
            {
                return body->body;
            }
        };


    private:

        WHEEL_PARTS_ELEMENTS axe;

        b2RevoluteJoint* join;
        
    public:

        Wheel(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb);
        
        void update(float time) override;

        void render(sf::RenderWindow& window) override;

        inline WHEEL_PARTS_ELEMENTS* getAxe()
        {
            return &axe;
        }

        void acelerate(float speed);

        void decelerate();

    private:

        void configAxe(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb);

        void configJoins();

    };


}

#endif