#include "..\headers\Body.hpp"
#include "..\headers\StaticBody.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::StaticBody::StaticBody(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world)
{
    body_definition.type = b2_staticBody;
    body_definition.position.Set(transform.position.x / World::getInstance()->getWorldScale(), transform.position.y / World::getInstance()->getWorldScale());
    body_definition.angle = transform.rotation * b2_pi / 180;

    body =  world.createBody(std::shared_ptr<Body>( this ));
}

