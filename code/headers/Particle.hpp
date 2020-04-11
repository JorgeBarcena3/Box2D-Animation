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

	/*
	* Tipo de particula
	*/
	enum PARTICLE_TYPE
	{
		CIRCLE = 0,
		RECTANGLE = 1,
		POLYGON = 2

	};

	/*
	* Particula
	*/
    class Particle
    {

	public:

		
		/*
		* Definicion de la particula
		*/
		struct ParticleDefinition
		{

			sf::Shape * shape; ///< Shape de SFMLs

			sf::Color color; ///< Color

			sf::Vector2f size; ///< Tamaño

			Box2DAnimation::PARTICLE_TYPE type; ///< Tamaño del tipo

		};

		

	private:

		bool active; ///< Determina si esta activada o no la particula

		sf::Vector2f position; ///< Posicion de la particula
				
		sf::Vector2f direction; ///< Direccion de la particula
				
		float alpha; ///< Alpha actual

		float speed; ///< Velocidad de la partida
	   
		ParticleSystem * particleSystem; ///< Sistema de particulas

		ParticleDefinition particleDefinition; ///< Definicion de la particula

	public:

		/*
		* Crea una particula
		*/
		Particle(ParticleSystem* system, bool active = false);

		/*
		* Ciclo de update
		*/
		void Update(float time);

		/*
		* Ciclo de render
		*/
		void render(sf::RenderWindow& window);

		/*
		* Activa la particula
		*/
		void eneable();

		/*
		* Desactiva la particula
		*/
		void disable();

		/*
		* Resetea la particula
		*/
		void reset();

	private:

		/*
		* Inicializa la particula
		*/
		void initialiceParticlesValues();


    };


}

#endif