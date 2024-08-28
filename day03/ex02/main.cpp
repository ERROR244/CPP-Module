#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
		FragTrap d("ydoC");
		FragTrap a(d);
		FragTrap b("Cody");

		a.highFivesGuys();
    a.attack("\033[34m\"some robot\"\033[0m");
		a.takeDamage(4);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(10);
		a.takeDamage(5);
		a.beRepaired(5);
		a.attack("\033[34m\"some other robot\"\033[0m");
		a.takeDamage(6);
		a.takeDamage(1);
		b.highFivesGuys();
		for (int i = 0; i < 5; i++)
			b.attack("\033[34m\"Cody-clone\"\033[0m");
		return (0);
}
