#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "round.h"

using std::vector;
using std::string;

namespace typer {

class GameEngine {
  public:
    GameEngine();
    explicit GameEngine(std::ifstream& in);
    void NewRound();
    Round& GetRound();

    // if the first round has started yet (on first enter key press)
    bool isStarted_;
  private:
    size_t num_prompts_;
    vector<string> prompts_;

    Round current_round_;
};

} // namespace typer