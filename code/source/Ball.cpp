#include "..\headers\Body.hpp"
#include "..\headers\Ground.hpp"
#include "..\headers\World.hpp"
#include "..\headers\Ball.hpp"

using namespace Box2DAnimation;

Box2DAnimation::Ball::Ball(float x, float y, float r, World& world, Body::SMLF_SHAPES_ATIBUTES attrb) :
    DynamicBody(x, y, r, r, world)
{

    radius = r;

    sf::CircleShape* circle = new sf::CircleShape(radius);
    circle->setPosition(x, y);
    circle->setOrigin(radius, radius);
    circle->setFillColor(attrb.fillColor);
    sfml_shape = std::shared_ptr<sf::Shape>(circle);

    shape.SetAsBox(
        sfml_shape->getLocalBounds().width /  2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );


    body_fixture.shape = &shape;
    body_fixture.density = 1;
    body_fixture.friction = 0.3f;
    body_fixture.restitution = 0.6f; // Make it bounce a little bit
    body->CreateFixture(&body_fixture);


}

void Box2DAnimation::Ball::render(sf::RenderWindow& renderWindow)
{
   
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::Ball::update(float time)
{

    sfml_shape->setPosition(
        body->GetPosition().x * World::getInstance()->getWorldScale(),
        body->GetPosition().y * World::getInstance()->getWorldScale()
    );

    sfml_shape->setRotation(
        body->GetAngle() * 180 / b2_pi
    );


}
