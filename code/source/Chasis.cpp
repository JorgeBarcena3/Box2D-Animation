#include "..\headers\Chasis.hpp"
#include "..\headers\World.hpp"

Box2DAnimation::Chasis::Chasis(Body::BOX2D_LOCATION_ATTRBUTES transform, World& world, Body::SMLF_SHAPES_ATIBUTES attrb)
    : RectangleDynamic(transform, world, attrb)
{
    configChasis(transform, attrb);
}

void Box2DAnimation::Chasis::update(float time)
{
    RectangleDynamic::update(time);

    back_elements.update(body);
    front_elements.update(body);

}

void Box2DAnimation::Chasis::render(sf::RenderWindow& window)
{

    RectangleDynamic::render(window);

    back_elements.draw(window);
    front_elements.draw(window);

}

void Box2DAnimation::Chasis::configChasis(Body::BOX2D_LOCATION_ATTRBUTES transform, Body::SMLF_SHAPES_ATIBUTES attrb)
{

    /* Caja principal */
    body_fixture.shape = shape.get();

    body_fixture.density = 5;
    body_fixture.friction = 3;
    body_fixture.restitution = 0.3;
    body_fixture.filter.groupIndex = -1;

    body->CreateFixture(&body_fixture);
    body->SetUserData(this);

    /* CAJA DE ATRAS */

    float new_size = transform.size.x / 2;

    back_elements.positionOffset.Set(-new_size / 2, -new_size / 2);

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(new_size, new_size));
    rectangle->setPosition(transform.position.x + back_elements.positionOffset.x, transform.position.y + back_elements.positionOffset.y);
    rectangle->setOrigin(new_size / 2, new_size / 2);
    rectangle->setFillColor(attrb.fillColor);

    back_elements.sfml_shape = std::shared_ptr<sf::Shape>(rectangle);

    back_elements.b2_shape.SetAsBox(new_size / 2, new_size / 2, b2Vec2(transform.position.x - back_elements.positionOffset.x, transform.position.y + back_elements.positionOffset.y), 0);

    back_elements.fixtureDefinition.shape = &back_elements.b2_shape;
    back_elements.fixtureDefinition.density = 1;
    back_elements.fixtureDefinition.friction = 30;
    back_elements.fixtureDefinition.restitution = 0.3f;
    back_elements.fixtureDefinition.filter.groupIndex = -1;

    back_elements.fixture = body->CreateFixture(&back_elements.fixtureDefinition);

    /* CAJA DE ALANTE */
    b2Vec2 new_size_ = b2Vec2(transform.size.x / 2, transform.size.x / 3);

    front_elements.positionOffset.Set(new_size_.x / 2, -new_size_.y / 2);

    rectangle = new sf::RectangleShape(sf::Vector2f(new_size_.x, new_size_.y));
    rectangle->setPosition(transform.position.x + front_elements.positionOffset.x, transform.position.y + front_elements.positionOffset.y);
    rectangle->setOrigin(new_size_.x / 2, new_size_.y / 2);
    rectangle->setFillColor(sf::Color::Red);

    front_elements.sfml_shape = std::shared_ptr<sf::Shape>(rectangle);

    front_elements.b2_shape.SetAsBox(new_size_.x / 2, new_size_.y / 2, b2Vec2(transform.position.x - front_elements.positionOffset.x, transform.position.y + front_elements.positionOffset.y), 0);

    front_elements.fixtureDefinition.shape = &front_elements.b2_shape;
    front_elements.fixtureDefinition.density = 1;
    front_elements.fixtureDefinition.friction = 30;
    front_elements.fixtureDefinition.restitution = 0.3f;
    front_elements.fixtureDefinition.filter.groupIndex = -1;

    front_elements.fixture = body->CreateFixture(&front_elements.fixtureDefinition);

}
