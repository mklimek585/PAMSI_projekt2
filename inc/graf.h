#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Element {
    Element* Nastepny;
    int wezel;
    int waga;
};

struct Dijkstra {
    int dlugoscSciezki;
    bool czyPowtorzony;
};

class Graf {
    private:
    int liczbaWierzcholkow;
    int liczbaKrawedzi;
    int wierzcholekStartowy;
    int** macierzSasiedztwa;
    Element* element;
    Element** listaSasiedztwa;
    int* droga;

    public:
    Graf(int liczbaWierzcholkow, int liczbaKrawedzi, int wierzcholekStartowy);
    void dodajKrawedz(int poczatek, int koniec, int waga);
    void wyswietlMacierz();
    void wyswietlListe();
    void pokazWynik(Dijkstra* arr);
    int minimum(Dijkstra* arr);
    Dijkstra* dijkstraMacierz();
    Dijkstra* dijkstraLista();
    void zapisz(Dijkstra* arr);

    static void UtworzGraf(int w, float g);
    static void WczytajGraf(Graf*& graf);
};

void generujGraf();
void wczytajGraf(Graf*& graf);

#endif