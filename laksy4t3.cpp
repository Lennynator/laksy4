#include <iostream>
#include <string>

class Auto {
private:
    std::string _rekisteri;
    int _huippunopeus = 0;
    int _nopeus = 0;
    int _matka = 0;

public:
    void set_rekisteri(const std::string& rekisteri) {
        _rekisteri = rekisteri;
    }

    void set_huippu(int huippu) {
        _huippunopeus = huippu;
    }
    void kulje(double tuntia) {
        double matkaLisays = _nopeus * tuntia;

        _matka += static_cast<int>(matkaLisays);
    }

    void set_kuljettumatka(int kuljettumatka) {
        _matka = kuljettumatka;
    }

    void set_nopeus(int nopeus) {
        _nopeus = nopeus;
    }

    void statsit() const {
        std::cout << "Auton rekisteri: " << _rekisteri << " Auton huippunopeus: " << _huippunopeus << "km/h. Auton nopeus nyt: " << _nopeus << " Auton kulkema matka: " << _matka << "\n";
    }

    void kiihdyta(int kiihdytys) {
        _nopeus = _nopeus + kiihdytys;

        if (_nopeus < 0) {
            _nopeus = 0;
        }
        if (_nopeus > _huippunopeus) {
            _nopeus = _huippunopeus;
        }
    }
};

int main() {
    Auto ford;

    ford.set_rekisteri("RRR-333");
    ford.set_huippu(90);
    ford.set_kuljettumatka(2000);
    ford.set_nopeus(60);

    ford.kulje(1.5);
    ford.statsit();



    return 0;
}
