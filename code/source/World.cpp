#include "..\headers\World.hpp"
#include "..\headers\Body.hpp"

using namespace Box2DAnimation;
using namespace sf;

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
    world = std::shared_ptr<b2World>(new b2World(gravity));


}

b2Body* Box2DAnimation::World::createBody(std::shared_ptr<Body> body)
{

    body_list.push_back(body);

    return world->CreateBody(&(body->body_definition));
}

void Box2DAnimation::World::Update(float t)
{
    for (auto body : body_list)
    {
        body->update(t);
    }

    world->Step(1 / 60.f, 8, 3);

}

void Box2DAnimation::World::render(sf::RenderWindow& renderWindow)
{
    for (auto body : body_list)
    {
        body->render(renderWindow);
    }

}

