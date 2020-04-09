#include "..\headers\Windmill.hpp"
#include "..\headers\World.hpp"
#include "..\headers\Body.hpp"

Box2DAnimation::Windmill::Windmill(b2Vec2 _center, Body* _Stick, std::vector<Body*> _Bodies)
{
    center = _center;
    stick = std::shared_ptr<Body>( _Stick );
    eneabled = false;

    for (auto body : _Bodies)
    {
        torques.push_back
        (
            std::shared_ptr<RotationTorque>
            ( 
                new RotationTorque
                (
                    10, 
                    Body::BOX2D_LOCATION_ATTRBUTES({ { 1240, 335 }, 0, {0,0} }),
                    *(World::getInstance()),
                    Body::SMLF_SHAPES_ATIBUTES({ sf::Color::Red })
                )
             )
        );

        body->setGravity(0);
        torques[torques.size() - 1]->setJointBodies(*stick, *body, center);

    }

}

void Box2DAnimation::Windmill::render(sf::RenderWindow& renderWindow)
{
    for (auto join : torques)
    {
        join->render(renderWindow);
    }
}

void Box2DAnimation::Windmill::update(float time)
{
    for (auto join : torques)
    {
        join->update(time);
    }
}

void Box2DAnimation::Windmill::startTorque()
{

    for (auto join : torques)
    {
        join->eneableMotor(true);
        join->getDynamicBody()->SetGravityScale(1);
    }

    eneabled = true;

    
}

void Box2DAnimation::Windmill::stopTorque()
{

    for (auto join : torques)
    {
        join->eneableMotor(false);
        join->getDynamicBody()->SetGravityScale(0);
        join->getDynamicBody()->SetLinearVelocity(b2Vec2_zero);
    }

    setTorqueSpeed(0);
    eneabled = false;


}

void Box2DAnimation::Windmill::setTorqueSpeed(float _speed)
{

    torqueSpeed = _speed;

    for (auto join : torques)
    {
        join->setSpeed(torqueSpeed);
    }
}
