#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class Auto {
private:
    static int matkajanopeusalussa;

public:
    std::string rekisteri;
    int huippunopeus;
    int nopeus;
    int kuljettumatka;

    Auto() : rekisteri(""), huippunopeus(0), nopeus(matkajanopeusalussa), kuljettumatka(matkajanopeusalussa) {}

    Auto(const std::string& rek, int huippu) : rekisteri(rek), huippunopeus(huippu), nopeus(matkajanopeusalussa), kuljettumatka(matkajanopeusalussa) {}

    void kiihdyta(int muutosnopeus) {
        nopeus += muutosnopeus;

        if (nopeus < 0) {
            nopeus = 0;
        }
        if (nopeus > huippunopeus) {
            nopeus = huippunopeus;
        }

        kuljettumatka += nopeus;
    }

    void kulje(double tunnit) {
        kuljettumatka += int(nopeus * tunnit);
    }
};

int Auto::matkajanopeusalussa = 0;

int main() {
    Auto Autot[10];
    bool kisa = true;

    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        std::stringstream ss;
        ss << "ABC-" << i + 1;

        Autot[i] = Auto(ss.str(), std::rand() % 101 + 100);
    }

    while (kisa) {
        for (auto& i : Autot) {
            i.kiihdyta(std::rand() % 26 - 10);
            i.kulje(1);

            if (i.kuljettumatka > 10000) {
                std::cout << "Voittaja oli auto " << i.rekisteri << "\n";
                std::cout << "Huippunopeus oli " << i.huippunopeus << "\n";
                kisa = false;
            }
        }
    }

    std::cout << "\n";
    for (const auto& i : Autot) {
        std::cout << i.rekisteri << "\t" << i.kuljettumatka << "\t" << i.nopeus << "\t" << i.huippunopeus << "\n";
    }

    return 0;
}
