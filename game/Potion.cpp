#include "Potion.h"
#include <iostream>

AlchemyWorkshop::AlchemyWorkshop() {
    Item hpPotion = { "체력 포션", 50 };
    Item mpPotion = { "마나 포션", 50 };

    recipes.push_back({ "체력 포션", "슬라임의 점액", "약초", hpPotion });
    recipes.push_back({ "마나 포션", "슬라임의 핵", "약초", mpPotion });
}

void AlchemyWorkshop::ShowAllRecipes() {
    std::cout << "\n--- [ 연금술 레시피 도서관 ] ---" << std::endl;
    for (int i = 0; i < recipes.size(); i++) {
        std::cout << i + 1 << ". " << recipes[i].recipeName << " (" << recipes[i].ingredient1 << "X1 , " << recipes[i].ingredient2 << "X1 )" << std::endl;
    }
    cout << endl;
}

void AlchemyWorkshop::SearchByName(std::string name) {
    bool isFound = false; 

    for (int i = 0; i < recipes.size(); i++) {
        if (recipes[i].recipeName == name) { 
            std::cout << "\n-> " << recipes[i].recipeName << " (" << recipes[i].ingredient1 << "X1 , " << recipes[i].ingredient2 << "X1 )" << std::endl;
            isFound = true;
            break; 
        }
    }
   
    if (!isFound) {
        std::cout << "\n-> [실패] '" << name << "' 레시피를 찾을 수 없습니다." << std::endl;
    }
    cout << endl;
}

void AlchemyWorkshop::SearchByIngredient(std::string ingredient) {
    bool isFound = false;
    std::cout << "\n['" << ingredient << "'] 재료가 포함된 레시피 목록:" << std::endl;

    for (int i = 0; i < recipes.size(); i++) {
        if (recipes[i].ingredient1 == ingredient || recipes[i].ingredient2 == ingredient) {
            std::cout << "\n-> " << recipes[i].recipeName << " (" << recipes[i].ingredient1 << "X1 , " << recipes[i].ingredient2 << "X1 )" << std::endl;
            isFound = true;
        }
    }
    
    if (!isFound) {
        std::cout << "-> 해당 재료가 필요한 레시피가 없습니다." << std::endl;
    }
    cout << endl;
}