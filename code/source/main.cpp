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


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../headers/World.hpp"
#include "../headers/Ground.hpp"
#include "../headers/Ball.hpp"

using namespace sf;
using namespace Box2DAnimation;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Box2D Animation - Jorge Barcena Lumbreras");
    World world(0, 10.0f, 1);

    Ground suelo(400, 575, 800, 50, world, Body::SMLF_SHAPES_ATIBUTES({Color::Green}));
    Ball   ball(400, 300, 50, world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red }));

    window.setVerticalSyncEnabled(true);

    bool exit = false;

    do
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
            {
                exit = true;
                break;
            }
            }

            
        }

        world.Update(0);

        window.clear(sf::Color(180, 200, 255));

        world.render(window);

        window.display();

    } while (!exit);

    return 0;
}