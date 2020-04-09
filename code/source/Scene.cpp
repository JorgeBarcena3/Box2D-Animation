#include "..\headers\World.hpp"
#include "..\headers\Body.hpp"
#include "..\headers\Scene.hpp"
#include "..\headers\BallDynamic.hpp"
#include "..\headers\RectangleDynamic.hpp"
#include "..\headers\Windmill.hpp"
#include "..\headers\RectangleStatic.hpp"

using namespace Box2DAnimation;
using namespace sf;

std::shared_ptr< Scene > Scene::instance = std::shared_ptr<Scene>(nullptr);

std::shared_ptr<Scene> Scene::getInstance()
{

    if (Scene::instance)
    {
        return instance;
    }

    instance = std::shared_ptr<Scene>(new Scene());
    return instance;
}

void Box2DAnimation::Scene::addActionToPool(std::string action)
{
    instance->actionsToDo.push_back(action);
}

Box2DAnimation::Scene::Scene() : world(0, 100.0f, 1)
{
    Scene::instance = std::shared_ptr<Scene>(this);
    configScene();
    //Objeto de prueba
    player = std::shared_ptr<Body>(new BallDynamic(30, Body::BOX2D_LOCATION_ATTRBUTES({ { 89, 510}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Yellow })));
    player->tag = "Coche";

}

Box2DAnimation::Scene::~Scene()
{
}

void Box2DAnimation::Scene::update(float t)
{

    world.Update(t);
    windmill->update(t);
    player->update(t);

}

void Box2DAnimation::Scene::render(sf::RenderWindow& renderWindow)
{

    world.render(renderWindow);
    windmill->render(renderWindow);
    player->render(renderWindow);

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

            if (event.key.code == sf::Keyboard::D)
            {
                Scene::addActionToPool("D");
            }
            else if(event.key.code == sf::Keyboard::A)
            {
                Scene::addActionToPool("A");
            }

            break;

        }


    }

    poolActionsToDo();

    return false;


}

void Box2DAnimation::Scene::configScene()
{

    sf::Color backColor = sf::Color(128, 192, 255);
    sf::Color green = sf::Color(64, 192, 64);

    //Contenedor de bolas
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 511 }, 0, {38,387} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }), true)));
    body_list.push_back(std::shared_ptr<Body>(new RectangleDynamic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1175, 286 }, -50, {38,200} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleDynamic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1311, 286 }, 50, {38,200} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));

    windmill = std::shared_ptr<Windmill>(
        new Windmill(
            { 1240, 335 },
            body_list[body_list.size() - 3].get(),
            { body_list[body_list.size() - 2].get() ,body_list[body_list.size() - 1].get() }
        )
        );

    windmill->setTorqueSpeed(0.5f);

    //Suelo izquierda
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 96, 697 }, 0, {192,206} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1149, 773 }, -9, {620,225} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1490, 722 }, -9, {121,232} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));

    //Zona de activacion
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 1500, 400 }, 0, {50,800} }), world, Body::SMLF_SHAPES_ATIBUTES({ Color::Red }))));
    body_list[body_list.size() - 1]->tag = "Activacion";

    //Caja de destino para meter las bolas
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 548, 254}, 0, {192,34} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 429, 283}, 51, {34,98} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 370, 283}, -51, {34,98} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));

    //Rampa aproximada con cubos
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 193, 670}, -310, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 234, 704}, -317, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 273, 738}, -324, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 325, 763}, -333, {110,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 378, 777}, -346, { 93, 96} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 456, 785}, -356, { 80, 84} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 538, 786},   -8, { 87, 90} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 625, 765},  -25, {113,106} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));

    //Fondo Rampa
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 437, 800},    0, {491,100} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));
    body_list.push_back(std::shared_ptr<Body>(new RectangleStatic(Body::BOX2D_LOCATION_ATTRBUTES({ { 201, 751},    0, {065,125} }), world, Body::SMLF_SHAPES_ATIBUTES({ backColor }))));


    //Pelotas a spawnear
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 272}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1220, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1260, 240}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1200, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1220, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1241, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1260, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));
    body_list.push_back(std::shared_ptr<Body>(new BallDynamic(15, Body::BOX2D_LOCATION_ATTRBUTES({ { 1280, 220}, 0, {0,0} }), world, Body::SMLF_SHAPES_ATIBUTES({ green }))));


}

void Box2DAnimation::Scene::poolActionsToDo()
{
    for (auto action : actionsToDo)
    {
        if (action == "Start Windmill")
        {
            windmill->startTorque();
        }
        else if (action == "D")
        {
            auto body = player->body;

            auto newSpeed = b2Vec2(300 * body->GetMass(), 0);

            body->ApplyLinearImpulse(newSpeed, body->GetPosition(), true); 
        }
        else if (action == "A")
        {
            auto body = player->body;

            auto newSpeed = b2Vec2(-300 * body->GetMass(), 0);

            body->ApplyLinearImpulse(newSpeed, body->GetPosition(), true);
        }
    }

    actionsToDo.clear();
}
