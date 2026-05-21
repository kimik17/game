#include "Potion.h"
#include <iostream>

AlchemyWorkshop::AlchemyWorkshop() {
    Item hpPotion = { "HP 포션", 50 };
    Item mpPotion = { "MP 포션", 50 };

    recipes.push_back({ "HP 포션", "슬라임의 점액", "약초", hpPotion });
    recipes.push_back({ "MP 포션", "슬라임의 핵", "약초", mpPotion });

    potionStock_["HP 포션"] = 3;
    potionStock_["MP 포션"] = 3;
    potionStock_["공병"] = 0;

}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
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

bool AlchemyWorkshop::DispensePotion(string name) {
    if (potionStock_.find(name) == potionStock_.end()) {
        std::cout << "제작소에 등록되지 않은 포션입니다." << std::endl;
        return false;
    }

    if (potionStock_[name] <= 0) {
        std::cout << "[제조 실패] " << name << "의 재고가 부족합니다! (현재 재고: 0)" << std::endl;
        return false;
    }

    potionStock_[name]--;
    std::cout << "-> " << name << " (재고: " << potionStock_[name] << ")" << std::endl;
    return true;
}

void AlchemyWorkshop::ReturnPotion(string name) {
    if (potionStock_.find(name) == potionStock_.end()) {
        std::cout << "제작소에 없는 포션입니다." << std::endl;
        return;
    }

    if (potionStock_[name] >= MAX_STOCK) {
        std::cout << "[반납 불가] 이미 " << name << "의 재고가 가득 찼습니다!(최대 3개)" << std::endl;
        return;
    }

    potionStock_[name]++;
    std::cout << "->" << name << " 반환 (현재 재고: " << potionStock_[name] << "개)" << std::endl;
}

int AlchemyWorkshop::GetStock(string name) {
    if (potionStock_.find(name) == potionStock_.end()) {
        return 0;
    }
    return potionStock_[name];
}