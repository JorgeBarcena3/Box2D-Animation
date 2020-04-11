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

#ifndef PARTICLE_BOX2DANIMATION
#define PARTICLE_BOX2DANIMATION

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>


namespace Box2DAnimation
{

	class ParticleSystem;

	enum PARTICLE_TYPE
	{
		CIRCLE = 0,
		RECTANGLE = 1,
		POLYGON = 2

	};

    /*
    * Abstraccion de la clase de b2World de box2D
    */
    class Particle
    {

	public:

		

		struct ParticleDefinition
		{

			sf::Shape * shape;

			sf::Color color;

			sf::Vector2f size;

			Box2DAnimation::PARTICLE_TYPE type;

		};

		

	private:

		bool active; 

		sf::Vector2f position;
				
		sf::Vector2f direction;
				
		float alpha;

		float speed;
	   
		ParticleSystem * particleSystem;

		ParticleDefinition particleDefinition;

	public:

		Particle(ParticleSystem* system, bool active = false);

		void Update(float time);

		void render(sf::RenderWindow& window);

		void eneable();

		void disable();

		void reset();

	private:

		void initialiceParticlesValues();


    };


}

#endif