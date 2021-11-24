#ifndef BOOLMATRIX
#define BOOLMATRIX

#include <vector>

class BoolMatrix {
private:
	using boolMatrix_t = std::vector<std::uint32_t>;

	boolMatrix_t matrix{};
public:
	BoolMatrix(unsigned int size)
	{
		matrix.resize(size);
	}

	size_t size() const;
	std::uint32_t &operator[](int index);
	const std::uint32_t &operator[](int index) const;
	bool at(int i, int j) const;

	bool isReflective();
	bool isAntiReflective();
	bool isSymmetrical();
	bool isAntiSymmetrical();
	bool isAsymmetrical();
	bool isTransitive();

	BoolMatrix getTransitiveClosure();
	BoolMatrix getReflectiveClosure();
	BoolMatrix getSymmetricalClosure();

	BoolMatrix powerUp();

	friend std::istream &operator>>(std::istream &in, BoolMatrix &m);
	friend std::ostream &operator<<(std::ostream &out, const BoolMatrix &m);
};

#endif