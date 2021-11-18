#include <stopwatch.h>
#include <unistd.h>

using std::thread;

namespace typer {

Stopwatch::Stopwatch() {
  tenth_seconds_ = 0;
  isRunning_ = false;
}

void Stopwatch::Start() {
  isRunning_ = true;
  th = thread([=]()
    {
      while (isRunning_) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        tenth_seconds_++;
      }
    });
}

void Stopwatch::Stop() {
  isRunning_ = false;
  th.join();
}

size_t Stopwatch::GetTime() const {
  return tenth_seconds_;
}

} // namespace typer