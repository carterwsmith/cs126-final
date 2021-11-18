#pragma once

#include <thread>

using std::thread;

namespace typer {

class Stopwatch {
  public:
    /**
     * Constructs a new, stopped stopwatch.
     */
    Stopwatch();

    /**
     * Starts the counting of the stopwatch.
     */
    void Start();
    /**
     * Stops the counting of the stopwatch.
     */
    void Stop();

    /**
     * Returns the stopwatch's current time in seconds.
     */
    size_t GetTime() const;
  private:
    /**
     * A thread to concurrently keep time.
     */
    thread th;

    /**
     * If the stopwatch is currently counting.
     */
    bool isRunning_;

    /**
     * The stopwatch's recorded time in tenth seconds.
     */
    size_t tenth_seconds_;
};

}