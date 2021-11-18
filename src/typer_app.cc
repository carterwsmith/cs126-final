#include <typer_app.h>

using std::map;

namespace typer {

TyperApp::TyperApp() {
  // instantiate game engine from text file of prompts
  std::cout << boost::filesystem::current_path() << std::endl;
  std::ifstream in("../../../../../../prompts.txt");
  engine_ = GameEngine(in);

  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void TyperApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  if (engine_.isStarted_) {
    //current round state
    string prompt = engine_.GetRound().GetPrompt();
    DisplayPromptString(prompt);
  } else {
    //start screen
  }
}

void TyperApp::update() {
  if (engine_.isStarted_) {
    if (engine_.GetRound().hasStartedTyping_ && !engine_.GetRound().isDone_) {
      engine_.GetRound().UpdateWpm();
    }
  }
}

void TyperApp::keyDown(ci::app::KeyEvent event) {
  if (event.getCode() == ci::app::KeyEvent::KEY_RETURN) {
    if (!engine_.isStarted_) {
      engine_.isStarted_ = true;
    }

    engine_.NewRound();
  } else {
    if (engine_.isStarted_) {
      if (!engine_.GetRound().hasStartedTyping_) {
        engine_.GetRound().StartRound();
      }

      string input(1, event.getChar());
      engine_.GetRound().UpdateRound(input);
    }
  }
}

void TyperApp::DisplayPromptString(string &input) const {
  ci::Color font_color("white");

  // maps the index of each word's last character to each word of the prompt
  map<size_t, string> words;
  size_t index = 0;
  string word;
  for (auto letter : input) {
    if (letter == ' ' && index != 0) {
      words.insert(std::pair<size_t, string>(index + 1, word));
      word = "";
    } else {
      word += letter;
    }
    index++;
  }
  // last word
  words.insert(std::pair<size_t, string>(index + 1, word));

  string display_line;
  size_t chars_in_line = 0;
  size_t lines_displayed = 0;

  for (const auto& display_word : words) {
    if (chars_in_line < kCharactersPerLine) {
      display_line += display_word.second + " ";
      chars_in_line += display_word.second.length() + 1;
    } else {
      ci::gl::drawStringCentered(display_line,
                                 ci::vec2(kWindowSize / 2, (kWindowSize / 2) + (double)(kLineSpacing * lines_displayed)),
                                 font_color, kPromptFont);

      lines_displayed++;
      display_line = display_word.second + " ";
      chars_in_line = display_word.second.length() + 1;
      continue;
    }

    if (display_word.first > input.length()) {
      // last line
      ci::gl::drawStringCentered(display_line,
                                 ci::vec2(kWindowSize / 2, (kWindowSize / 2) + (double)(kLineSpacing * lines_displayed)),
                                 font_color, kPromptFont);
    }
  }
}

  //ci::gl::drawStringCentered(input, ci::vec2(kWindowSize / 2, kWindowSize / 2),
                             //font_color, kPromptFont);
}