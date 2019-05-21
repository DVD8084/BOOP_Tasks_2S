#include "test.h"

using std::vector;
using std::cout;

/**
 *  @brief  Function used to test the Dice class.
 *  Conducts two tests: one with a set of two regular D6, and another
 *  with a set of three unfair coins (p(0) = 1/3, p(1) = 2/3).
 */
void dice_test()
{
    vector <Dice> dice_set;
    for (int i = 0; i < 2; i++)
    {
        dice_set.emplace_back(6);
    }
    vector <double> probabilities;
    for (int i = 0; i < 2; i++)
    {
        probabilities.push_back(i + 1);
    }
    vector <Dice> coin_set;
    for (int i = 0; i < 3; i++)
    {
        coin_set.emplace_back(2, probabilities);
    }
    cout << "[SET 1: 2 REGULAR DICE]\n";
    print_probabilities(dice_set);
    cout << "\n[SET 2: 3 UNFAIR COINS]\n[p(0) = 1/3, p(1) = 2/3]\n";
    print_probabilities(coin_set);
    
}