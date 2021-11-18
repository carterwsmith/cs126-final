# Typing Tester | CS 126 Final Project

This project is a Cinder game application that is based on tracking and recording the player's typing speed. The interface of the game is made up of displaying a prompt that the user types as fast as possible, advancing as correct characters are typed and constantly recording their average speed in words per minute (WPM = characters typed per minute / 5). When the prompt is finished, a final average WPM is displayed to the user which can be used as a benchmark for future results.

## Background Knowledge

### Project Introduction
I have been interested in speed typing and improving my typing skills since I started using Typeracer as part of an elementary school class in 2009. Here is my scorecard: 

<a href="https://data.typeracer.com/pit/profile?user=cws2002&ref=badge" target="_top"><img src="https://data.typeracer.com/misc/badge?user=cws2002" border="0" alt="TypeRacer.com scorecard for user cws2002"/></a>

While the Typeracer website is good for the most part, it lacks some features such as the ability to practice custom prompts or participate in races solo. Developing an application such as this will allow me to practice typing in an offline, lightweight, and fully customizable environment. 

There are many applicable benefits to an application like this, including reduced inaccuracies of calculating speeds due to communication between client and server, the ability to import custom prompts that test certain typing idiosyncrasies, and smaller intervals of time between races.

For example, here is a histogram of my fastest race ever, which registered at exactly 200 WPM:

<a href="https://data.typeracer.com/pit/result?id=|tr:cws2002|1377"><img src="https://i.ibb.co/kHb2TjZ/Screen-Shot-2021-03-24-at-3-55-43-PM.png"/></a>

You can see pretty clearly that my average speed was well over 200 WPM for the entirety of the race, yet Typeracer's client-server interface resulted in some additional time that changed the final result. This error will be largely eliminated with this application.

### Setup Considerations
 - I plan to use JSON or some other library that allows users to import a set of prompts that will randomly be selected from for each race
 - The client's typing should be recorded directly through the application
 - Otherwise, the application will be entirely self-contained

## Timeline

### Week 1
By the end of Week 1, I will have:

- Created appropriate headers and source files
- Assigned member variables to each data object
- Designed the structure of the application with proper encapsulation

### Week 2
By the end of Week 2, I will have:

- Created UI elements that display on the screen for each race
- Constructed an accurate WPM tracker
- A playable application that displays an average WPM result

### Week 3
By the end of Week 3, I will have:

- Polished the user interface and gameplay
- Considered additional features to improve the application
- Thoroughly tested the application

## Stretch Goals

### High Score
For each game session, track the highest WPM for each prompt. Display it at the end of each race next to the player's actual score for the race.

### WPM Averaging
Track the user's WPM for each race, calculating a running average of all WPM scores and displaying it somewhere on the application.

### Player Scores
At the start of each session, record the player's name. If the player achieves a high score for a prompt, record their name along with the score to be displayed for future sessions.
