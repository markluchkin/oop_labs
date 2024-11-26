#include "../include/GameField.hpp"
#include "../include/ShipManager.hpp"
#include "../include/AbilityManager.hpp"

int main() {
    std::cout << "BattleShip\n";
    std::vector<int> shipSizes = {4, 3, 2, 1,};
    ShipManager manager(shipSizes);
    GameField field;
    auto s = manager.getAllShips();

    AbilityManager abilityManager(true);

    try{
        field.placeShip(3, 3, s[0]);
        field.placeShip(5, 8, s[1], Orientation::Horizontal);
        field.placeShip(0, 0, s[3]);
        field.placeShip(7, 4, s[3]);

    } catch (PlaceShipError &error){
        std::cout << error.what() << std::endl;
    }
    field.printField();

//    try {
//        field.attackCell(3, 3);
//        field.attackCell(3, 3);
//        field.attackCell(3, 4);
//        field.attackCell(10, 9);
//    } catch (AttackError &error){
//        std::cout << error.what() << std::endl;
//    }
    //manager.getShip(0)->printInfo();


    abilityManager.useAbility(field); //DD

    try {
        field.attackCell(3,5);
    } catch (AttackError &error){
        std::cout << error.what() << std::endl;
    }
    manager.getShip(0)->printInfo();

    abilityManager.useAbility(field, 1, 2); //Scanner


    try{
        abilityManager.useAbility(field); //Bombardment
    } catch(EmptyFieldError &error){
        std::cout << error.what() << std::endl;
    }

    manager.printShipsInfo();

    try{
        abilityManager.useAbility(field); //NoAbility
    } catch(NoAbilityError &error){
        std::cout << error.what() << std::endl;
    }

    return 0;
}


