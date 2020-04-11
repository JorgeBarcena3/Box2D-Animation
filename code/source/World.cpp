#include "..\headers\World.hpp"
#include "..\headers\Body.hpp"

using namespace Box2DAnimation;
using namespace sf;

World* World::instance = nullptr;

World * World::getInstance()
{

    if (World::instance)
    {
        return instance;
    }

    instance = new World(0, -9.8f);
    return instance;
}

World::World(float x, float y, float _worldScale) : drawer(nullptr)
{

    World::instance = this;
    gravity = b2Vec2(x, y);
    worldScale = _worldScale;
    world = new b2World(gravity);
    world->SetContactListener(&contactHandler);

}

Box2DAnimation::World::~World()
{

}

b2Body* Box2DAnimation::World::createBody(Body * body)
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

  //  world->DebugDraw();

}

