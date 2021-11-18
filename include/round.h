#pragma once

#include <string>
#include <stopwatch.h>

using std::string;

namespace typer {

class Round {
  public:
    Round();
    explicit Round(string& prompt);

    void StartRound();
    void EndRound();

    // on key press
    void UpdateRound(string& input);
    // on update call
    void UpdateWpm();

    bool IsRoundOver();

    string& GetPrompt();

    bool hasStartedTyping_;
    bool isDone_;

  private:
    string prompt_;
    string player_progress_;

    size_t next_letter_position_;
    string next_letter_;

    size_t current_wpm_;
    Stopwatch timer_;
};

} // namespace typer