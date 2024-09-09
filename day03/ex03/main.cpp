#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap Diamond;
    DiamondTrap named_Diamond("khalil");

	std::cout << "\n\n";

	std::cout << '\n';

	Diamond.whoAmI();
    named_Diamond.whoAmI();

	std::cout << '\n';

	Diamond.printStats();

	std::cout << '\n';

	Diamond.attack("Target");
	named_Diamond.attack("named_Target");

	std::cout << "\n";

	Diamond.printStats();
	named_Diamond.printStats();
	std::cout << "\n";



    return 0;
}
