// kvadraticka.cpp - program pro reseni kvadraticke rovnice ax^2 + bx + c = 0
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cout << "Vyreseni kvadraticke rovnice ax^2 + bx + c = 0\n";
    cout << "Zadejte koeficient a: ";
    cin >> a;
    cout << "Zadejte koeficient b: ";
    cin >> b;
    cout << "Zadejte koeficient c: ";
    cin >> c;

    const double EPS = 1e-12;
    // Degenerovane pripady
    if (fabs(a) < EPS) {
        if (fabs(b) < EPS) {
            if (fabs(c) < EPS) {
                cout << "Rovnice ma nekonecne mnoho reseni.\n";
            } else {
                cout << "Rovnice nema zadne reseni.\n";
            }
        } else {
            double x = -c / b;
            cout << "Linearni rovnice, reseni: x = " << x << "\n";
        }
        return 0;
    }

    // Kvadraticka rovnice
    double D = b*b - 4*a*c;
    cout << "Diskriminant D = " << D << "\n";
    if (D > EPS) {
        double sqrtD = sqrt(D);
        double x1 = (-b + sqrtD) / (2*a);
        double x2 = (-b - sqrtD) / (2*a);
        cout << "2 realna reseni: x1 = " << x1 << ", x2 = " << x2 << "\n";
    } else if (fabs(D) < EPS) {
        double x = -b / (2*a);
        cout << "Jedno dvojnasobne reseni: x = " << x << "\n";
    } else {
        double sqrtNegD = sqrt(-D);
        double realPart = -b / (2*a);
        double imagPart = sqrtNegD / (2*a);
        cout << "2 komplexni reseni: "
             << "x1 = " << realPart << " + " << imagPart << "i, "
             << "x2 = " << realPart << " - " << imagPart << "i" << "\n";
    }

    return 0;
}
