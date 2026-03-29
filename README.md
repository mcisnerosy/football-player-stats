# football-player-stats

A command-line American football analytics program written in C that manages offensive and defensive player databases, tracks position-specific statistics, and displays formatted stat tables by player, team, or position.

## Overview
This program provides a fully interactive CLI for building and querying a football player database. Users can add offensive and defensive players with position-specific stats, look up individual players, and view entire team rosters broken out by position group — all formatted as clean stat tables directly in the terminal.

The program handles two separate databases simultaneously:
- **Offense** — QB, HB, WR, TE, OL with position-specific stat tracking
- **Defense** — DL, LB, CB, S with unified defensive stat tracking

Key features:
- Add offensive players with stats tailored to their position (e.g. QBs track passer rating, WRs track receiving %, OL tracks pancakes and pressures)
- Add defensive players tracking tackles, sacks, pass deflections, forced fumbles, interceptions, and defensive TDs
- Automatically calculates derived stats — QB passer rating, completion %, rush average, reception %
- View any individual player by name, school, position, and grad year
- View full team rosters broken into position groups (QBs, Skill Players, Linemen, Defense)
- Formatted stat table output with column headers for clean terminal display

## Tech Stack
- C
- Structs for offensive and defensive player data models
- Dynamic string comparison and input validation
- Modular design across header and source files
- Makefile for streamlined compilation

## How to Run
1. Clone the repo
2. Compile using the Makefile:
```bash
make
```
3. Run the program:
```bash
./football
```
4. To clean compiled files:
```bash
make clean
```

## Program Options
```
-------------------------------------

Options:

  o: add an offensive player to the database
  d: add a defensive player to the database
  v: view a player from the database
  t: view a team from the database
  p: view a position from the database
  q: quit the program
```

## Supported Positions
**Offense:** QB, HB, WR, TE, OL

**Defense:** DL, LB, CB, S

## Example — Adding a QB
```
Enter the first name of the player: Patrick
Enter the last name of the player: Mahomes
Enter the abbreviation of the school: KC
Enter the player's grad year (FR, SO, JR, SR, GRAD): SR
Enter the player's position: QB
Enter the number of games played: 17

[Stats prompted: passing yards, attempts, completions, TDs,
rush yards, attempts, TDs, interceptions, fumbles, sacks]

KC QB Patrick Mahomes has been added to the database!
```

## Example — Viewing a Team
```
Enter the abbreviation of the team: KC

Team found!

Quarterbacks
| INIT. | POS | SCHOOL | YEAR | PASS YDS | PASS ATT | PASS CMP | PASS CMP % | ...
| PM    | QB  | KC     | SR   | 5250     | 597      | 401      | 67.2       | ...

Skilled Players
| INIT. | POS | SCHOOL | YEAR | REC YDS | REC TGTS | ...
...
```

## Project Structure
```
football-player-stats/
├── project.c        # Main program entry point and menu loop
├── footballFunc.c   # All function implementations
├── footballFunc.h   # Offense/Defense struct definitions and function declarations
├── Makefile         # Compilation instructions
└── README.md
```

## Acknowledgements
University of Notre Dame — CSE 20311 Fundamentals of Computing
