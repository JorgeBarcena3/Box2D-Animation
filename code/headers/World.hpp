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

    /**
    * Abstraccion de la clase de b2World de box2D. Es un singleton
    */
    class World
    {
    private:

        static World * instance; ///< Instancia del mundo

    public:

        static World * getInstance(); ///< Devuelve la instancia

    public:

        SFMLDebugDraw* drawer; ///< Herramienta de debug

    private:

        float worldScale; ///< Escala del mundo (ARREGLAR)

        b2Vec2 gravity; ///< Gravedad del mundo

        b2World* world; ///< Mundo de box2D

        std::vector<Body*> body_list; ///< Lista de cuerpos instanciados

        ContactHandler contactHandler; ///< Lista de contactor

    public:

        /**
        * Constructor del mundo
        */
        World(float x, float y, float worldScale = 1);

        ~World();

        /**
        * Crea un cuerpo en el mundo
        */
        b2Body* createBody(Body * body);

        /**
        * Ciclo de update
        */
        void Update(float t);

        /**
        * Ciclo de render
        */
        void render(sf::RenderWindow& renderWindow);

        /**
        * Determian la gravedad del mundo
        */
        inline void setGravity(float x, float y)
        {
            gravity = b2Vec2(x, y);
            world->SetGravity(gravity);
        }

        /**
        * Devuelve el mundo de box2D
        */
        inline b2World * get_b2World()
        {
            return world;
        }

        /**
        * Devuelve la escala del mundo
        */
        inline float getWorldScale() { return worldScale; }

    };


}

#endif