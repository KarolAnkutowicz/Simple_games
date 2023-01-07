/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: main.cpp
 */

#include <iostream>
#include <tuple>

const unsigned int constFizz = 3;
const unsigned int constBuzz = 5;
const unsigned int constMax = 30;

void mPrintDefault() { std::cout << "\nDo you agree default settings: Fizz - " << constFizz << "n, Buzz - "
        << constBuzz << "n, max - " << constMax << " ? (y / n)\n"; }

void mPrintFizz() { std::cout << "Set \"Fizz\" number:\n"; }

void mPrintBuzz() { std::cout << "Set \"Buzz\" number:\n"; }

void mPrintMax() { std::cout << "Set max number:\n"; }

void mPrintContinue() { std::cout << "\nDo you want to continue? (y/n)\n"; }

bool fGetDecision(char aDecision)
{
    bool vDecision = false;
    switch (aDecision)
    {
        case 'n': vDecision = false; break;
        case 'y':
        default: vDecision = true; break;
    }
    return vDecision;
}

std::tuple <unsigned int, unsigned int, unsigned int> fSetArguments()
{
    unsigned int vFizz, vBuzz, vMax;
    mPrintFizz();
    std::cin >> vFizz;
    mPrintBuzz();
    std::cin >> vBuzz;
    mPrintMax();
    std::cin >> vMax;
    std::cout << "\n";
    return std::make_tuple(vFizz, vBuzz, vMax);
}

void fMakeFizzBuzz(unsigned int aFizz, unsigned int aBuzz, unsigned int aMax)
{
    bool vDivide = false;
    unsigned int vStart = 0;
    do
    {
        vStart++;
        vDivide = false;
        if ((vStart % aFizz) == 0)
        {
            std::cout << "Fizz";
            vDivide = true;
        }
        if ((vStart % aBuzz) == 0)
        {
            std::cout << "Buzz";
            vDivide = true;
        }
        if (vDivide == false)
            std::cout << vStart;
        std::cout << std::endl;
    } while (vStart < aMax);
    std::cout << "\n";
}


int main()
{
    bool vContinue = true;
    char vOption;
    unsigned int vFizz = constFizz, vBuzz = constBuzz, vMax = constMax;

    do
    {
        mPrintDefault();
        std::cin >> vOption;
        std::cout << std::endl;
        vContinue = fGetDecision(vOption);
        if (vContinue == false)
        {
            auto vArguments = fSetArguments();
            fMakeFizzBuzz(std::get<0>(vArguments), std::get<1>(vArguments), std::get<2>(vArguments));
        }
        else
            fMakeFizzBuzz(constFizz, constBuzz, constMax);
        mPrintContinue();
        std::cin >> vOption;
        vContinue = fGetDecision(vOption);
    } while (vContinue == true);

    return 0;
}

/* main.cpp */
/********** END_OF_FILE **********/