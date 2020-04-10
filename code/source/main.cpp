// File: main.cpp
// Description : Proyecto base con la libreria de SFML
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

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
//


#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <box2d/b2_world.h>
#include "../headers/Scene.hpp"
#include "../headers/SFMLDebugDraw.h"

using namespace sf;
using namespace Box2DAnimation;

int main()
{
    RenderWindow window(VideoMode(1500, 800), "Box2D Animation - Jorge Barcena Lumbreras");

    /* Initialize SFML Debug Draw */
    SFMLDebugDraw debugDraw(window);

    Scene myScene;  
    myScene.setDrawTool(debugDraw);

    window.setVerticalSyncEnabled(true);

    bool exit = false;

    sf::Clock clock;

    do
    {
        /* MANEJAMOS LOS INPUT */
        exit = myScene.manageInput(window);

        /* CICLO DE UPDATE */
        sf::Time elapsed = clock.restart();        
        myScene.update(elapsed.asSeconds());

        /* CICLO DE RENDER */
        window.clear(sf::Color(240,240,240));
        myScene.render(window);
        window.display();

    } while (!exit);

    return 0;
}