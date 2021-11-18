#include <typer_app.h>

using typer::TyperApp;

void prepareSettings(TyperApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(TyperApp, ci::app::RendererGl, prepareSettings);