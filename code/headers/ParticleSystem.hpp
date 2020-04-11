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

#ifndef PARTICLESYSTEM_BOX2DANIMATION
#define PARTICLESYSTEM_BOX2DANIMATION

#include <memory>
#include <vector>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "Particle.hpp"


namespace Box2DAnimation
{



    /*
    * Abstraccion de la clase de b2World de box2D
    */
    class ParticleSystem
    {

        friend Particle;

    public:

        /*
        * Definicion del sistema de particulas
        */
        struct ParticleSystemDef
        {
            float coneAngle = 1; ///< Cono de apertura para las particulas

            int particlesNumber = 20; ///< Cantidad de particulas

            PARTICLE_TYPE type = PARTICLE_TYPE::CIRCLE; ///< Tipo de particulas

            sf::Vector2f direction = { 0,1 }; ///< Direccion de las particuals

            sf::Color color = sf::Color::Red; ///< Color base

            bool randomColor = false; ///< Randomiza el color

            sf::Vector2f baseSize = {5,5}; ///< Tamaño de la particula

            sf::Vector2i speedRange = {1, 5}; ///< Rango de velocidad

        };

    private:

        bool eneabled; ///< Activa/Desactiva el sistema

        int particlesNumber; ///< Cantidad de particulas

        sf::Vector2f position; ///< Posicion

        ParticleSystemDef particleDefinition; ///< Definicion del sistema
         
        std::vector<Particle *> particlePool; ///< Particulas creadas

    public:

        /*
        * Crea el sistema de particulas
        */
        ParticleSystem(sf::Vector2f position, ParticleSystemDef definition, bool eneabled = false);

        /*
        * Ciclo de render
        */
        void update(float time);

        /*
        * Ciclo de update
        */
        void render(sf::RenderWindow& window);

        /*
        * Empieza a emitir particulas
        */
        void start();

        /*
        * Para el sistema de particulas
        */
        void stop();

        /*
        * Reinicia el sistema de particulas
        */
        void restart();

        /*
        * Determina la posicion del sistema de particulas
        */
        void setPosition(sf::Vector2f newPosition);

    };


}

#endif