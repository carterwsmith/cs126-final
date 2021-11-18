#include <stopwatch.h>
#include <unistd.h>

using std::thread;

namespace typer {

Stopwatch::Stopwatch() {
  seconds_ = 0;
  isRunning_ = false;
}

void Stopwatch::Start() {
  isRunning_ = true;
  th = thread([=]()
    {
      while (isRunning_) {
        sleep(1);
        seconds_++;
      }
    });
}

void Stopwatch::Stop() {
  isRunning_ = false;
  th.join();
}

size_t Stopwatch::GetTime() const {
  return seconds_;
}

} // namespace typer