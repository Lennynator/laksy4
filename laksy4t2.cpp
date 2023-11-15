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
    ford.set_huippu(77);
    ford.set_kuljettumatka(0);
    ford.set_nopeus(0);

    ford.statsit();
    ford.kiihdyta(30);
    ford.statsit();
    ford.kiihdyta(70);
    ford.statsit();
    ford.kiihdyta(50);
    ford.statsit();
    ford.kiihdyta(-200);
    ford.statsit();

    

    return 0;
}
