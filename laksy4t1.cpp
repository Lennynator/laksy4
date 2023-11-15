// laksy4t1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 

class Auto 
{
private:
	std::string _rekisteri;
	std::string _huippunopeus;
	int _nopeus = 0;
	int _matka = 0;
	



public: 

	void set_rekisteri(const std::string& rekisteri)
	{
		_rekisteri = rekisteri;
	}
	void set_huippu(const std::string& huippu)
	{
		_huippunopeus = huippu;
	}
	void set_kuljettumatka(int kuljettumatka) 
	{
		_matka = kuljettumatka;
	}
	void set_nopeus(int nopeus)
	{
		_nopeus = nopeus;
	}

	void statsit() const 
	{
		std::cout << "Auton rekisteri: " << _rekisteri << " Auton huippunopeus: " << _huippunopeus << "Auton nopeus nyt: " << _nopeus << "Auton kulkema matka: " << _matka << "\n";
	}




};

int main() 
{

	Auto ford;

	ford.set_rekisteri("RRR-333");
	ford.set_huippu("77 km/h");
	ford.set_kuljettumatka(0);
	ford.set_nopeus(0);
	ford.statsit();
	return 0;


}


