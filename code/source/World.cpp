#include "..\headers\World.hpp"


using namespace Box2DAnimation;

std::shared_ptr< World > World::instance = std::shared_ptr<World>(nullptr);

std::shared_ptr<World> World::getInstance()
{

    if (World::instance)
    {
        return instance;
    }

    instance = std::shared_ptr<World>(new World(0, -9.8f));
    return instance;
}

World::World(float x, float y)
{

    World::instance = std::shared_ptr<World>(this);
    gravity = b2Vec2(x, y);
    world = std::shared_ptr<b2World>( new b2World(gravity));


}
