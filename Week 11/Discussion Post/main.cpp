#include <iostream>

template <typename T>
requires std::integral<T> || std::floating_point<T>
class PointInPositive3DSpace {

public:
    PointInPositive3DSpace(const T x, const T y, const T z) {
        if (x < 0 || y < 0 || z < 0) {
            throw InNegative3DSpace("This point is not in positive 3D space! Whatever that means...!");
        }

        this->x = x;
        this->y = y;
        this->z = z;
    }

    PointInPositive3DSpace operator+(PointInPositive3DSpace p2) const {
        return (x + p2.x, y + p2.y, z + p2.z);
    }

    std::ostream &operator<<(std::ostream &os, const PointInPositive3DSpace &p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }

    class InNegative3DSpace : public std::runtime_error {
    public:
        using std::runtime_error::runtime_error;
    };

private:
    T x, y, z;

};

int main() {
    try {
        std::cout << "Going to try to make a point in positive 3D space..." << std::endl;
        double x = 1.25;
        double y = 2.00;
        double z = 3.00;
        PointInPositive3DSpace<double> p(x, y, z);
    } catch (PointInPositive3DSpace::InNegative3DSpace &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
