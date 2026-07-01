<a name="readme-top"></a>

<!-- GENERAL GAME INFO -->
<br />
<div align="center">

  <h2 align="center">Vampire survivor</h2>

  <p align="center">
    Vampire Survivors is a fast-paced but simple bullet-hell roguelite where hordes of monsters attempt to overwhelm you. The game was released on October 20, 2022.
    <br />
    <strong>Original game : </strong>
    <a href="https://store.steampowered.com/app/1794680/Vampire_Survivors/"><strong>General info »</strong></a>
    ·
    <a href="https://www.youtube.com/watch?v=bzYEU3rBD-Y"><strong>Youtube video »<strong></a>
    <br />
    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#my-version">My version</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
    </li>
    <li><a href="#how-to-play">How To Play</a></li>
    <li><a href="#class-structure">Class structure</a></li>
    <li><a href="#checklist">Checklist</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

 
<img src="https://shared.fastly.steamstatic.com/store_item_assets/steam/apps/1794680/ss_6105ad3d6af52593c31d915bf39e91512611ea8e.1920x1080.jpg?t=1763675244" alt="Second picture on the steam store">

Here's why:
* It's one of my favourite games of all time.
* The game is complex in ways that I find more interesting to work on.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## My version

This section gives a clear and detailed overview of which parts of the original game I planned to make.



### The minimum I will most certainly develop:
* Main screen <br>Start button -> Takes you to character selection<br>Gold counter<br>Quit button
* Character select shows available/unlockable characters. If a character is selected it also shows their passive bonus and stats.
* The first level/map <br>-Repeating map<br>-Tree, pond, garden and grave obstacles
* Base movement in x, y and diagonal directions 
* Power selection. On level up you can get a new weapon or passive item or upgrade a weapon or passive item you already have. It shows you your current weapons and their current level and current stats.
* The four base player characters (different sprites and base stats)<br>- Antonio <br>- Imelda <br>- Pasqualina<br>- Gennaro
* The seven base weapons <br>- Whip<br>- Magica Wand<br>- Knife<br>- Axe<br>- King Bible<br>- Santa Water<br>- Laurel
* The two base passive items <br>- Spinach<br>- Armor
* Light sources (the brazier) that can be destroyed for some pick-ups 
* Basic pick-ups (Experience gem, Gold Coin, Floor chicken, Treasure Chest)
* Three to four base enemies (based on bahaviour) <br>-Basic enemies (Moves to the player position)<br>Bats, Skeletons, Zombies, Mudman <br>-"Pusher" enemies (Moves through the screen pushing other enemies)<br>Bats<br>"Wall" enemies (Forms an arena around the player) <br> Flower Wall <br>- Boss enemies (drops chests)<br> Mantis
* Hud with timer, showing weapons and passive items, showing lvl, level progress, timer and kill count
* Animation of enemies and the player
* Audio effects and music
* Pause stops the simulation of the game. Shows your items and their current level and your current stats.
* Results screen shows the time survived, gold earned, level reached, enemies defeated, what passive items and weapons you had in the run, how much damage you did with each weapons, how long you had each weapon and the weapon's dps for that round and what and how many pick-ups you picked up.

### What I will probably make as well:
* Additional characters (4 to 8)
* Weapon evolutions
* Additional passive items and weapons

### What I plan to create if I have enough time left:
* Additional levels/maps
* Unlocking the additional weapons and characters through achievements
* The power-up shop on the main menu

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started
Detailed instructions on how to run your game project are in this section.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* Visual Studio 2022

### How to run the project

Download, build and run the latest version of the project. <br>
No extra steps are required

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- HOW TO PLAY -->
## How to play


### Controls
* Left click on the start button (blue rectangle) to start the game
* wasd or arrow keys to move around 

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CLASS STRUCTURE -->
## Class structure 

### Inheritance 
Enemy:
  Following Enemy<br>
All enemies have the same basic structure but based on behaviour they move differently.<br><br>

Weapon: Whip weapon<br>
All weapons share the same basic structure. The main difference comes from the type of projectlyle they spawn and which stats get buffed on upgrade.<br><br>

Projectile: Whip projectile<br>
Overrides the behaviour of the projectile<br><br>

GameState: StartScreen, GameLoop<br>
Allows easy switching between the main game states without cluttering up the game class

### ..

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CHECKLIST -->
## Checklist

- [x] Accept / set up github project
- [x] week 01 topics applied
    - [x] const keyword applied proactively (variables, functions,..)
    - [x] static keyword applied proactively (class variables, static functions,..)
    - [x] object composition (optional)
- [x] week 02 topics applied
- [x] week 03 topics applied
- [x] week 04 topics applied
- [x] week 05 topics applied
- [x] week 06 topics applied
- [x] week 07 topics applied
- [x] week 08 topics applied
- [ ] week 09 topics applied (optional)
- [ ] week 10 topics applied (optional)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Your Name - Attila.SZEREMI@student.howest.be

Project Link: [https://github.com/AttilaSzeremi/Retake-GD14-Szeremi-Attila](https://github.com/AttilaSzeremi/Retake-GD14-Szeremi-Attila)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments


* [Example 1: cpp reference on std::vector](https://en.cppreference.com/w/cpp/container/vector)
<!-- * .. -->

<p align="right">(<a href="#readme-top">back to top</a>)</p>

