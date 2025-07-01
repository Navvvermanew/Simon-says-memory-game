# Simon-says-memory-game
Simon Says: A reflex and memory-based game built with Arduino UNO, LEDs, and buttons — inspired by the classic *Simon Says* game. This project lights up a sequence of LEDs that the player must memorize and reproduce using  corresponding push buttons. With every successful round, the sequence grows longer.
## How the Game works :
1. **Sequence Generation**: Arduino creates a random LED blinks and the sequence start.
2. **Playback**: The LEDs blink in the current level's sequence.
3. **User Input**: Player must press the corresponding buttons in the correct order.
4. **Level up or Game Over** :<br>   
        If user input is correct: Level increases and a longer sequence plays.
   <br>
        If user input is wrong: All LEDs blink to indicate **Game Over**, and the game resets.
## Hardware Components:
        Arduino UNO - 1
        Breadboard - 1
        LEDs- 5
        Push Buttons - 5
        220 ohm resistors(LEDs) - 5
        10kohm resistors(Buttons) - 5
        Jumper wires
## Circuit Connections:
        | LED   | Arduino Pin | Button | Arduino Pin  |
        | LED 1 | 8           | Btn1   | 2            |
        | LED 2 | 9           | Btn2   | 3            |
        | LED 3 | 10          | Btn3   | 4            |
        | LED 4 | 11          | Btn4   | 5            |
        | LED 5 | 12          | Btn5   | 6            |

    - LEDs: Anode (+) → Arduino Pin (via 220Ω), Cathode (−) → GND  
    - Buttons: One side → Arduino Pin (with 10kΩ pull-down to GND), other side → +5V
## Code Overview :
        - `generateSequence()`: Creates a random 100-step sequence.
        - `playSequence()`: Blinks LEDs up to current level.
        - `checkUserInput()`: Waits for button inputs, checks correctness.
        - `gameOver()`: Blinks all LEDs 3 times when wrong button is pressed.
## Features :
        Randomized sequence generation.
        Real-time user input validation.
        Visual feedback through LEDs.
        Level-based difficulty scaling.
        Clean and modular code.
## Future Improvements :
        Can add a buzzer for sound feedbacks.
        Integrate an LCD to display score and messages. 
        Add Difficulty settings (Easy/Medioum/Hard)
## Learning Outcomes :
        Embedded systems design with Arduino.
        Event-driven programming and debouncing.
        Circuit design for LEDs and push buttons.
        Random number generation and game logic.
