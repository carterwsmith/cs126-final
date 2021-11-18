#include <typer_app.h>

using std::map;

namespace typer {

TyperApp::TyperApp() {
  // instantiate game engine from text file of prompts
  std::ifstream in("../../../../../../prompts.txt");
  engine_ = GameEngine(in);

  auto start_img = loadImage( loadAsset( "start.png" ) );
  start = ci::gl::Texture2d::create( start_img );

  auto empty_img = loadImage( loadAsset( "empty.png" ) );
  empty = ci::gl::Texture2d::create( empty_img );

  auto prompt_img = loadImage( loadAsset( "prompt.png" ) );
  prompt = ci::gl::Texture2d::create( prompt_img );

  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void TyperApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  if (engine_.isStarted_) {
    //current round state
    ci::gl::clear();
    ci::gl::draw(prompt);

    string prompt_text = engine_.GetRound().GetPrompt();
    DisplayPromptString(prompt_text);
  } else {
    //start screen
    ci::gl::clear();
    ci::gl::draw(start);
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

      string input;

      switch (event.getCode()) {
        default:
          input = event.getChar();
          break;
      }

      //std::cout << event.getCode() << std::endl;
      engine_.GetRound().UpdateRound(input);
    }
  }
}

void TyperApp::DisplayPromptString(string &input) {
  ci::Color prompt_color = ci::Color("white");
  //ci::Color progress_color = ci::Color("lawngreen");
  //ci::Color error_color = ci::Color("firebrick");

  DisplayCenteredString(input, 0, prompt_color, kPromptFont);

  if (engine_.GetRound().hasStartedTyping_) {
    size_t progress_line = 11;
    DisplayProgress(progress_line);
    DisplayWpm(progress_line + 3);
  }
}

size_t TyperApp::DisplayCenteredString(string& input, size_t line_spacing, ci::Color& font_color, ci::Font& font) {
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
                                 ci::vec2(kWindowSize / 2, (kWindowSize / 4) +
                                                           (double)(kLineSpacing * (lines_displayed + line_spacing))),
                                 font_color, font);

      lines_displayed++;
      display_line = display_word.second + " ";
      chars_in_line = display_word.second.length() + 1;
      continue;
    }

    if (display_word.first > input.length()) {
      // last line
      ci::gl::drawStringCentered(display_line,
                                 ci::vec2(kWindowSize / 2, (kWindowSize / 4) +
                                                           (double)(kLineSpacing * (lines_displayed + line_spacing))),
                                 font_color, font);
    }
  }

  return lines_displayed;
}

void TyperApp::DisplayWpm(size_t line_spacing) {
  ci::Color wpm_color("white");
  string wpm;

  if (!engine_.GetRound().isDone_) {
    wpm = "Your current WPM: " + std::to_string(engine_.GetRound().GetWpm());
  } else {
    wpm = "Your final WPM: " + std::to_string(engine_.GetRound().GetWpm());
  }

  DisplayCenteredString(wpm, line_spacing, wpm_color, kWpmFont);
}

void TyperApp::DisplayProgress(size_t line_spacing) {
  ci::Color progress_color("white");
  string progress = engine_.GetRound().GetProgress();
  string display;

  if (progress.find(' ') != std::string::npos) {
    size_t last_index = progress.find_last_of(' ');
    display = "Your current word:" + progress.substr(last_index);
    DisplayCenteredString(display, line_spacing, progress_color, kProgressFont);
  } else {
    display = "Your current word: " + progress;
    DisplayCenteredString(display, line_spacing, progress_color, kProgressFont);
  }
}

  //ci::gl::drawStringCentered(input, ci::vec2(kWindowSize / 2, kWindowSize / 2),
                             //font_color, kPromptFont);
}