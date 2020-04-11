#include "..\headers\Body.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::Body::~Body()
{
    world->get_b2World()->DestroyBody(body);
}
