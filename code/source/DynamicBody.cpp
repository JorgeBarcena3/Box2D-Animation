#include "..\headers\Body.hpp"
#include "..\headers\DynamicBody.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::DynamicBody::DynamicBody(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world)
{
    body_definition.type = b2_dynamicBody;
    body_definition.position.Set(transform.position.x / World::getInstance()->getWorldScale(), transform.position.y / World::getInstance()->getWorldScale());
    body_definition.angle = transform.rotation * 3.1415 / 180;

    body = world.createBody(std::shared_ptr<Body>(this));

    shape.SetAsBox(transform.size.x * 0.5f, transform.size.y * 0.5f);

    body_fixture.shape = &shape;

    body->CreateFixture(&body_fixture);

}

void Box2DAnimation::DynamicBody::render(sf::RenderWindow& renderWindow)
{
}

void Box2DAnimation::DynamicBody::update(float time)
{
}
