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

#ifndef BODY_BOX2DANIMATION
#define BODY_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>


namespace Box2DAnimation
{

    class World;

    /*
    * Abstraccion de la clase de b2World de box2D
    */
    class Body
    {

        friend class World;

    private:

        static std::vector<std::shared_ptr<Body>> instances;

    public:

        static void Update()
        {
            for (auto instance : instances)
            {
                instance->update(0);
            }
        }

        static void Render(sf::RenderWindow& renderWindow)
        {
            for (auto instance : instances)
            {
                instance->render(renderWindow);
            }

        }

    protected:

        b2BodyDef body_definition;

        b2FixtureDef body_fixture;

        b2PolygonShape shape;

        b2Body * body;

        std::shared_ptr< World > world;
        
    public:

        virtual void render(sf::RenderWindow& renderWindow) = 0;

        virtual void update(float time) = 0;

    };


}

#endif