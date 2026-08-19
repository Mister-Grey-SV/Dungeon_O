# Project O

A small console-based dungeon crawler written in C++ as a personal learning project.

The game combines turn-based movement, simple enemy AI, line-of-sight, melee combat, items, messages, score calculation, and a persistent leaderboard.

## About

Project O was created as a practical C++ project to bring together a large part of the language and standard library topics learned during self-study.

The game is intentionally simple in terms of gameplay.

## Gameplay

The player's main objective is to find a way out of the dungeon.

There are several possible approaches:

1. Escape as quickly as possible.
2. Find the treasures and escape.
3. Clear as much of the dungeon as possible before escaping.

The game tracks performance and converts it into a score.

### Scoring

The score is calculated from:

* collected treasures
* found and used healing potions
* defeated enemies
* number of player turns

The scoring system is designed to reward both speed and exploration.

## Features

### Turn-based gameplay

The player and enemies take turns.

The player can:

* move
* attack
* use healing potions

### Enemy AI

Enemies have simple behaviour states:

* idle/patrol
* combat

Patrolling enemies follow predefined horizontal or vertical routes.

When an enemy detects the player and has line of sight, it switches to combat behaviour.

### Line of sight

The game uses a grid-based line-of-sight algorithm to determine whether the player and an enemy can see each other.

### Combat

Combat uses dice-based attacks inspired by tabletop RPG mechanics.

Attacks include:

* attack roll
* armor class check
* damage roll
* hit/miss result
* kill result

Combat information is shown in the on-screen battle log.

### Items

The dungeon contains:

* healing potions
* keys
* treasures
* exits

Bosses provide keys when defeated.

### Messages and events

The game can display contextual messages when the player:

* discovers items
* reaches special locations
* encounters locked objects
* triggers scripted events

### Leaderboard

Each record contains:

* player name
* total score
* treasures
* turns
* defeated enemies

The leaderboard keeps the top 15 results.

Records are stored in a binary file and loaded automatically when the game starts.

## Project Structure

The project is split into several main components.

### `Game`

Contains the main gameplay loop and coordinates game actions.

Responsible for:

* turn handling
* movement
* combat
* game results
* score tracking

### `World`

Stores the dungeon grid and its cells.

Responsible for:

* map state
* actor positions
* walls
* items
* messages
* line of sight

### `Player`

Represents actors participating in the game.

Stores:

* position
* direction
* stats
* inventory
* movement state
* behaviour

### `AI`

Controls enemy decision making.

It determines whether an enemy should patrol, approach the player, attack, or end its turn.

### `Render`

Handles all console rendering.

The project uses the Windows Console API to control cursor positioning.

### `Interface`

Handles user input.

Gameplay commands are read directly from the keyboard using `_getch()`.

### `RecordManager`

Handles leaderboard data.

Responsible for:

* creating records
* calculating scores
* sorting records
* limiting the leaderboard size
* saving records
* loading records

### `level_data`

Contains the static level description, including:

* actor placement
* item placement
* messages
* dungeon layout

Keeping level data separate from game logic makes the gameplay code easier to work with.

## Controls

### Menu

| Key | Action           |
| --- | ---------------- |
| `W` | Move cursor up   |
| `S` | Move cursor down |
| `F` | Select           |
| `Q` | Exit / No        |

### Gameplay

| Key     | Action             |
| ------- | ------------------ |
| `W`     | Move up            |
| `S`     | Move down          |
| `A`     | Move left          |
| `D`     | Move right         |
| `F`     | Attack / Confirm   |
| `R`     | Use healing potion |
| `Space` | Finish turn        |
| `Q`     | Exit               |

Uppercase and lowercase input are both accepted.

## Technical Notes

This project is primarily a learning project rather than a production-ready game.

The current version intentionally uses:

* hardcoded level data
* console rendering
* Windows-specific console functionality
* a simple binary format for leaderboard records

## Build

The project was developed on Windows using Visual Studio.

A Windows C++ compiler and the Windows Console API are required.

## Status

The game is considered complete in its current scope.

## Screenshots

The current version is a console-based game designed around a fixed-width layout and full-screen console presentation.
