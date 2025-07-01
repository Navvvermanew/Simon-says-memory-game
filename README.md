# Simon-says-memory-game
Simon Says: A reflex and memory-based game built with Arduino UNO, LEDs, and buttons — inspired by the classic *Simon Says* game. This project lights up a sequence of LEDs that the player must memorize and reproduce using  corresponding push buttons. With every successful round, the sequence grows longer.
## How the Game works :
1. **Sequence Generation**: Arduino creates a random LED blinks and the sequence start.
2. **Playback**: The LEDs blink in the current level's sequence.
3. **User Input**: Player must press the corresponding buttons in the correct order.
4. **Level up or Game Over** :
        If user input is correct: Level increases and a longer sequence plays.
        If user input is wrong: All LEDs blink to indicate **Game Over**, and the game resets.
