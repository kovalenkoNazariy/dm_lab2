#include <iostream>
#include "boolMatrix.h"

int main()
{
    int length{};
    std::cout << "Enter the length of the bool matrix: ";
    std::cin >> length;

    BoolMatrix boolMatrix(length);

    std::cin >> boolMatrix;
    std::cout << '\n' << std::boolalpha;
    bool transitive = boolMatrix.isTransitive();
    bool reflective = boolMatrix.isReflective();
    bool symmetrical = boolMatrix.isSymmetrical();

    std::cout << "Equivalent: " << (transitive && reflective && symmetrical) << '\n';
    std::cout << "Partial: " << (reflective && boolMatrix.isAntiSymmetrical() && transitive) << '\n';
    std::cout << "Strict: " << (boolMatrix.isAsymmetrical() && boolMatrix.isAntiReflective() && boolMatrix.isTransitive()) << '\n';

    std::cout << "\n";

    if (!transitive) {
        std::cout << "Transitive closure: \n" << (boolMatrix.getTransitiveClosure()) << '\n';
    }

    if (!reflective) {
        std::cout << "Reflective closure: \n" << (boolMatrix.getReflectiveClosure()) << '\n';
    }

    if (!symmetrical) {
        std::cout << "Symmetrical closure: \n" << (boolMatrix.getSymmetricalClosure()) << '\n';
    }

    BoolMatrix m2 = boolMatrix.powerUp();

    std::cout << "power 2: \n" << m2 << '\n';
    std::cout << "power 3: \n" << m2.powerUp();
}