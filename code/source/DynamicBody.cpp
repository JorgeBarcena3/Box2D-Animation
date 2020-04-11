#include "..\headers\Body.hpp"
#include "..\headers\DynamicBody.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::DynamicBody::DynamicBody(Body::BOX2D_LOCATION_ATTRBUTES transform, World& _world)
{
    body_definition.type = b2_dynamicBody;
    body_definition.position.Set(transform.position.x / World::getInstance()->getWorldScale(), transform.position.y / World::getInstance()->getWorldScale());
    body_definition.angle = transform.rotation * b2_pi / 180.f;

    world = &_world;
    body = _world.createBody(this);
    

}

