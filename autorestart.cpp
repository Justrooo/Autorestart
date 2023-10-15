#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "INFO: Program restartuje komputer z systemem Windows. Aby powtarzac restart wystarczy dac"
        " skrot pliku .exe do folderu shell:startup. Aby zmienic czas restartu zmodifikuj wartosc w pliku czas.txt UWAGA: ZBYT MALA"
        "WARTOSC CZASU MOZE SKUTKOWAC NIEODWRACALNYM CIAGLYM RESTARTEM SYSTEMU!!!" << std::endl;
    int czas{}; // Argumentu czasu

    ifstream plik{ "czas.txt" };
    if (!plik)
    {
        cerr << "BLAD OTWARCIA PLIKU" << std::endl;
        exit(1);
    }
    if (plik >> czas)
    {
        std::string komenda{ "C:\\Windows\\System32\\shutdown /s /t " + std::to_string(czas) };
        system(komenda.c_str());
        std::cout << "Restart za: " << czas << " sekund" << std::endl;
    }
    else
    {
        cerr << "BLAD ODCZYTANIA CZASU Z PLIKU" << std::endl;
        exit(1);
    }
}