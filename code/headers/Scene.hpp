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
#include "Car.hpp"
#include "SFMLDebugDraw.h"
#include "Elevator.hpp"
#include "ParticleSystem.hpp"

namespace Box2DAnimation
{
    class Body;

    /*
    * Clase que crea la escena de la demo. Es un singleton
    */
    class Scene
    {
    private:

        static Scene * instance; ///< Instancia de la escena

    public:

        static Scene * getInstance(); ///< Devuelve la escena activa

        static void addActionToPool(std::string action); ///< Añade una accion a la pool de acciones a realizar en el ciclo de update

    private:

        std::vector<std::string> actionsToDo; ///< Acciones que hay que hacer

        World world; ///< Mundo que tiene

        std::vector<Body *> body_list; ///< Lista de cuerpos instanciados

        Windmill * windmill; ///< Molino

        Car * car; ///< Coche

        Elevator * elevator; ///< Ascensor

    public:

        bool debugMode = false; ///< Modo debug activado

    public:

        /*
        * Crea la escena
        */
        Scene();

        ~Scene();

        /*
        * Ciclo de update
        */
        void update(float t);

        /*
        * Ciclo de render
        */
        void render(sf::RenderWindow& renderWindow);

        /*
        * Maneja el input
        */
        bool manageInput(sf::RenderWindow& window);

        /*
        * Determina una herramienta de debug
        */
        void setDrawTool(SFMLDebugDraw& draw);

    private:

        /*
        * Configura la escena
        */
        void configScene();

        /*
        * Realiza las acciones que hay en el pool
        */
        void poolActionsToDo();

    };


}

#endif