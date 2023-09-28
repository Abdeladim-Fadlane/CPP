#include"ClapTrap.hpp"

ClapTrap::ClapTrap()
{ 
    std::cout<<"ClapTrap Default constructor called\n";
}
ClapTrap::ClapTrap(const std::string& target):name(target)
{   
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout<<"ClapTrap parametrize constructor called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout<<"ClapTrap copy constructor called\n";
    *this = obj;
}

ClapTrap& ClapTrap::operator =(const ClapTrap& obj)
{
    std::cout<<"ClapTrap Copy assignment operator called \n";
    this->HitPoints = obj.HitPoints;
    this->EnergyPoints = obj.EnergyPoints;
    this->AttackDamage = obj.AttackDamage;
    return(*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(HitPoints <= 0|| EnergyPoints <=0)
    {
        std::cout<<"ClapTrap "<<name<<" is already out of hit points can't attak !\n";
        return;
    } 
    std::cout<<"ClapTrap "<<name<<" attacks " << target<<" ,causing "<<AttackDamage<<" points of damage!\n";
    EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "ClapTrap "<<name<<" is already out of hit points and can't take more damage!" << std::endl;
        return;
    }  
    HitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " attack damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "ClapTrap "<<name<<" is already out of hit points and can't repair hit points !" << std::endl;
        return;
    }  
    HitPoints += amount;
    EnergyPoints--;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
}
   