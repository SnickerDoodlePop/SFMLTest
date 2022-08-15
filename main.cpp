#include <SFML/Graphics.hpp>

float vy = 0.f, ay = 0.5f, velIncrement = -25;

void moveOrb(sf::CircleShape &orb){
    sf::Vector2f currentPos = orb.getPosition();
    if(abs(currentPos.y - 900) <= 30){
        vy = velIncrement;
        velIncrement += 2.5;
        if(velIncrement >= 0){
            ay = 0;
            vy = 0;
        }
    }
    currentPos.y += vy;
    vy += ay;
    orb.setPosition(currentPos);
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pondering My Orb..");
    sf::CircleShape shape(100.f);
    shape.setPosition(960-(100/2), 0);
    shape.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        _sleep(7);
        moveOrb(shape);
        window.clear();
        window.draw(shape);
        window.display();
        if(!ay){
            window.close();
        }
    }

    return 0;
}