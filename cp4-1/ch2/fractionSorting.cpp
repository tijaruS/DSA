#include <bits/stdc++.h>
class Fraction {
  private:
    int numerator;
    int denominator;
    void simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int commonDivisor =
            std::gcd(std::abs(numerator), std::abs(denominator));
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

  public:
    Fraction(int num = 0, int den = 0) : numerator(num), denominator(den) {
        if (denominator == 0) {
            std::cerr << "denominator can not be zero. Setting it to 1"
                      << std::endl;
            denominator = 1;
        }
        simplify();
    }
    bool operator<(const Fraction &other) const {
        return static_cast<long long>(numerator) * other.denominator <
               static_cast<long long>(other.numerator) * denominator;
    }
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
    friend std::istream &operator>>(std::istream &is, Fraction &f);
};
std::ostream &operator<<(std::ostream &os, const Fraction &f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}
std::istream &operator>>(std::istream &is, Fraction &f) {
    char slash;
    is >> f.numerator >> slash >> f.denominator;
    f.simplify();
    return is;
}
int main() {
    std::vector<Fraction> fractions;
    int no;
    std::cin >> no;
    for (int i = 0; i < no; i++) {
        Fraction f;
        std::cin >> f;
        fractions.push_back(f);
    }
    std::sort(fractions.begin(), fractions.end());
    for (const auto &f : fractions) {
        std::cout << f << " ";
    }
    std::cout << std::endl;

    return 0;
}
