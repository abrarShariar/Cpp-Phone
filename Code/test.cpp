/*
    This file contains the features of SFML that is used for the graphical interface

    NOTE: Sohan Chowdury [15-30269-2] contributed in learning SFML
*/
#include<iostream>
#include<string>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace std;

void playMusic(string name);

void playMusic(string name){
   sf::RenderWindow window(sf::VideoMode(250, 350), " MUSIC ");

 //Texture (Music Play icon)
    sf::Texture playIcon;
    playIcon.loadFromFile("image/musicPlay.png");
    //Rectangle (Music app)
     sf::RectangleShape recMusicPlay;
    recMusicPlay.setSize(sf::Vector2f(100,100));
    recMusicPlay.setOutlineThickness(2);
    recMusicPlay.setPosition(70,50);
    recMusicPlay.setTexture(&playIcon);

    //Texture (Music Stop icon)
    sf::Texture stopIcon;
    stopIcon.loadFromFile("image/stop.png");
    //Rectangle (Music STOP app)
     sf::RectangleShape recMusicStop;
    recMusicStop.setSize(sf::Vector2f(50,50));
    recMusicStop.setPosition(95,200);
    recMusicStop.setTexture(&stopIcon);

    name="music/"+name;

//Code for playing MUSIC intro
    sf::Music musicFile;
    musicFile.openFromFile(name);
    musicFile.setVolume(60);         // reduce the volume

    /*
    introMusic.setPosition(0, 1, 10); // change its 3D position
    introMusic.setPitch(2);           // increase the pitch
    introMusic.setLoop(true);         // make it loop
    */

    // Play it
    //musicFile.play();

    // run the program as long as the window is open
    while (window.isOpen())
    {

            //Mouse Position (Phone App)
    sf::Vector2f recPos=recMusicStop.getPosition();
    sf::Vector2i mousePos=sf::Mouse::getPosition(window);

    if((mousePos.x>recPos.x && mousePos.x<recPos.x+50) && (mousePos.y>recPos.y && mousePos.y<recPos.y+50)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            window.close();
        }
    }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
                }
            window.draw(recMusicPlay);
            window.draw(recMusicStop);
            window.display();
            window.clear(sf::Color::White);
        }
    }
}

int main(){
    string name="wake_me_up.wav";
    playMusic(name);

}





