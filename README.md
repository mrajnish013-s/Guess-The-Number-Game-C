# 🎮 Guess The Number Game (Multiplayer)

A console-based multiplayer number guessing game developed in **C Programming**.

The game allows two players to compete by guessing randomly generated numbers. The player who guesses their secret number in fewer attempts wins the game.

This project was built to practice **C programming fundamentals**, **modular programming**, **Git**, and **GitHub workflow**.

---

## ✨ Features

- 🎮 Two-player gameplay
- 🎲 Random number generation
- 🎯 Three difficulty levels
  - Easy (1–50)
  - Medium (1–100)
  - Hard (1–500)
- 🛡️ Input validation
  - Handles non-numeric input
  - Prevents invalid range input
  - Prevents invalid menu choices
- 🔄 Replay option
- 📊 Guess counter
- 🏆 Automatic winner detection
- 🧩 Modular function-based design
- 💻 User-friendly console interface

---

## 🎯 Difficulty Levels

| Level | Number Range |
|--------|--------------|
| Easy | 1–50 |
| Medium | 1–100 |
| Hard | 1–500 |

---

## 🛡️ Input Validation

The game validates user input to improve reliability.

- Rejects non-numeric input (Example: `abc`)
- Rejects numbers outside the selected range
- Rejects invalid menu choices
- Prompts the user until valid input is entered

---

## 🛠️ Technologies Used

- C Programming
- Standard C Library
- GCC (MinGW)
- Windows Console API (UTF-8 Emoji Support)
- Git
- GitHub

---

## 📂 Project Structure

```text
Guess-The-Number-Game-C
│
├── main.c
├── README.md
├── .gitignore
├── LICENSE
└── screenshots/
```

---

## ▶️ How to Compile and Run

### Using GCC (MinGW)

```bash
gcc main.c -o main
main
```

---

## 🎮 How to Play

1. Select a difficulty level.
2. Player 1 guesses their secret number.
3. Pass the keyboard to Player 2.
4. Player 2 guesses their secret number.
5. The player with fewer guesses wins.
6. Choose whether to play another round.

---

## 📸 Screenshots

Screenshots will be added soon.

- Welcome Screen
- Difficulty Selection
- Gameplay
- Winner Screen

---

## 🚀 Future Improvements

- 🏅 Scoreboard
- 💾 High score saving using file handling
- 💡 Hint system
- ⏱️ Timer mode
- 🎨 Colored console output
- 📁 Multiple source files
- 📄 Header files
- 🌍 Cross-platform support
- 🤖 Single Player vs Computer mode
- 🧪 Unit Testing

---

## 📚 Concepts Practiced

- Functions
- Function Prototypes
- Pointers
- Call by Reference
- Loops
- Conditional Statements
- Switch Statement
- Random Number Generation
- Input Validation
- Modular Programming
- Git Branch Workflow
- Pull Requests
- GitHub Repository Management

---

## 👨‍💻 Author

**Rajneesh Maurya**

B.Tech CSE Student  
Ajay Kumar Garg Engineering College

GitHub: **mrajnish013-s**

---

## ⭐ Support

If you found this project helpful, consider giving it a **⭐ Star** on GitHub.