#include "..\headers\ContactHandler.hpp"
#include "..\headers\Body.hpp"
#include "..\headers\Scene.hpp"

using namespace Box2DAnimation;

void Box2DAnimation::ContactHandler::BeginContact(b2Contact* contact)
{
    // Get Fixtures
    b2Fixture* f1 = contact->GetFixtureA();
    b2Fixture* f2 = contact->GetFixtureB();

    // Get both bodies
    b2Body* b1 = f1->GetBody();
    b2Body* b2 = f2->GetBody();

    // Get our objects that reference these bodies
    Body* o1 = (Body*)b1->GetUserData();
    Body* o2 = (Body*)b2->GetUserData();

    if (o1->tag == "Activacion" && o2->tag == "Coche")
    {
        Scene::addActionToPool("Start Windmill");
        Scene::addActionToPool("AppearElevator");
    }
    else if (o1->tag == "Elevator" && o2->tag == "Coche")
    {
        Scene::addActionToPool("ElevatorStart");
    }
    else if (o1->tag == "Plataforma final" && o2->tag == "Coche")
    {
        Scene::addActionToPool("StartParticles");
    }


}

void Box2DAnimation::ContactHandler::EndContact(b2Contact* contact)
{
}
