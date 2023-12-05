#include<iostream>
#include<ctime>
#include<cstdio>
#include<thread>
Usingnamespace std;
Usingnamespace std::this_thread;
Usingnamespace std::chrono_literals;
Usingnamespace std::chrono:system_clock;

int numberOfPlayers = 0;
int numberOfQuestions = 0;

string questions[30];
string answers[30][4];

short int correctAnswers[30];
short int gameMode = 0;

char playAgain;

for (int j = 0; j < numberOfQuestions; j++) {
    // Start the program routine where all players receive the same questions
    // Seed needed for generating a random number
    srand(time(NULL));
    // Your code logic for handling the same questions for all players goes here
}

// Generate a random number between 1 and 30
int randomNum = rand() % 30 + 1;

// Clear the console screen
system("CLS");

// Display the question corresponding to the randomly generated number
cout << questions[randomNum] << endl;

// Display the answer choices for the question
for (int tr = 0; tr < 4; tr++) {
    cout << answers[randomNum][tr] << endl;
}

for (int k = 0; k < numberOfPlayers; k++) {
    cout << "Answer by " << playerName[k] << " ";
    start = clock();
    cin >> playerAnswers[k][randomNum];
    duration = (clock() - start) / (double)CLOCKS_PER_SEC;

    if (duration > 15) {
        cout << "Time limit for the question is 15 seconds!" << endl;
        sleep_for(1s);
    } else if (playerAnswers[k][randomNum] == correctAnswers[randomNum]) {
        playerScores[k] += 1;
    } else {
        playerScores[k] = 0 + playerScores[k];
    }

    // Clear the console screen
    system("CLS");

    // Display the question again
    cout << questions[randomNum] << endl;

    // Display the answer choices again
    for (int tr = 0; tr < 4; tr++) {
        cout << answers[randomNum][tr] << endl;
    }
}

for (int r = 0; r < numberOfPlayers; r++) {
    // Display and calculate the current score as a percentage
    cout << "Score for " << playerName[r] << " is " << playerScores[r]
         << " " << float((playerScores[r] / numberOfQuestions) * 100) << " % " << endl;
}

cout << "Play again? Type YES or NO (Y/N): ";
cin >> playAgain;

if (playAgain == 'Y' || playAgain == 'y') {
    // Clear the console screen
    system("CLS");
    // Restart the game by calling the main function
    return main();
}
