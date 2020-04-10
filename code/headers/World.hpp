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

#ifndef WORLD_BOX2DANIMATION
#define WORLD_BOX2DANIMATION

#include <memory>
#include <vector>
#include <box2d/b2_world.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ContactHandler.hpp"
#include "SFMLDebugDraw.h"

namespace Box2DAnimation
{
    class Body;
    
    /*
    * Abstraccion de la clase de b2World de box2D 
    */
    class World
    {
    private:

        static std::shared_ptr< World > instance;

    public:

        static std::shared_ptr<World> getInstance();

    public:

        SFMLDebugDraw * drawer;

    private:

        float worldScale;

        b2Vec2 gravity;

        std::shared_ptr< b2World > world;

        std::vector<std::shared_ptr<Body>> body_list;

        ContactHandler contactHandler;

    public:

        World(float x, float y, float worldScale = 1);

        ~World();

        b2Body* createBody(std::shared_ptr<Body> body);

        void Update(float t);

        void render(sf::RenderWindow& renderWindow);

        inline void setGravity(float x, float y)
        {
            gravity = b2Vec2(x, y);
            world->SetGravity(gravity);
        }

        inline std::shared_ptr<b2World> get_b2World()
        {
            return world;
        }

        inline float getWorldScale() { return worldScale; }

    };


}

#endif