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

#ifndef SCENE_BOX2DANIMATION
#define SCENE_BOX2DANIMATION

#include <memory>
#include <vector>
#include <box2d/box2d.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "Windmill.hpp"

namespace Box2DAnimation
{
    class Body;

    /*
    * Abstraccion de la clase de b2World de box2D
    */
    class Scene
    {
    private:

        static std::shared_ptr< Scene > instance;

    public:

        static std::shared_ptr<Scene> getInstance();

        static void addActionToPool(std::string action);

    private:

        std::vector<std::string> actionsToDo;

        World world;

        std::vector<std::shared_ptr<Body>> body_list;

        std::shared_ptr<Box2DAnimation::Windmill> windmill;

        std::shared_ptr<Body> player;

    public:

        Scene();

        ~Scene();

        void update(float t);

        void render(sf::RenderWindow& renderWindow);

        bool manageInput(sf::RenderWindow& window);

    private:

        void configScene();

        void poolActionsToDo();

    };


}

#endif