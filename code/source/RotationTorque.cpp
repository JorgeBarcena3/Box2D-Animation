#include "..\headers\Body.hpp"
#include "..\headers\StaticBody.hpp"
#include "..\headers\RotationTorque.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::RotationTorque::RotationTorque(float r, Body::BOX2D_LOCATION_ATTRBUTES transform, World& _world, Body::SMLF_SHAPES_ATIBUTES attrb)
{

    world = &_world;
    radius = r;

    sf::CircleShape* circle = new sf::CircleShape(radius);
    circle->setPosition(transform.position.x, transform.position.y);
    circle->setOrigin(radius, radius);
    circle->setFillColor(attrb.fillColor);
    sfml_shape = circle;

    b2CircleShape new_shape;
    new_shape.m_radius = r;

}

void Box2DAnimation::RotationTorque::render(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::RotationTorque::update(float time)
{
    auto pos = torqueJoin->GetAnchorA();
    sfml_shape->setPosition(pos.x, pos.y);

}


void Box2DAnimation::RotationTorque::setJointBodies(Body& A, Body& B, b2Vec2 center)
{
    b2RevoluteJointDef torqueJoinDef;

    torqueJoinDef.bodyA = A.body;
    torqueJoinDef.bodyB = B.body;
    torqueJoinDef.collideConnected = true;

    torqueJoinDef.localAnchorA = (A.body->GetLocalPoint(center));
    torqueJoinDef.localAnchorB = (B.body->GetLocalPoint(center));

    torqueJoinDef.referenceAngle = 0;

    torqueJoinDef.enableMotor = false;
    torqueJoinDef.maxMotorTorque = powf(10,16);
    torqueJoinDef.motorSpeed = 2 * 10;

    torqueJoin = (b2RevoluteJoint*)(world->get_b2World()->CreateJoint(&torqueJoinDef));



}
