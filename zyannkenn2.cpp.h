#pragma once
#include <iostream>
#include <string>
#include <array>


using namespace std;


enum class Hand
{
    Rock = 0,      
    Scissors = 1,  
    Paper = 2      
};


enum class Result 
{
    Draw,   
    Win,   
    Lose    
};


struct JankenManager 
{
   
    static constexpr array<const char*, 3> HandNames = { "ぐー", "チョキ", "パー" };

    
    static Result judge(Hand player, Hand cpu);

   
    static string getHandName(Hand hand);
};
