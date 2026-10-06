#include "zyannkenn2.cpp.h"


Result JankenManager::judge(const Hand player, const Hand cpu) 
{
    const int p = static_cast<int>(player);
    const int c = static_cast<int>(cpu);
    const int diff = (p - c + 3) % 3;

    if (diff == 0) return Result::Draw;
    if (diff == 2) return Result::Win;   
    return Result::Lose;
}


string JankenManager::getHandName(const Hand hand)
{
    const size_t index = static_cast<size_t>(hand);
    if (index < HandNames.size()) {
        return HandNames[index];
    }
    return "Unknown";
}