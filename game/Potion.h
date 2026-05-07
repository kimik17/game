#pragma once
#include<iostream>
#include<string>
#include <vector>
#include "Item.h"
#include "player.h"
using std::cout;
using std::endl;
using std::string;

struct PotionRecipe {
    string recipeName;
    string ingredient1;
    string ingredient2;
    Item resultPotion;
};

class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

public:
    AlchemyWorkshop();

    void ShowAllRecipes();
    void SearchByName(string name);
    void SearchByIngredient(string ingredient);


};