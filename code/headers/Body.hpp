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

    /**
    * Abstraccion de la clase de b2Body de box2D
    */
    class Body
    {

        friend class World; ///< La clase world puede acceder a todos los miembros de Body


    public:

        /**
        * Atributos de la shape que representa el Body
        */
        struct SMLF_SHAPES_ATIBUTES
        {
            sf::Color fillColor;
            sf::Color outLineColor;
        };

        /**
        * Atributos de posicion iniciales del body
        */
        struct BOX2D_LOCATION_ATTRBUTES
        {
            b2Vec2 position;
            float rotation;
            b2Vec2 size;

        };

    public:


        b2BodyDef body_definition; ///< Definicion del cuerpo

        b2FixtureDef body_fixture_def; ///< Definicion de la fixture

        sf::Shape* sfml_shape; ///< Shape que dibuja el body

        b2Fixture* body_fixture; ///< Fixture del body

        b2Shape* shape; ///< Shape del body

        b2Body* body; ///< Body

        World* world; ///< Mundo al que referenciamos

        std::string tag; ///< Tag del body

    public:

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

        /**
        * Despierta el Body para que pueda interactuar con box2D
        */
        inline void setBodyAwake(bool awake)
        {
            body->SetAwake(awake);
        };

        /**
        * Determina colo le afecta la gravedad a nuestros Body
        */
        inline void setGravity(float grav)
        {
            body->SetGravityScale(grav);
        };

        ~Body();

    };


}

#endif