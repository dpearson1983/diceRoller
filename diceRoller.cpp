/* diceRoller.cpp
 * David Pearson, 21-8-2020
 * 
 * This program can simulate dice rolls of an arbitrary number of die, of arbitrary numbers of sides.
 */

#include <iostream>
#include <random>
#include <vector>
#include <string>

class parameters{
    int N, sides;
    
public:
    parameters(int argc, char *argv[]);
    
    int getSides();
    
    int getN();
    
};

int main(int argc, char *argv[]) {
    parameters p(argc, argv);
    
    std::random_device seeder;
    std::mt19937_64 gen(seeder());
    std::uniform_int_distribution<int> dist(1,p.getSides());
    
    std::vector<int> rolls;
    
    for (int i = 0; i < p.getN(); ++i) {
        rolls.push_back(dist(gen));
        std::cout << rolls[i] << std::endl;
    }
    
    std::cout << "Simulating " << p.getN() << " rolls of " << p.getSides() << std::endl;
    
    double avg = 0.0;
    int sum = 0;
    for (size_t i = 0; i < rolls.size(); ++i) {
        sum += rolls[i];
        avg += rolls[i];
    }
    avg /= rolls.size();
    std::cout << "The sum of the rolls was: " << sum << std::endl;
    std::cout << "The average of the rolls was: " << avg << std::endl;
    
    return 0;
}

parameters::parameters(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string temp(argv[i]);
        if (temp == "-D6" or temp == "-d6") {
            parameters::sides = 6;
        } else if (temp == "-D20" or temp == "-d20") {
            parameters::sides = 20;
        } else if (temp == "-D12" or temp == "-d12") {
            parameters::sides = 12;
        } else if (temp == "-N" or temp == "-N") {
            parameters::N = std::stoi(argv[i + 1]);
        }
    }
}

int parameters::getSides() {
    return parameters::sides;
}

int parameters::getN() {
    return parameters::N;
}
