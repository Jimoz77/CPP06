#include "Base.hpp"
#include <cstdlib>

#include <ctime>     // Pour time()
#include <iostream>  // Pour afficher ce qu'on a généré (très utile pour débugger)


Base* generate(void)
{
    static bool is_seeded = false;
    if (!is_seeded)
    {
        std::srand(std::time(NULL));
        is_seeded = true;
    }

    int random_value = std::rand() % 3;

    switch (random_value)
    {
        case 0:
            std::cout << "Générateur : création de A\n";
            return (new A());
        case 1:
            std::cout << "Générateur : création de B\n";
            return (new B());
        case 2:
            std::cout << "Générateur : création de C\n";
            return (new C());
    }
    return (NULL);
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p) != NULL)
		std::cout << "A\n";
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << "B\n";
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "C\n";
	else
		std::cout << "Erorr\n";
}

void identify(Base& p)
{

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		//return;
	}
	catch (const std::exception &e)
	{
		try
			{
				(void)dynamic_cast<B&>(p);
				std::cout << "B\n";
				//return;
			}
			catch (const std::exception &e)
			{
				try
				{
					(void)dynamic_cast<C&>(p);
					std::cout << "C\n";
					//return;
				}
				catch (const std::exception &e)
				{
					std::cout << "Erorr\n";
				}
			}	
	}
}

Base::~Base()
{

}
