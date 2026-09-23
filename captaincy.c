// Represents one footballer being considered for captaincy, with the four factors used to score them
#include <cs50.h>
#include <stdio.h>



typedef struct
{
    string player_name;
    float fixture_difficulty;
    float recent_form;
    bool home_away;
    float history_vs_opponnent;
} footballer;

// Weights reflect my own captaincy priorities: fixture difficulty matters
// most because harder oppponnentrs require better performance followed by history vs opponent because dosent matter as much as current form is priority
// then form and home/away least because playing ground shouldnt influence as much.

const float fixture_difficulty_weight = 0.4;
const float recent_form_weight = 0.2;
const float history_vs_oponnent_weight = 0.3;
const float home_away_weight = 0.1;

// Takes one footballers stats, normalises each factor to a 0-1 scale,
// applies my weighting, and returns their overall captaincy
float score(footballer f)
{
    float fixture = (f.fixture_difficulty / 5) * fixture_difficulty_weight;
    float form = (f.recent_form /15) * recent_form_weight;
    float history = (f.history_vs_opponnent / 15) * history_vs_oponnent_weight;
    float home_away = (f.home_away) * home_away_weight;

    return fixture + form + history + home_away;

}






int main(void)
{
    footballer footballers[5];
    footballers[0].player_name = "Lionel Messi";
    footballers[0].fixture_difficulty = 5;
    footballers[0]. recent_form = 10.0;
    footballers[0].home_away = true;
    footballers[0].history_vs_opponnent = 9.5;

    footballers[1].player_name = "Cristiano Ronaldo";
    footballers[1].fixture_difficulty = 4;
    footballers[1]. recent_form = 5.5;
    footballers[1].home_away = false;
    footballers[1].history_vs_opponnent = 4.3;


    for(int i = 0; i <2; i++)
    {
        printf("Player: %s, Score: %f\n", footballers[i].player_name, score(footballers[i]));
    }



}
