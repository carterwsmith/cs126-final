#pragma once

#include <string>
#include <stopwatch.h>

using std::string;

namespace typer {

class Round {
  public:
    /**
     * Default constructor.
     */
    Round();
    /**
     * Constructs a round given a prompt.
     * @param prompt the prompt for the round
     */
    explicit Round(string& prompt);

    /**
     * Begins the round when typing is started.
     */
    void StartRound();
    /**
     * Ends the round when the prompt is finished.
     */
    void EndRound();

    /**
     * Updates the round progress (on key press) with a given string input.
     * @param input the character pressed
     */
    void UpdateRound(string& input);
    /**
     * Updates the player's WPM.
     */
    void UpdateWpm();

    /**
     * Checks if the round is over.
     * @return true if the user has completed the prompt
     */
    bool IsRoundOver();

    /**
     * Returns the prompt.
     */
    string& GetPrompt();
    /**
     * Returns the player's current WPM.
     */
    size_t GetWpm();
    /**
     * Returns the user's current progress.
     */
    string& GetProgress();
    /**
     * Returns the next letter.
     */
    string& GetNextLetter();

    /**
     * If the user has started typing.
     */
    bool hasStartedTyping_;
    /**
     * If the round is done.
     */
    bool isDone_;

  private:
    /**
     * The prompt of the round.
     */
    string prompt_;
    /**
     * The player's current (correct) progress.
     */
    string player_progress_;

    /**
     * The location of the player's next letter to type.
     */
    size_t next_letter_position_;
    /**
     * The player's next letter to type.
     */
    string next_letter_;

    /**
     * The player's current WPM.
     */
    size_t current_wpm_;
    /**
     * A timer recording the length of the round.
     */
    Stopwatch timer_;
};

} // namespace typer