# Virtual Cricket Game in C++

## Overview
This project is an Object-Oriented Programming (OOP) based virtual cricket game developed in C++. The game adheres to specific rules and functionalities, offering a simulated cricket experience.

## Game Rules and Features

### Team Composition
- Two teams: `TeamA` and `TeamB`
- Each team consists of 4 players.
- Users select players for each team from a pool of 11 predefined players.

### Innings Structure
- Two innings for each match.
- Each inning comprises 6 balls.
- One bowler from the bowling team bowls all 6 deliveries, while one batsman from the batting team faces these deliveries.

### Toss Functionality
- Toss decides the team to bat or bowl first.

### Gameplay Mechanics
- Batting and bowling sequence determined by player selection.
- Scoring range: 0 to 6 runs per delivery.
- Batsman declared OUT if they score 0 runs; next batsman in line begins batting.

### Match Conclusion
- Team with higher total runs wins.
- In case of a tie in runs, the match ends in a draw.

### User Experience Enhancements
- Functions to display:
    - Pool of 11 players
    - Players selected for each team
    - Game scorecard after each delivery
    - Match summary upon game completion

## How to Use
1. Clone the repository.
2. Compile the code in a C++ environment.
3. Run the executable file generated after compilation.

## Contributing
Contributions are welcome! Fork the repository, make your changes, and create a pull request.
