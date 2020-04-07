#include "..\headers\Body.hpp"
#include "..\headers\DynamicBody.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::DynamicBody::DynamicBody(float x, float y, float size_x, float size_y, World& world)
{
    body_definition.type = b2_dynamicBody;
    body_definition.position.Set(x, y);

    body = world.createBody(std::shared_ptr<Body>(this));

    shape.SetAsBox(size_x * 0.5f, size_y * 0.5f);

    body_fixture.shape = &shape;
;
    body->CreateFixture(&body_fixture);

}

void Box2DAnimation::DynamicBody::render(sf::RenderWindow& renderWindow)
{
}

void Box2DAnimation::DynamicBody::update(float time)
{
}
