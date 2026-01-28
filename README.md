# c-game-project
CAR RACING GAME IN C++ (CONSOLE BASED)

Introduction

This is a console-based Car Racing and Dodging Game developed in C++.  
The game is designed to simulate a simple racing environment where the player must avoid enemy cars coming from above.

I built this project while learning the fundamentals of programming in C++, especially focusing on real-time input handling, loops, conditions, and game logic development.


Purpose of This Project

The main reason I created this game was to move beyond basic beginner programs and build something interactive.

This project helped me understand:

• How a game loop works  
• How objects can move inside a console screen  
• How keyboard input can be captured instantly  
• How collision detection is implemented  
• How scoring and difficulty progression are managed  


Game Concept

The gameplay is simple but challenging:

• The player controls a car placed at the bottom of the road  
• Enemy cars appear randomly in lanes and move downward  
• The road consists of three lanes  
• The player must switch lanes to avoid collision  
• A collision results in immediate game over  
• Every enemy car that passes safely increases the score  


Main Features Included

This project contains several complete game features:

• Three-lane road system  
• Player movement using arrow keys  
• Multiple enemy cars falling simultaneously  
• Random enemy respawn positions  
• Collision detection system  
• Score counter  
• Speed increase as score grows  
• Start menu and instruction screen  
• Restart option after game over  


Player Controls

The game uses keyboard controls:

• Left Arrow Key → Move car to the left lane  
• Right Arrow Key → Move car to the right lane  
• ESC Key → Exit the game anytime  
• R Key → Restart the game after Game Over  


Enemy Cars System

The game includes three enemy vehicles at once.

Each enemy has:

• Its own lane position  
• Its own vertical movement  
• A random spawn lane after crossing the screen  

This creates a more realistic and challenging experience compared to a single obstacle game.


Collision Detection Logic

Collision occurs when:

• An enemy reaches the player’s row  
• Both are in the same lane  

Once collision happens, the game ends immediately.


Scoring System

The score increases when:

• An enemy car successfully reaches the bottom and disappears  
• The player survives longer  

This makes the score a measure of survival and performance.


Difficulty Progression

To make the game more engaging, speed increases gradually:

• Every 5 points, the game delay reduces  
• Enemy cars move faster over time  

This creates increasing challenge as the player progresses.


Technologies and Libraries Used

This project is written in C++ and uses the following libraries:

• iostream → For console output  
• conio.h → For keyboard input without waiting  
• windows.h → For cursor movement and Sleep function  
• ctime → For random enemy spawning  


Platform Note

This is a Windows-only console project because it depends on:

• conio.h  
• windows.h  

It will not run directly on Linux or Mac without modifications.


How to Run the Game

Requirements:

• Windows operating system  
• Any C++ IDE (CodeBlocks, Dev-C++, Visual Studio)  
• MinGW or MSVC compiler  

Steps:

• Download or clone the repository  
• Open the source file in your IDE  
• Compile and run the program  
• Use arrow keys to play  


Future Improvements

In the next versions, I plan to add:

• High score saving system  
• Better road and car graphics  
• Additional levels and lanes  
• Power-ups and bonus points  
• Cross-platform support  


Developer Information

Developed by: Muhammad Hamza Imran 
Program: BS Artificial Intelligence  
Learning Focus: C++ Programming, Logic Building, Console Game Development

This project was a great learning experience and an important step in strengthening my programming skills.

