#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data* john = new Data(42, "john");

    std::cout << "--- ADRESSES MEMOIRE ---\n";
    std::cout << "Original Data pointer : " << john << "\n";

    uintptr_t raw = Serializer::serialize(john);
    std::cout << "Serialized (uintptr_t): " << raw << "\n";
    
    Data* result2 = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer  : " << result2 << "\n\n";

    std::cout << "--- VERIFICATION ---\n";
    if (john == result2)
        std::cout << "SUCCESS: Pointers are perfectly identical!\n\n";
    else
        std::cout << "ERROR: Pointers do not match!\n\n";

    std::cout << "--- DATA CONTENT ---\n";
    std::cout << "id: " << result2->getid() << "\n";
    std::cout << "name: " << result2->getname() << "\n";

    delete john;
    return 0;
}
