#include "..\headers\Body.hpp"
#include "..\headers\Ground.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::Ground::Ground(float x, float y, float size_x, float size_y, World& world, Body::SMLF_SHAPES_ATIBUTES attrb) : StaticBody(x, y, size_x, size_y, world)
{

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(size_x, size_y));
    rectangle->setPosition(x,y);
    rectangle->setOrigin(size_x / 2, size_y / 2);
    rectangle->setFillColor(attrb.fillColor);

    sfml_shape = std::shared_ptr<sf::Shape>(rectangle);

    shape.SetAsBox(
        sfml_shape->getLocalBounds().width / 2.0f / World::getInstance()->getWorldScale(),
        sfml_shape->getLocalBounds().height / 2.0f / World::getInstance()->getWorldScale()
    );

    body->CreateFixture(&shape, 0);


}

void Box2DAnimation::Ground::render(sf::RenderWindow& renderWindow)
{
   
    renderWindow.draw(*sfml_shape);
}

void Box2DAnimation::Ground::update(float time)
{
    sfml_shape->setPosition(
        body->GetPosition().x * World::getInstance()->getWorldScale(),
        body->GetPosition().y * World::getInstance()->getWorldScale()
    );

    sfml_shape->setRotation(
        body->GetAngle() * 180 / b2_pi
    );

}
