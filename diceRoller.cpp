/* diceRoller.cpp
 * David Pearson, 21-8-2020
 * 
 * This program can simulate dice rolls of an arbitrary number of die, of arbitrary numbers of sides.
 */

#include <iostream>
#include <random>
#include <vector>

int main() {
    std::random_device seeder;
    std::mt19937_64 gen(seeder());
    std::uniform_int_distribution<int> dist(1,6);
    
    std::cout << dist(gen) << std::endl;
    
    return 0;
}
