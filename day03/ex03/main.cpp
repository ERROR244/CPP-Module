#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap Diamond;
    DiamondTrap named_Diamond("khalil");

	std::cout << "\n\n";

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
