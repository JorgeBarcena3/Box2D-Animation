#include "..\headers\Body.hpp"
#include "..\headers\StaticBody.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::StaticBody::StaticBody(float x, float y, float size_x, float size_y, World& world)
{
    body_definition.position.Set(x, y);

    body =  world.createBody(std::shared_ptr<Body>( this ));

    shape.SetAsBox(size_x * 0.5f, size_y * 0.5f);
    body->CreateFixture(&shape, 0);
}

void Box2DAnimation::StaticBody::render(sf::RenderWindow& renderWindow)
{
}

void Box2DAnimation::StaticBody::update(float time)
{
}
