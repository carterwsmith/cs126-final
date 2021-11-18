#include <catch2/catch.hpp>

#include <stopwatch.h>
#include <chrono>
#include <thread>

using typer::Stopwatch;

TEST_CASE("Stopwatch functionality") {
  Stopwatch stopwatch = Stopwatch();

  SECTION("Time recording correctly") {
    std::chrono::milliseconds second(1000); // or whatever

    stopwatch.Start();
    std::this_thread::sleep_for(second);
    stopwatch.Stop();

    REQUIRE(stopwatch.GetTime() / 10 == Approx(1));
  }

}