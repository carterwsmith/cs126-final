#pragma once

#include <thread>

using std::thread;

namespace typer {

class Stopwatch {
  public:
    Stopwatch();
    void Start();
    void Stop();
    size_t GetTime() const;
  private:
    thread th;
    bool isRunning_;
    size_t seconds_;
};

}