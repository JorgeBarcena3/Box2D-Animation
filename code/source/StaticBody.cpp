#include "..\headers\Body.hpp"
#include "..\headers\StaticBody.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::StaticBody::StaticBody(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world)
{
    body_definition.position.Set(transform.position.x / World::getInstance()->getWorldScale(), transform.position.y / World::getInstance()->getWorldScale());
    body_definition.angle = transform.rotation * b2_pi / 180;

    body =  world.createBody(std::shared_ptr<Body>( this ));

    shape.SetAsBox(transform.size.x * 0.5f, transform.size.y * 0.5f);
    body->CreateFixture(&shape, 0);
}

void Box2DAnimation::StaticBody::render(sf::RenderWindow& renderWindow)
{
}

void Box2DAnimation::StaticBody::update(float time)
{
}
