#include "..\headers\Body.hpp"
#include "..\headers\Car.hpp"
#include "..\headers\World.hpp"

using namespace Box2DAnimation;

Box2DAnimation::Car::Car(CAR_ATTRBUTES CAR_ATTRB, Body::SMLF_SHAPES_ATIBUTES attrb, std::string tag)
{

    // ************************ THE CAR ************************ //

    Body::SMLF_SHAPES_ATIBUTES carAttr({ sf::Color::Yellow });

    Body::BOX2D_LOCATION_ATTRBUTES chasisAttrb(
        {
            { 96, 500 },
            0, 
            {120,20}
        });

    chasis = std::shared_ptr<Chasis>(new Chasis(chasisAttrb, *World::getInstance().get(), carAttr));
    chasis->tag = tag;

}


void Box2DAnimation::Car::update(float time)
{

    if (chasis != nullptr)
        chasis->update(time);

}

void Box2DAnimation::Car::render(sf::RenderWindow& window)
{
    if (chasis != nullptr)
        chasis->render(window);
}
