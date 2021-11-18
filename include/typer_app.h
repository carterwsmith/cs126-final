#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <game_engine.h>

namespace typer {

class TyperApp : public ci::app::App {
  public:
    TyperApp();

    void draw() override;
    void update() override;
    void keyDown(ci::app::KeyEvent event) override;

    const double kWindowSize = 875;
    const double kMargin = 100;

    const ci::Font kPromptFont = ci::Font("Helvetica", 25.0);
    const size_t kCharactersPerLine = 64;
    const size_t kLineSpacing = 30;

  private:
    void DisplayPromptString(string& input) const;

    GameEngine engine_;
};

} // namespace typer