#include "..\headers\Body.hpp"
#include "..\headers\Rectangle.hpp"
#include "..\headers\World.hpp"
#include "..\headers\Ball.hpp"

using namespace Box2DAnimation;

Box2DAnimation::Ball::Ball(float r, Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb) :
    DynamicBody(transform, world)
{

    radius = r;

    sf::CircleShape* circle = new sf::CircleShape(radius);
    circle->setPosition(transform.position.x, transform.position.y);
    circle->setOrigin(radius, radius);
    circle->setFillColor(attrb.fillColor);
    sfml_shape = std::shared_ptr<sf::Shape>(circle);

    b2CircleShape new_shape;
    new_shape.m_radius = r;


    shape = std::shared_ptr<b2Shape>(new b2CircleShape(new_shape));

    body_fixture.shape = shape.get();
    body_fixture.density = 1;
    body_fixture.friction = 0;
    body_fixture.restitution = 0.6f; // Make it bounce a little bit
    body->CreateFixture(&body_fixture);


}

void Box2DAnimation::Ball::render(sf::RenderWindow& renderWindow)
{
   
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::Ball::update(float time)
{

    sfml_shape->setRotation(
        body->GetAngle() * 180 / b2_pi
    );

    sfml_shape->setPosition(
        body->GetPosition().x * World::getInstance()->getWorldScale(),
        body->GetPosition().y * World::getInstance()->getWorldScale()
    );

   


}
