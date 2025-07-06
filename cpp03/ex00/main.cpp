#include "ClapTrap.hpp"

int	main(void)
{
    // Test constructor
    ClapTrap clap1("Bumblebee");
    ClapTrap clap2("Optimus");
    
    std::cout << "\n=== Attack Tests ===" << std::endl;
    clap1.attack("Starscream");
    clap2.attack("Megatron");
    
    std::cout << "\n=== Take Damage Tests ===" << std::endl;
    clap1.takeDamage(5);
    clap2.takeDamage(3);
    
    std::cout << "\n=== Repair Tests ===" << std::endl;
    clap1.beRepaired(2);
    clap2.beRepaired(1);
    
    std::cout << "\n=== Energy Depletion Test ===" << std::endl;
    // Use up remaining energy (started with 10, used 2 so far)
    for (int i = 0; i < 8; i++)
        clap1.attack("Target");
    
		// Should show no energy message
    clap1.attack("Target");
    clap1.beRepaired(1);
    
    std::cout << "\n=== Death Test ===" << std::endl;
    clap2.takeDamage(20); // Should kill it
    clap2.attack("Target"); // Should show dead message
    clap2.takeDamage(5); // Should show already dead message
    
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    ClapTrap clap3(clap1);
    clap3.attack("CopyTarget");
    
    return (0);
}
