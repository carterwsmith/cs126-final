#include <catch2/catch.hpp>

#include <round.h>

using typer::Round;
using std::string;

TEST_CASE("Round functionality") {
  string prompt = "The quick brown fox jumped over the lazy dog.";
  Round round = Round(prompt);

  SECTION("Initial variables correct") {
    REQUIRE(round.GetPrompt().length() == 45);
    REQUIRE(round.GetNextLetter() == "T");
    REQUIRE(round.GetWpm() == 0);
  }

  // cannot directly test WPM due to integration with user-facing app
  SECTION("Update round") {
    string t = "T";
    round.UpdateRound(t);

    REQUIRE(round.GetProgress() == "T");
    REQUIRE(round.GetNextLetter() == "h");
    REQUIRE(round.IsRoundOver() == false);
  }

  SECTION("Finish round") {
    string prompt2 = "a";
    Round round2 = Round(prompt2);

    string a = "a";
    round2.StartRound();
    round2.UpdateRound(a);

    REQUIRE(round2.GetProgress() == "a");
    REQUIRE(round2.IsRoundOver() == true);
  }
}
