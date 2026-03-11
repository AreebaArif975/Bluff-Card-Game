# 🃏 Bluff Card Game — OOP Simulation (C++)

A fully object-oriented multiplayer Bluff card game simulation in C++, demonstrating core OOP principles through a structured 6-class hierarchy.

---

## 📌 Overview

This project implements the classic Bluff card game for 4 players using a standard 52-card deck. Built entirely in C++, it applies multiple inheritance, polymorphism, friend classes, and file handling to simulate complete gameplay — from deck shuffling and card distribution to bluff detection, challenge resolution, and result recording.

---

## 👥 Team

| Name | Role |
|------|------|
| Areeba Arif | Team Lead |
| Wishmah Akhtar | Derivation simulation, bug fixing |
| Aqsa Zaib | String parsing, edge case handling |

---

## 🛠️ Tech Stack

| Tool | Purpose |
|------|---------|
| C++ | Core language |
| File I/O | Recording player names and game results |

---

## 🎮 How to Play

- 4 players are dealt 13 cards each from a shuffled 52-card deck
- The lead player declares a rank and places cards face-down
- Other players must play cards of the same declared rank (or bluff)
- Any player can challenge by calling **"Bluff!"**
  - If the challenge is correct → the bluffing player picks up the pile
  - If the challenge is wrong → the challenger picks up the pile
- First player to empty their hand wins

---

## ✨ Features

- ✅ Random swap-based deck shuffling
- ✅ Even card distribution among 4 players
- ✅ Turn-based gameplay with pass/play/challenge options
- ✅ Bluff detection and challenge resolution logic
- ✅ File handling to record player names and game results
- ✅ Full OOP class hierarchy

---

## 🏗️ Class Structure

```
numCard         faceCard
    \               /
         Card
          |
        Player
          |
         Game ←→ back (friend class)
```

| Class | Responsibility |
|-------|---------------|
| `numCard` | Manages numeric cards (2–10), rank conversion and display |
| `faceCard` | Manages face cards (J, Q, K, A), rank conversion and display |
| `Card` | Inherits from both; unified card with rank, suit, reset, display |
| `Player` | Holds a player's hand of up to 52 cards |
| `Game` | Core game logic: shuffle, distribute, turns, bluff detection |
| `back` | Friend of Game; manages game state transitions |

---

## 🧠 OOP Concepts Applied

| Concept | Implementation |
|---------|---------------|
| **Multiple Inheritance** | `Card` inherits from both `numCard` and `faceCard` |
| **Polymorphism** | Overloaded and overridden `display()` and `ranktoint()` functions |
| **Friend Class** | `back` is a friend of `Game` for state access |
| **Has-A Relationship** | `Game` has `Player`s; `Player` has `Card`s |
| **File Handling** | Player info and results written to text file |

---

## 🚀 Getting Started

### Prerequisites

- C++ compiler (g++ recommended)

### Compile & Run

```bash
g++ -o bluff main.cpp
./bluff
```

---

## 📚 Concepts Covered

- Object-oriented programming in C++
- Multiple inheritance and diamond problem awareness
- Operator and function overloading
- Friend class access patterns
- Static arrays for hand and pile management
- File I/O in C++
