#include <iostream>
#include "boolMatrix.h"

size_t BoolMatrix::size() const {
    return matrix.size();
}

std::uint32_t &BoolMatrix::operator[](int index) {
    return matrix[index];
}

const std::uint32_t &BoolMatrix::operator[](int index) const {
    return matrix[index];
}

bool BoolMatrix::at(int i, int j) const {
    return matrix[i] & (1 << j);
}

bool BoolMatrix::isReflective() {
	for (int i{ 0 }; i < matrix.size(); ++i) {
		if (!(matrix[i] & (1 << i)))
			return false;
	}
	
	return true;
}

bool BoolMatrix::isAntiReflective() {
	for (int i{ 0 }; i < matrix.size(); ++i) {
		if (matrix[i] & (1 << i))
			return false;
	}

	return true;
}

bool BoolMatrix::isSymmetrical() {
    for (int i{ 0 }; i < matrix.size(); ++i) {
        for (int j{ 0 }; j < matrix.size(); ++j) {
            if(at(i, j) != at(j, i))
                return false;
        }
    }

    return true;
}

bool BoolMatrix::isAntiSymmetrical() {
    for (int i{ 0 }; i < matrix.size(); ++i) {
        for (int j{ 0 }; j < matrix.size(); ++j) {
            if (at(i, j) == at(j, i))
                return false;
        }
    }

    return true;
}

bool BoolMatrix::isAsymmetrical() {
    return !isSymmetrical() && isAntiReflective();
}

bool BoolMatrix::isTransitive() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {

            if (at(i, j) == 1) {
                for (int z = 0; z < matrix.size(); z++) {
                    if (at(j, z) == 1 && at(i, z) == 0) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

BoolMatrix BoolMatrix::getTransitiveClosure() {
    BoolMatrix m(*this);

    for (int i{ 0 }; i < m.size(); ++i) {
        for (int j{ 0 }; j < m.size(); ++j) {

            if (at(i, j) == 1) {
                for (int z = 0; z < matrix.size(); z++) {
                    m[j] |= 1 << z;
                    m[i] &= ~(1 << z);
                }
            }
        }
    }

    return m;
}

BoolMatrix BoolMatrix::getReflectiveClosure() {
    BoolMatrix m(*this);

    for (int i{ 0 }; i < m.size(); ++i) {
        m[i] |= 1 << i;
    }

    return m;
}

BoolMatrix BoolMatrix::getSymmetricalClosure() {
    BoolMatrix m(*this);

    for (int i{ 0 }; i < m.size(); ++i) {
        for (int j{ 0 }; j < m.size(); ++j) {
            if (at(i, j) || at(j, i)) {
                m[i] |= 1 << j;
                m[j] |= 1 << i;
            }
        }
    }

    return m;
}

BoolMatrix BoolMatrix::powerUp() {
    BoolMatrix m(matrix.size());

    for (int i{ 0 }; i < m.size(); ++i) {
        for (int j{ 0 }; j < m.size(); ++j) {
            
            if (at(i, j)) {
                for (int jx{ 0 }; jx < m.size(); ++jx) {

                    if (at(j, jx)) {
                        m[i] |= 1 << jx;
                    }
                }
            }
        }
    }

    return m;
}

std::istream &operator>>(std::istream &in, BoolMatrix &m) {
    for (int i{ 0 }; i < m.size(); ++i) {

        std::cout << "Enter a row: ";
        for (int j{ 0 }; j < m.size(); ++j) {

            int temp{ -1 };
            std::cin >> temp;
            /*while (true) {
                std::cin >> temp;

                if (temp == 0 || temp == 1) {
                    break;
                }

                std::cerr << "Please only enter either a 1 or 0 while entering a bool matrix.\n";
            }
            */
            m[i] |= temp << j;
        }
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const BoolMatrix &m) {
    for (int i{ 0 }; i < m.size(); ++i) {
        for (int j{ 0 }; j < m.size(); ++j) {
            std::cout << ((m[i] >> j) & 1) << ' ';
        }

        std::cout << '\n';
    }

    return out;
}