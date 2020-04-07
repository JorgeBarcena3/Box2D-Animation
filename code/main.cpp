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


#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>


using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800,600), "Box2D Animation - Jorge Barcena Lumbreras");

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
			
			window.clear();

			window.display();
		}

	} while (!exit);

	return 0;
}