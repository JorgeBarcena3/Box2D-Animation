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

#ifndef CONTACTHANDLER_BOX2DANIMATION
#define CONTACTHANDLER_BOX2DANIMATION

#include <memory>
#include <vector>
#include <box2d/box2d.h>

namespace Box2DAnimation
{    
    /*
    * Abstraccion de la clase de b2World de box2D 
    */
    class ContactHandler : public b2ContactListener
    {

        /// Called when two fixtures begin to touch.
        virtual void BeginContact(b2Contact* contact) override;

        /// Called when two fixtures cease to touch.
        virtual void EndContact(b2Contact* contact) override;

    };


}

#endif