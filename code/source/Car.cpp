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
            { 96, 450 },
            0,
            {120,20}
        });

    chasis = std::shared_ptr<Chasis>(new Chasis(chasisAttrb, *World::getInstance().get(), carAttr));
    chasis->tag = tag;

    Body::BOX2D_LOCATION_ATTRBUTES front_wheel_attrb(
        {
            { 56, 510 },
            0,
            {20,20}
        });

    front_wheel = std::shared_ptr<Wheel>(new Wheel(front_wheel_attrb, *World::getInstance().get(), attrb));
    front_wheel->tag = "Coche";

    Body::BOX2D_LOCATION_ATTRBUTES back_wheel_attrb(
        {
            { 130, 510 },
            0,
            {20,20}
        });

    back_wheel = std::shared_ptr<Wheel>(new Wheel(back_wheel_attrb, *World::getInstance().get(), attrb));
    back_wheel->tag = "Coche";
    configJoins();
}


void Box2DAnimation::Car::update(float time)
{

    static float motorSpeed = 0;

    switch (status)
    {

    case -1:

        motorSpeed += 1;
        break;

    case 1:

        motorSpeed -= 1;
        break;

    default:

        break;
    }

    status = 0;

    motorSpeed *= 0.99;
    if (motorSpeed < -25) {
        motorSpeed = -25;
    }
    front_wheel->acelerate(motorSpeed);
    back_wheel->acelerate(motorSpeed);

    front_join->SetMaxMotorForce(abs(600 * front_join->GetJointTranslation()));
    front_join->SetMotorSpeed((front_join->GetMotorSpeed() - 10 * front_join->GetJointTranslation()));

    back_join->SetMaxMotorForce(abs(600 * back_join->GetJointTranslation()));
    back_join->SetMotorSpeed((back_join->GetMotorSpeed() - 10 * back_join->GetJointTranslation()));


    if (chasis != nullptr)
        chasis->update(time);

    if (back_wheel != nullptr)
        back_wheel->update(time);

    if (front_wheel != nullptr)
        front_wheel->update(time);
}

void Box2DAnimation::Car::render(sf::RenderWindow& window)
{
    if (chasis != nullptr)
        chasis->render(window);

    if (back_wheel != nullptr)
        back_wheel->render(window);

    if (front_wheel != nullptr)
        front_wheel->render(window);
}

void Box2DAnimation::Car::acelerate(int state)
{

    status = state;
}

void Box2DAnimation::Car::decelerate()
{
    front_wheel->decelerate();
    back_wheel->decelerate();
}

void Box2DAnimation::Car::configJoins()
{

    // ************************ PRISMATIC JOINTS ************************ //
            //  definition
    b2PrismaticJointDef axlePrismaticJointDef = b2PrismaticJointDef();
    axlePrismaticJointDef.lowerTranslation = -0.3f;
    axlePrismaticJointDef.upperTranslation = 0.5f;
    axlePrismaticJointDef.enableLimit = true;
    axlePrismaticJointDef.enableMotor = true;

    // front axle
    axlePrismaticJointDef.bodyA = chasis->body;
    axlePrismaticJointDef.bodyB = front_wheel->getAxe()->getb2Body();
    axlePrismaticJointDef.Initialize(chasis->body, front_wheel->getAxe()->getb2Body(), front_wheel->getAxe()->getb2Body()->GetWorldCenter(), b2Vec2(cosf(b2_pi / 3), sinf(b2_pi / 3)));
    front_join = (b2PrismaticJoint*)World::getInstance()->get_b2World()->CreateJoint(&axlePrismaticJointDef);

    // rear axle
    axlePrismaticJointDef.bodyA = chasis->body;
    axlePrismaticJointDef.bodyB = back_wheel->getAxe()->getb2Body();
    axlePrismaticJointDef.Initialize(chasis->body, back_wheel->getAxe()->getb2Body(), back_wheel->getAxe()->getb2Body()->GetWorldCenter(), b2Vec2(1, 0));
    back_join = (b2PrismaticJoint*)World::getInstance()->get_b2World()->CreateJoint(&axlePrismaticJointDef);


}
