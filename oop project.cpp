#include <bits/stdc++.h>
using namespace std;

// Abstract class
class AbstractCalculator {
public:
    virtual void calculate() = 0;
};

// Encapsulation
class Add {
private:
    double a, b;
public:
    void setValues(double x, double y) {
        a = x; b = y;
    }
    double getResult() {
        return a + b;
    }
};

// Inheritance
class Subtract : public AbstractCalculator {
protected:
    double a, b;
public:
    Subtract(double x, double y) {
        a = x; b = y;
    }
    void calculate() override {
        cout << "Subtraction: " << (a - b) << endl;
    }
};

// Function Overriding
class MultiplyBase {
public:
    virtual void calculate() {
        cout << "Base Multiplication" << endl;
    }
};

class MultiplyDerived : public MultiplyBase {
private:
    double a, b;
public:
    MultiplyDerived(double x, double y) {
        a = x; b = y;
    }
    void calculate() override {
        cout << "Multiplication: " << (a * b) << endl;
    }
};

// Function Overloading
class Divide {
public:
    double divide(int a, int b) {
        return (b != 0) ? (double)a / b : 0;
    }
    double divide(double a, double b) {
        return (b != 0) ? a / b : 0;
    }
};

class MathOverload {
public:
    double operation(double x) { return x * x; } // square
    double operation(double x, bool squareRoot) { return squareRoot ? sqrt(x) : x; }
    double cube(double x) { return x * x * x; }
    double cubeRoot(double x) { return cbrt(x); }
};

// Friend Function
class Power;
class Base {
private:
    double base;
public:
    Base(double b) : base(b) {}
    friend double power(const Base&, const Power&);
};

class Power {
private:
    double exp;
public:
    Power(double e) : exp(e) {}
    friend double power(const Base&, const Power&);
};

double power(const Base& b, const Power& p) {
    return pow(b.base, p.exp);
}

// Trigonometry
class TrigBase {
public:
    virtual void show(double angle) {
        cout << "Base angle: " << angle << endl;
    }
};

class TrigDerived : public TrigBase {
public:
    void show(double angle) override {
        cout << "sin(" << angle << ") = " << sin(angle) << endl;
        cout << "cos(" << angle << ") = " << cos(angle) << endl;
        cout << "tan(" << angle << ") = " << tan(angle) << endl;
    }
};

// Logarithm using static function
class Logarithm {
public:
    static double log10calc(double x) {
        return log10(x);
    }
    static double lncalc(double x) {
        return log(x);
    }
};

// Factorial using template
template <typename T>
class Factorial {
public:
    T compute(T n) {
        if (n <= 1) return 1;
        return n * compute(n - 1);
    }
};

// Modulus using operator overloading
class Modulus {
private:
    int a;
public:
    Modulus(int x) : a(x) {}
    int operator%(const Modulus& m) {
        return a % m.a;
    }
};

// Inline percentage
inline double percentage(double part, double total) {
    return (total != 0) ? (part / total) * 100 : 0;
}
// nCr / nPr using template
template <typename T>
class Combinatorics {
public:
    T fact(T n) {
        return (n <= 1) ? 1 : n * fact(n - 1);
    }

    T nCr(T n, T r) {
        if (r > n) {
            cout << "Error: r cannot be greater than n.\n";
            return 0;
        }
        return fact(n) / (fact(r) * fact(n - r));
    }

    T nPr(T n, T r) {
        if (r > n) {
            cout << "Error: r cannot be greater than n.\n";
            return 0;
        }
        return fact(n) / fact(n - r);
    }

    void run() {
        T n, r;
        cout << "\n----- nCr / nPr Calculation -----\n";
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter r: ";
        cin >> r;
        cout << "nCr: " << nCr(n, r) << ", nPr: " << nPr(n, r) << endl;
    }
};

// MAIN FUNCTION
int main() {
    double x, y;
    int choice;

    while (true) {
        cout << "\n========= Scientific Calculator =========\n";
        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square/Square Root\n7. Trigonometry\n8. Logarithm\n";
        cout << "9. Factorial\n10. Modulus\n11. Percentage\n12. Cube/Cube Root\n13. nCr/nPr\n0. Exit\n";
        cout << "=========================================\n";
        cout << ">> Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\n[INFO] Exiting calculator. Goodbye!\n";
            break;
        }

        cout << "\n---[ INPUT SECTION ]----------------------\n";
        switch (choice) {
            case 1: {
                cout << "Enter two numbers (a b): ";
                cin >> x >> y;
                Add a;
                a.setValues(x, y);
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Addition: " << a.getResult() << endl;
                break;
            }
            case 2: {
                cout << "Enter two numbers (a b): ";
                cin >> x >> y;
                Subtract s(x, y);
                cout << "\n---[ RESULT ]-----------------------------\n";
                s.calculate();
                break;
            }
            case 3: {
                cout << "Enter two numbers (a b): ";
                cin >> x >> y;
                MultiplyBase* m = new MultiplyDerived(x, y);
                cout << "\n---[ RESULT ]-----------------------------\n";
                m->calculate();
                delete m;
                break;
            }
            case 4: {
                cout << "Enter two numbers (a b): ";
                cin >> x >> y;
                Divide d;
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Integer: " << d.divide((int)x, (int)y) << ", Floating: " << d.divide(x, y) << endl;
                break;
            }
            case 5: {
                cout << "Enter base and exponent: ";
                cin >> x >> y;
                Base b(x);
                Power p(y);
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Power: " << power(b, p) << endl;
                break;
            }
            case 6: {
                cout << "Enter a number: ";
                cin >> x;
                MathOverload mo;
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Square: " << mo.operation(x) << ", Square Root: " << mo.operation(x, true) << endl;
                break;
            }
            case 7: {
                cout << "Enter angle in radians: ";
                cin >> x;
                TrigBase* t = new TrigDerived();
                cout << "\n---[ RESULT ]-----------------------------\n";
                t->show(x);
                delete t;
                break;
            }
            case 8: {
                cout << "Enter a number > 0: ";
                cin >> x;
                cout << "\n---[ RESULT ]-----------------------------\n";
                if (x > 0) {
                    cout << "log10(" << x << ") = " << Logarithm::log10calc(x) << endl;
                    cout << "ln(" << x << ") = " << Logarithm::lncalc(x) << endl;
                } else {
                    cout << "Error: log undefined for x <= 0\n";
                }
                break;
            }
            case 9: {
                int n;
                cout << "Enter an integer: ";
                cin >> n;
                Factorial<int> f;
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Factorial of " << n << " = " << f.compute(n) << endl;
                break;
            }
            case 10: {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                Modulus m1(a), m2(b);
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Modulus: " << (m1 % m2) << endl;
                break;
            }
            case 11: {
                cout << "Enter part and total: ";
                cin >> x >> y;
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Percentage: " << percentage(x, y) << "%" << endl;
                break;
            }
            case 12: {
                cout << "Enter a number: ";
                cin >> x;
                MathOverload mo;
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "Cube: " << mo.cube(x) << ", Cube Root: " << mo.cubeRoot(x) << endl;
                break;
            }
            case 13: {
                int n, r;
                cout << "Enter n and r: ";
                cin >> n >> r;
                Combinatorics<int> c;
                cout << "\n---[ RESULT ]-----------------------------\n";
                cout << "nCr: " << c.nCr(n, r) << ", nPr: " << c.nPr(n, r) << endl;
                break;
            }
            default:
                cout << "[ERROR] Invalid choice.\n";
        }
        cout << "------------------------------------------\n";
    }

    return 0;
}
