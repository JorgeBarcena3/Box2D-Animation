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

#ifndef CAR_BOX2DANIMATION
#define CAR_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "DynamicBody.hpp"
#include "Chasis.hpp"
#include "Wheel.hpp"
#include "ParticleSystem.hpp"


namespace Box2DAnimation
{
   
    class World;

    /**
    * Crea un coche compuesto por un chasis y unas ruedas
    */
    class Car
    {

    public:

        /**
        * Atributos del coche
        */
        struct CAR_ATTRBUTES
        {
            b2Vec2 position;
            b2Vec2 size;

        };

    private:

        Chasis * chasis; ///< Chasis del coche

        Wheel * front_wheel; ///< Rueda delantera

        Wheel * back_wheel; ///< Rueda trasera

        b2RevoluteJoint * front_joint; ///< Motor delantero

        b2RevoluteJoint * back_joint; ///< Rueda trasero

        int status; ///< Estado del motor del coche

        std::vector< ParticleSystem * > particleSystem; ///< Sistema de particulas del coche

        bool rotating; ///< Si el coche se esta rotando

    public:

        /**
        * Crea un coche
        */
        Car(CAR_ATTRBUTES location,  Body::SMLF_SHAPES_ATIBUTES attrb, std::string tag = "");

        ~Car();
        
        /**
        * Ciclo de update
        */
        void update(float time);

        /**
        * Ciclo de render
        */
        void render(sf::RenderWindow& window);

        /**
        * Acelera el coche
        */
        void acelerate(int state);

        /**
        * Frena el coche
        */
        void decelerate();

        /**
        * Activa las particulas del coche
        */
        void startParticles();

        /**
        * Desactiva las particulas del coche
        */
        void stopParticles();

        /**
        * Rota el coche aplicando una fuerza
        */
        void rotateCar();


    private:

        /**
        * Configura los Joints
        */
        void configJoints();

        /**
        * Respawnea el coche
        */
        void respawnCar();

        /**
        * Determina la velocidad
        */
        void SetCarSpeed();


    };


}

#endif