#include "..\headers\World.hpp"
#include "..\headers\Body.hpp"
#include "..\headers\Scene.hpp"
#include "..\headers\BallDynamic.hpp"
#include "..\headers\RectangleDynamic.hpp"
#include "..\headers\Windmill.hpp"
#include "..\headers\RectangleStatic.hpp"

using namespace Box2DAnimation;
using namespace sf;

Scene* Scene::instance = nullptr;

Scene* Scene::getInstance()
{

    if (Scene::instance)
    {
        return instance;
    }

    instance = new Scene();
    return instance;
}

void Box2DAnimation::Scene::addActionToPool(std::string action)
{
    instance->actionsToDo.push_back(action);
}

Box2DAnimation::Scene::Scene() : world(0, 200, 1)
{
    Scene::instance = this;
    configScene();

}

Box2DAnimation::Scene::~Scene()
{
    delete elevator;
    delete car;
    delete windmill;
}

void Box2DAnimation::Scene::update(float t)
{

    world.Update(t);
    windmill->update(t);
    car->update(t);
    elevator->update(t);


}

void Box2DAnimation::Scene::render(sf::RenderWindow& renderWindow)
{

    if (debugMode)
        world.get_b2World()->DebugDraw();
    else
    {

        windmill->render(renderWindow);
        car->render(renderWindow);
        elevator->render(renderWindow);
        world.render(renderWindow);

    }

}

bool Box2DAnimation::Scene::manageInput(sf::RenderWindow& window)
{

    Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:

            return true;
            break;


        case Event::KeyPressed:

            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
            {
                Scene::addActionToPool("Car right");
            }
            else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
            {
                Scene::addActionToPool("Car left");
            }
            else if (event.key.code == sf::Keyboard::P)
            {
                Scene::addActionToPool("AppearElevator");
            }
            else if (event.key.code == sf::Keyboard::O)
            {
                Scene::addActionToPool("Stop");
            }
            else if (event.key.code == sf::Keyboard::N)
            {
                Scene::addActionToPool("StartParticles");
            }
            else if (event.key.code == sf::Keyboard::M)
            {
                Scene::addActionToPool("StopParticles");
            }
            else if (event.key.code == sf::Keyboard::R)
            {
                Scene::addActionToPool("RotateCar");
            }

            break;

        }


    }

    poolActionsToDo();

    return false;


}

void Box2DAnimation::Scene::setDrawTool(SFMLDebugDraw& draw)
{
    world.drawer = &draw;
    world.get_b2World()->SetDebugDraw(&draw);

    draw.SetFlags(b2Draw::e_shapeBit);
    draw.AppendFlags(b2Draw::e_centerOfMassBit);
    draw.AppendFlags(b2Draw::e_jointBit);

}

void Box2DAnimation::Scene::configScene()
{

    sf::Color backColor = sf::Color(128, 192, 255);
    sf::Color green = sf::Color(64, 192, 64);

    //Contenedor de bolas
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 511 }, 0, {38,387} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }), true));
    body_list.push_back(new RectangleDynamic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1175, 286 }, -50, {38,200} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list.push_back(new RectangleDynamic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1311, 286 }, 50, {38,200} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));

    windmill =
        new Windmill(
            { 1240, 335 },
            body_list[body_list.size() - 3],
            { body_list[body_list.size() - 2],body_list[body_list.size() - 1] }
    );

    windmill->setTorqueSpeed(0.5f);

    //Suelo izquierda
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 96, 697 }, 0, {192,206} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));

    //Suelo derecha
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1149, 773 }, -9, {620,225} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));

    //Zona de activacion
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1490, 722 }, -9, {121,232} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Activacion";

    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1550, 400 }, 0, {50,800} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red })));

    //Caja de destino para meter las bolas
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 548, 254}, 0, {300,34} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 350, 300}, 51, {34,150} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list[body_list.size() - 1]->tag = "Plataforma final";
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 250, 300}, -51, {34,150} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list[body_list.size() - 1]->tag = "Plataforma final";

    //Rampa aproximada con cubos
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 193, 670}, -310, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 234, 704}, -317, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 273, 738}, -324, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 325, 763}, -333, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 378, 777}, -346, { 93, 96} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 456, 785}, -356, { 80, 84} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 538, 786},   -8, { 87, 90} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 625, 770},  -20, {113,106} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));

    //Fondo Rampa
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 437, 800},    0, {491,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));
    body_list.push_back(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 201, 751},    0, {065,125} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor })));


    //Pelotas a spawnear
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 272}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1220, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1260, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1200, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1220, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";
    body_list.push_back(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1260, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green })));
    body_list[body_list.size() - 1]->tag = "Pelota";

    //Ascensor
    elevator = new Elevator(Body::BOX2D_LOCATION_ATTRBUTES({ { 760, 1200}, 0, {195,34} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }));
    elevator->tag = "Elevator";

    //Objeto de prueba
    car = new Car(Car::CAR_ATTRBUTES({}), Body::SMLF_SHAPES_ATIBUTES({ sf::Color::Yellow }), "Coche");



}

void Box2DAnimation::Scene::poolActionsToDo()
{

    for (auto action : actionsToDo)
    {
        if (action == "Start Windmill")
        {
            windmill->startTorque();
        }
        else if (action == "Car right")
        {

            car->acelerate(-1);

        }
        else if (action == "Car left")
        {

            car->acelerate(1);
        }
        else if (action == "AppearElevator")
        {
            elevator->up(0, 725);
        }
        else if (action == "Stop")
        {
            elevator->Stop();
        }
        else if (action == "ElevatorStart")
        {
            elevator->up(5, 250);
        }
        else if (action == "StartParticles")
        {
            car->startParticles();
        }
        else if (action == "StopParticles")
        {
            car->stopParticles();
        }
        else if (action == "RotateCar")
        {
            car->rotateCar();
        }

    }

    actionsToDo.clear();
}
