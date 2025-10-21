#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Mateescu Emil Stefan
// Domeniu: MagazindESport
// Obiecte: Sauna, BandaDeAlergat, PudraProteica

enum TipSauna
{
    USCATA = 1,
    UMEDA = 2
};

enum TipBanda
{
    ELECTRICA = 1,
    MECANICA = 2,
    CURBATA = 3
};


class Sauna
{
public:
    char *marca = nullptr;
    int capacitate = 0;
    TipSauna tipSauna = USCATA;
    int PutereSoba = 0;
    float pret = 0;
    int Inaltime = 2;
    int Latime = 1;
    int Lungime = 1;

    float volumSauna()
    {
        return this->Inaltime*this->Latime*this->Lungime;
    }
};

class PudraProteica
{
public:
    char *brand = nullptr;
    int gramaj = 0;
    int ppp = 0; //proteina per portie
    float pret = 0;

    float portiiInGramaj()
    {
        //cout << endl << "Pudra Proteica contine " << this->gramaj/this->ppp << "portii";
        return this->gramaj/this->ppp;
    }
};

class BandaDeAlergat
{
public:
    char *marca = nullptr;
    TipBanda tipBanda = ELECTRICA;
    float pret = 0;

    void afisareBanda()
    {
        cout << endl << "Bande de alergat de marca " << this->marca << ", este " << 
        this->afisareTipBanda() << " si costa " << this->pret << "lei" << endl;
    }

    char* afisareTipBanda()
    {
        if (this->tipBanda == ELECTRICA)
            return "ELECTRICA";
        else if (this->tipBanda == MECANICA)
            return "MECANICA";
        else if (this->tipBanda == CURBATA)
            return "CURBATA";
        else return "NECUNOSCUT";
    } 
};

int main()
{
    BandaDeAlergat banda1;

    banda1.marca = new char[strlen("GymFit")+1];
    strcpy(banda1.marca, "GymFit");
    banda1.tipBanda = ELECTRICA;
    banda1.pret = 1999.99;

    banda1.afisareBanda();
}