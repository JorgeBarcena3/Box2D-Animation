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

}

void Box2DAnimation::Chasis::render(sf::RenderWindow& window)
{



    for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext())
    {
        b2PolygonShape* shape = (b2PolygonShape*)f->GetShape();



        sf::ConvexShape polygon(shape->m_count);
        for (int i = 0; i < shape->m_count; i++)
        {
            sf::Vector2f transformedVec = SFMLDebugDraw::B2VecToSFVec(b2Mul(body->GetTransform(), shape->m_vertices[i]));
            polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(transformedVec.y))); 
        }						

        polygon.setFillColor(sf::Color::Red);

        window.draw(polygon);


    }


}

void Box2DAnimation::Chasis::configChasis(Body::BOX2D_LOCATION_ATTRBUTES transform, Body::SMLF_SHAPES_ATIBUTES attrb)
{

    /* Caja principal */
    b2FixtureDef body_fixture_def;
    body_fixture_def.shape = shape;

    body_fixture_def.density = 500 / 10;
    body_fixture_def.friction = 3;
    body_fixture_def.restitution = 0;
    body_fixture_def.filter.groupIndex = -1;

    body->DestroyFixture(body_fixture);
    body_fixture = body->CreateFixture(&body_fixture_def);
    body->SetUserData(this);

    /* CAJA DE ATRAS */

    float new_size = transform.size.x / 4;

    back_elements.positionOffset.Set(-new_size / 2, (-new_size / 2));

    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(new_size, new_size));
    rectangle->setPosition(transform.position.x + back_elements.positionOffset.x, transform.position.y + back_elements.positionOffset.y);
    rectangle->setOrigin(new_size / 2, new_size / 2);
    rectangle->setFillColor(sf::Color::Blue);


    back_elements.b2_shape.SetAsBox(new_size / 3, new_size , body->GetLocalPoint({transform.position.x - (new_size * 2.3f),  transform.position.y - (new_size )}) , 0);

    back_elements.fixtureDefinition.shape = &back_elements.b2_shape;
    back_elements.fixtureDefinition.density = 100 / 5;
    back_elements.fixtureDefinition.friction = 3;
    back_elements.fixtureDefinition.restitution = 0;
    back_elements.fixtureDefinition.filter.groupIndex = -1;

    back_elements.fixture = body->CreateFixture(&back_elements.fixtureDefinition);

    /* CAJA DE ALANTE */

    front_elements.positionOffset.Set(-new_size / 2, (-new_size / 2));

    rectangle = new sf::RectangleShape(sf::Vector2f(new_size, new_size));
    rectangle->setPosition(transform.position.x + front_elements.positionOffset.x, transform.position.y + front_elements.positionOffset.y);
    rectangle->setOrigin(new_size / 2, new_size / 2);
    rectangle->setFillColor(sf::Color::Red);


    front_elements.b2_shape.SetAsBox(new_size / 3, new_size, body->GetLocalPoint({ transform.position.x + (new_size * 2.4f),  transform.position.y - (new_size * 1) }), 0);

    front_elements.fixtureDefinition.shape = &front_elements.b2_shape;
    front_elements.fixtureDefinition.density = 100 / 10 ;
    front_elements.fixtureDefinition.friction = 3;
    front_elements.fixtureDefinition.restitution = 0;
    front_elements.fixtureDefinition.filter.groupIndex = -1;

    front_elements.fixture = body->CreateFixture(&front_elements.fixtureDefinition);

}
