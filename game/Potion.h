#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
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

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

    std::map<string, int> potionStock_;
    const int MAX_STOCK = 3;

public:
    AlchemyWorkshop();

    void ShowAllRecipes();
    void SearchByName(string name);
    void SearchByIngredient(string ingredient);

    bool DispensePotion(string name);

    void ReturnPotion(string name);

    int GetStock(string name);
};