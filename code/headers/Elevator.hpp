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

#ifndef ELEVATOR_BOX2DANIMATION
#define ELEVATOR_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "DynamicBody.hpp"
#include "RectangleStatic.hpp"


namespace Box2DAnimation
{ 


    class World;

    /*
    * Configura el ascensor
    */
    class Elevator : public DynamicBody
    {


    private:


        RectangleStatic * anchorRectangle; ///< Plataforma a la que se enganchará el ascensor

        b2PrismaticJoint *  elevatorJoint; ///< Joint del ascensor

        bool eneabled = false; ///< Activa o desactiva el ascensor

        float maxTimer = 0; ///< Tiempo que estará esperando la plataforma

        float currentTime = 0; ///< Tiempo que lleva actualmente la plataforma

        float yLimit = 0; ///< Limite de Y
        
    public:

        /*
        * Configura el ascensor
        */
        Elevator(Body::BOX2D_LOCATION_ATTRBUTES location, World& world, Body::SMLF_SHAPES_ATIBUTES attrb, bool isSensor = false);

        ~Elevator();

        /*
        * Renderiza el render
        */
        virtual void render(sf::RenderWindow& renderWindow) override;
        
        /*
        * Ciclo de update
        */
        void update(float time) override;

        /*
        * Modifica la fixture
        */
        void modifyFixture(b2PolygonShape newFixture);

        /*
        * Hace un update de la fixture
        */
        virtual void updateFixture(b2FixtureDef fixture) override;

        /*
        * Activa el ascensor
        */
        void up(float timeToStart = 0, float limit = 0);

        /*
        * Para el ascensor
        */
        void Stop();


    };


}

#endif