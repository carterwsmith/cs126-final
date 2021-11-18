#include <round.h>

namespace typer {

Round::Round() = default;

Round::Round(string& prompt) {
  prompt_ = prompt;
  player_progress_ = "";

  next_letter_position_ = 0;
  next_letter_ = prompt_.at(0);

  current_wpm_ = 0;
  hasStartedTyping_ = false;
  isDone_ = false;
}

// on first key press that is not enter
void Round::StartRound() {
  timer_.Start();
}

void Round::EndRound() {
  timer_.Stop();
  isDone_ = true;
}

void Round::UpdateRound(string &input) {
  if (!hasStartedTyping_) {
    hasStartedTyping_ = true;
  }

  if (input == next_letter_ && !isDone_) {
    next_letter_position_++;
    next_letter_ = prompt_[next_letter_position_];

    player_progress_ += input;
  }

  if (IsRoundOver() && !isDone_) {
    EndRound();
  }
}

void Round::UpdateWpm() {
  if (timer_.GetTime() == 0) {
    current_wpm_ = 0;
    return;
  }

  double wpm = ((double)next_letter_position_ / 5) / ((double)timer_.GetTime() / 600);
  current_wpm_ = round(wpm);
}

bool Round::IsRoundOver() {
  if (player_progress_ == prompt_) {
    return true;
  } else {
    return false;
  }
}

string& Round::GetPrompt() {
  return prompt_;
}

size_t Round::GetWpm() {
  return current_wpm_;
}

string& Round::GetProgress() {
  return player_progress_;
}

string& Round::GetNextLetter() {
  return next_letter_;
}

} // namespace typer