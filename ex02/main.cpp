#include <iostream>
#include "Base.hpp" // Assure-toi que ce nom correspond bien à ton fichier header

int main()
{
    std::cout << "=== DEBUT DES TESTS (Casting Magique) ===\n\n";

    // On fait 5 tests à la suite pour bien voir l'aléatoire
    for (int i = 0; i < 5; i++)
    {
        std::cout << "--- Test numéro " << i + 1 << " ---\n";

        // 1. On génère l'objet masqué
        Base* randomObj = generate();

        // 2. On le démasque avec la fonction pointeur
        std::cout << "Identification via pointeur   : ";
        identify(randomObj);

        // 3. On le démasque avec la fonction référence
        // L'astuce : on déréférence le pointeur avec l'étoile (*) pour passer l'objet lui-même (une référence)
        std::cout << "Identification via référence  : ";
        identify(*randomObj);

        // 4. LA RÈGLE D'OR : On nettoie la mémoire !
        delete randomObj;

        std::cout << "\n";
    }

    // Petit test bonus pour prouver que ta fonction pointeur gère bien les crashs
    std::cout << "--- Test bonus avec un pointeur NULL ---\n";
    std::cout << "Identification via pointeur   : ";
    identify(NULL);

    std::cout << "\n=== FIN DES TESTS ===\n";

    return 0;
}
