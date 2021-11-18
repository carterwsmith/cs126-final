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
    /**
     * Default constructor.
     */
    GameEngine();
    /**
     * Constructs a game engine from a file stream of prompts.
     * @param in a file stream of prompts
     */
    explicit GameEngine(std::ifstream& in);

    /**
     * Creates a new round from a random prompt.
     */
    void NewRound();
    /**
     * Returns the game's current round.
     */
    Round& GetRound();

    /**
     * If the user has bypassed the start screen (on enter key press).
     */
    bool isStarted_;
  private:
    /**
     * The number of available prompts in the game.
     */
    size_t num_prompts_;
    /**
     * All of the prompts in the game.
     */
    vector<string> prompts_;

    /**
     * The game's current round.
     */
    Round current_round_;
};

} // namespace typer