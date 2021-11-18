#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <game_engine.h>

namespace typer {

class TyperApp : public ci::app::App {
  public:
    /**
     * Application constructor that reads prompts from prompts.txt in the root directory
     */
    TyperApp();

    /**
     * Displays the application state each frame.
     */
    void draw() override;
    /**
     * Handles logic for updating the application each frame.
     */
    void update() override;
    /**
     * Handles parsing and managing application state when a key is pressed.
     * @param event a key press
     */
    void keyDown(ci::app::KeyEvent event) override;

    /**
     * The square size of the window.
     */
    const double kWindowSize = 875;
    /**
     * The margin of the window.
     */
    const double kMargin = 100;

    /**
     * The font used to display the prompt.
     */
    ci::Font kPromptFont = ci::Font("Futura", 25.0);
    /**
     * The font used to display the progress.
     */
    ci::Font kProgressFont = ci::Font("Futura", 25.0);
    /**
     * The font used to display the WPM.
     */
    ci::Font kWpmFont = ci::Font("Sequel100Black-85", 25.0);
    /**
     * The maximum number of characters per centered line of the prompt.
     */
    const size_t kCharactersPerLine = 64;
    /**
     * The desired spacing between lines in pixels.
     */
    const size_t kLineSpacing = 30;

  private:
    /**
     * Displays a prompt given the prompt as a string.
     * @param input the prompt
     */
    void DisplayPromptString(string& input);
    /**
     * Displays the player's current WPM.
     * @param line_spacing the vertical line on which to display
     */
    void DisplayWpm(size_t line_spacing);
    /**
     * Displays the player's current typing progress in the form of their current correct word.
     * @param line_spacing the vertical line on which to display
     */
    void DisplayProgress(size_t line_spacing);
    /**
     * Displays a string centered in the application window.
     * @param input the string to display
     * @param line_spacing the vertical line on which to display
     * @param font_color the desired color of the font
     * @return the number of lines the string occupies on the application
     */
    size_t DisplayCenteredString(string& input, size_t line_spacing, ci::Color& font_color, ci::Font& font);

    /**
     * The application's game engine.
     */
    GameEngine engine_;

    /**
     * A texture for the game's start screen.
     */
    ci::gl::Texture2dRef start;

    /**
     * A texture for the game's background.
     */
    ci::gl::Texture2dRef empty;

    /**
     * A texture for a screen with a prompt displayed.
     */
    ci::gl::Texture2dRef prompt;
};

} // namespace typer