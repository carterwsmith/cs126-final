#include <game_engine.h>
#include <ctime>

using std::string;

namespace typer {

GameEngine::GameEngine() = default;

GameEngine::GameEngine(std::ifstream& in) {
  num_prompts_ = 0;
  string line;

  string current_prompt;
  while (std::getline(in, line)) {
    if (line == "-") {
      prompts_.push_back(current_prompt);
      num_prompts_++;

      current_prompt.clear();
    } else {
      current_prompt += line;
    }
  }

  if (num_prompts_ == 0) {
    throw std::invalid_argument("No prompts provided");
  }

  isStarted_ = false;
}

void GameEngine::NewRound() {
  if (current_round_.hasStartedTyping_ && !current_round_.isDone_) {
    return;
  }

  srand(time(nullptr));
  size_t new_prompt_position = rand() % num_prompts_;

  current_round_ = Round(prompts_[new_prompt_position]);
}

Round& GameEngine::GetRound() {
  return current_round_;
}

} // namespace typer