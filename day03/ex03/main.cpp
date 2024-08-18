#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
		// FragTrap d("ydoC");
		// FragTrap a(d);
		DiamondTrap b("Cody");

		// a.highFivesGuys();
    // a.attack("\033[34m\"some robot\"\033[0m");
		// a.takeDamage(10);
		// a.takeDamage(10);
		// a.beRepaired(5);
		// a.attack("\033[34m\"some other robot\"\033[0m");
		// b.highFivesGuys();
		for (int i = 0; i < 5; i++)
			b.attack("\033[34m\"Cody-clone\"\033[0m");
		return (0);
}
