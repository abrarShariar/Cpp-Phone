/*
    This file contains the features of SFML that is used for the graphical interface

    NOTE: Sohan Chowdury [15-30269-2] contributed in learning SFML
*/

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "Methods.h"

void showPhoneScreen(){
    //load font
    sf::Font font;
    font.loadFromFile("Timeless.ttf");

    string date=showDate();
    string time=showTime();
    //text to display date & time
    sf::Text viewDate(date,font);
    viewDate.setCharacterSize(15);
    viewDate.setPosition(0,0);
    viewDate.setColor(sf::Color::White);
    //time
    sf::Text viewTime(time,font);
    viewTime.setCharacterSize(15);
    viewTime.setPosition(340,0);
    viewTime.setColor(sf::Color::White);

    //texture (Phone icon)
    sf::Texture phoneIcon;
    phoneIcon.loadFromFile("image/phone_.png");
    //RectangleShape (Phone icon)
    sf::RectangleShape recPhone;
    recPhone.setSize(sf::Vector2f(45,45));
    recPhone.setOutlineColor(sf::Color::Black);
    recPhone.setOutlineThickness(2);
    recPhone.setPosition(60,50);
    recPhone.setTexture(&phoneIcon);
    //Text (Phone)
    sf::Text phoneText("Phone",font);
    phoneText.setCharacterSize(15);
    phoneText.setPosition(63,90);
    phoneText.setColor(sf::Color::White);

    //texture (Text icon)
    sf::Texture textIcon;
    textIcon.loadFromFile("image/Open_mail.png");
    //RectangleShape (Text)
    sf::RectangleShape recText;
    recText.setSize(sf::Vector2f(45,45));
    recText.setOutlineColor(sf::Color::Black);
    recText.setOutlineThickness(2);
    recText.setPosition(150,50);
    recText.setTexture(&textIcon);
    //Text (text app)
    sf::Text Text("Text",font);
    Text.setCharacterSize(15);
    Text.setPosition(158,90);
    Text.setColor(sf::Color::White);

    //Texture (Contact icon)
    sf::Texture contactIcon;
    contactIcon.loadFromFile("image/Contacts.png");
    //RectangleShape (Contacts)
    sf::RectangleShape recContact;
    recContact.setSize(sf::Vector2f(45,45));
    recContact.setOutlineColor(sf::Color::Black);
    recContact.setOutlineThickness(2);
    recContact.setPosition(240,50);
    recContact.setTexture(&contactIcon);
    //Text (Contacts)
    sf::Text contactText("Contacts",font);
    contactText.setCharacterSize(15);
    contactText.setPosition(240,90);
    contactText.setColor(sf::Color::White);

    //texture (Camera)
    sf::Texture cameraIcon;
    cameraIcon.loadFromFile("image/camera.png");
    //Rectangle Shape
    sf::RectangleShape recCamera;
    recCamera.setSize(sf::Vector2f(45,45));
    recCamera.setOutlineColor(sf::Color::Black);
    recCamera.setOutlineThickness(2);
    recCamera.setPosition(330,50);
    recCamera.setTexture(&cameraIcon);
    //Text (Camera)
    sf::Text cameraText("Camera",font);
    cameraText.setCharacterSize(15);
    cameraText.setPosition(331,90);
    cameraText.setColor(sf::Color::White);

    //Texture (Calculator)
    sf::Texture calIcon;
    calIcon.loadFromFile("image/calculator.png");
    //Rectangle (Calculator app)
     sf::RectangleShape recCal;
    recCal.setSize(sf::Vector2f(47,47));
    recCal.setOutlineColor(sf::Color::Black);
    recCal.setOutlineThickness(2);
    recCal.setPosition(60,120);
    recCal.setTexture(&calIcon);
    //Text (Calculator)
    sf::Text calText("Calculator",font);
    calText.setCharacterSize(15);
    calText.setPosition(63,160);
    calText.setColor(sf::Color::White);

    //Texture (Music)
    sf::Texture musicIcon;
    musicIcon.loadFromFile("image/music.png");
    //Rectangle (Music app)
     sf::RectangleShape recMusic;
    recMusic.setSize(sf::Vector2f(43,43));
    recMusic.setOutlineColor(sf::Color::Black);
    recMusic.setOutlineThickness(2);
    recMusic.setPosition(150,120);
    recMusic.setTexture(&musicIcon);
    //Text (Music)
    sf::Text musicText("Music",font);
    musicText.setCharacterSize(15);
    musicText.setPosition(153,160);
    musicText.setColor(sf::Color::White);

    //Texture (Facebook)
    sf::Texture fbIcon;
    fbIcon.loadFromFile("image/facebook.png");
    //RectangleShape (Facebook app)
    sf::RectangleShape recFb;
    recFb.setSize(sf::Vector2f(43,43));
    recFb.setOutlineColor(sf::Color::Black);
    recFb.setOutlineThickness(2);
    recFb.setPosition(240,120);
    recFb.setTexture(&fbIcon);
    //Text (Facebook)
    sf::Text fbText("Facebook",font);
    fbText.setCharacterSize(15);
    fbText.setPosition(240,160);

    //Texture (Google)
    sf::Texture googleIcon;
    googleIcon.loadFromFile("image/google.png");
    //RectangleShape (Google)
    sf::RectangleShape recGoogle;
    recGoogle.setSize(sf::Vector2f(43,43));
    recGoogle.setOutlineColor(sf::Color::Black);
    recGoogle.setOutlineThickness(2);
    recGoogle.setPosition(330,120);
    recGoogle.setTexture(&googleIcon);
    //Text
    sf::Text googleText("Google",font);
    googleText.setCharacterSize(15);
    googleText.setPosition(330,160);

    //texture (Qwerty)
    sf::Texture qwerty;
    qwerty.loadFromFile("image/qwerty.png");
    //RectangleShape (Qwerty)
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(380,200));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition(10,400);
    rectangle.setTexture(&qwerty);

sf::RenderWindow window(sf::VideoMode(400,600), "C++ Phone");

//  GAME LOOP
    while (window.isOpen())
    {

        sf::Event event;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        while (window.pollEvent(event))
        {
        if (event.type == sf::Event::Closed){
            window.close();
        }
        window.draw(viewTime);
        window.draw(viewDate);
        window.draw(recPhone);
        window.draw(phoneText);
        window.draw(recText);
        window.draw(Text);
        window.draw(recContact);
        window.draw(contactText);
        window.draw(recCamera);
        window.draw(cameraText);
        window.draw(recCal);
        window.draw(calText);
        window.draw(recMusic);
        window.draw(musicText);
        window.draw(recFb);
        window.draw(fbText);
        window.draw(recGoogle);
        window.draw(googleText);
        window.draw(rectangle);
        window.display();
        window.clear(sf::Color::Black);
    }
}
}
