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

World::World(float x, float y, float _worldScale)
{

    World::instance = std::shared_ptr<World>(this);
    gravity = b2Vec2(x, y);
    worldScale = _worldScale;
    world = std::shared_ptr<b2World>(new b2World(gravity));
    world->SetContactListener(&contactHandler);


}

Box2DAnimation::World::~World()
{
    instance.reset();

    if (!world->IsLocked())
    {
        if (body_list.size() != 0)
        {
            for (size_t i = 0; i < body_list.size(); i++)
            {
                world->DestroyBody(body_list[i]->body);
                body_list.erase(body_list.begin() + i);
            }
        }
    }


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
       // body->render(renderWindow);
    }

    world->DebugDraw();

}

