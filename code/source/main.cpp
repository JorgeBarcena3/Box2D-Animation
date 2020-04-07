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

void configScene(std::vector<Body*>& body_list, World& world)
{
    //Suelo izquierda
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 96, 697 }, 0, {192,206} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 1149, 773 }, -9, {620,225} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 1490, 722 }, -9, {121,232} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Green })));


    //Contenedor de bolas
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 511 }, 0, {38,387} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 1150, 286 }, -64, {38,200} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 1331, 286 }, 64, {38,200} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));


    //Caja de destino para meter las bolas
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 548, 254}, 0, {192,34} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 429, 283}, 51, {34,98} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 370, 283}, -51, {34,98} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));

    //Rampa aproximada con cubos
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 193, 670}, -310, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 234, 704}, -317, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 273, 738}, -324, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 325, 763}, -333, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 378, 777}, -346, { 93, 96} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 456, 785}, -356, { 80, 84} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 538, 786},   -8, { 87, 90} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 625, 765},  -20, {113,106} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));

    //Fondo Rampa
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 437, 800},    0, {491,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
    body_list.push_back(new Ground(Body::BOX2D_LOCATION_ATTRBUTES({ { 201, 751},    0, {065,125} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Blue })));
          

    //Pelotas a spawnear
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 272}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1220, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1260, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1200, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1220, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1260, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));
    body_list.push_back(new Ball(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1280, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));



}


int main()
{
    RenderWindow window(VideoMode(1500, 800), "Box2D Animation - Jorge Barcena Lumbreras");

    std::vector<Body*> body_list;

    World world(0, 100.0f, 1);

    configScene(body_list, world);


    //Ball   ball(400, 300, 50, world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red }));

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