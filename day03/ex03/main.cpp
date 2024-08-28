#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap Diamond;
    DiamondTrap named_Diamond("khalil");

	std::cout << "\n\n";

	std::cout << "DiamondTrap name: " << Diamond.getDName() << '\n';
	std::cout << "named_DiamondTrap name: " << named_Diamond.getDName() << '\n';

	std::cout << '\n';

	std::cout << "Diamondclaptrap name: " << Diamond.getName() << '\n';
	std::cout << "named_Diamondclaptrap name: " << named_Diamond.getName() << '\n';

	std::cout << '\n';

	std::cout << "Diamondclaptrap Hit points: " << Diamond.getNum(1) << '\n';
	std::cout << "named_Diamondclaptrap Hit points: " << named_Diamond.getNum(1) << '\n';

	std::cout << '\n';

	std::cout << "Diamondclaptrap Energy points: " << Diamond.getNum(2) << '\n';
	std::cout << "named_Diamondclaptrap Energy points: " << named_Diamond.getNum(2) << '\n';

	std::cout << '\n';

	std::cout << "Diamondclaptrap damage points: " << Diamond.getNum(3) << '\n';
	std::cout << "named_Diamondclaptrap damage points: " << named_Diamond.getNum(3) << '\n';

	std::cout << '\n';

	Diamond.attack("Target");
	named_Diamond.attack("named_Target");

	std::cout << '\n';

	Diamond.whoAmI();
    named_Diamond.whoAmI();

	std::cout << '\n';

	Diamond.takeDamage(30);
	named_Diamond.takeDamage(30);

	std::cout << '\n';

	Diamond.beRepaired(20);
	named_Diamond.beRepaired(20);

	std::cout << '\n';

	Diamond.highFivesGuys();
	named_Diamond.highFivesGuys();

	std::cout << '\n';

	Diamond.guardGate();
	named_Diamond.guardGate();

	std::cout << "\n\n";



    return 0;
}
