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


        struct ParticleSystemDef
        {
            float coneAngle = 1;
            int particlesNumber = 20;
            PARTICLE_TYPE type = PARTICLE_TYPE::CIRCLE;
            sf::Vector2f direction = { 0,1 };
            sf::Color color = sf::Color::Red;
            bool randomColor = false;
            sf::Vector2f baseSize = {5,5};
            sf::Vector2i speedRange = {1, 5};

        };

    private:

        bool eneabled;

        int particlesNumber;

        sf::Vector2f position;

        ParticleSystemDef particleDefinition;

        std::vector<Particle *> particlePool;

    public:

        ParticleSystem(sf::Vector2f position, ParticleSystemDef definition, bool eneabled = false);

        void update(float time);

        void render(sf::RenderWindow& window);

        void start();

        void stop();

        void restart();

        void setPosition(sf::Vector2f newPosition);

    };


}

#endif