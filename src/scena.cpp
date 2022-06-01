#include "scena.h"
#include "graf.h"

using namespace std;

void pokaz(bool _menu) {
    if (_menu) {
        menu();
    }
}

void wypiszMozliwosci() {
    cout << "1 - wygeneruj graf" << endl;
    cout << "2 - wczytaj graf" << endl;
    cout << "3 - wyświetl graf" << endl;
    cout << "4 - algorytm Dijkstra na macierzy sąsiedztwa" << endl;
    cout << "5 - algorytm Dijkstra na liście sąsiedztwa" << endl;
    cout << "0 - koniec działania programu" << endl;
    cout << "Twój wybór: ";
}

void menu() {

    int wybor;
    bool flaga = true;
    Graf* graf;
    Dijkstra* arr;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    while (flaga) {
        wypiszMozliwosci();
        cin >> wybor;
        switch (wybor) {
            case 1: {
                generujGraf();
                break;
            }
            case 2: {
                wczytajGraf(graf);
                break;
            }
            case 3: {
                graf->wyswietlMacierz();
                graf->wyswietlListe();
                break;
            }
            case 4: {
                auto t1 = high_resolution_clock::now(); // poczatek mierzenia czasu
                for (int i = 0; i < 100; i++) {
                    arr = graf->dijkstraMacierz();
                }
                auto t2 = high_resolution_clock::now(); // koniec mierzenia czasu
                duration<double, std::milli> ms_double = t2 - t1; // obliczanie czasu
                cout << "ALGORYTM DJIKSTRY DLA MACIERZY";
                cout << endl << "Czas działania algorytmu: " << ms_double.count() << " ms." << endl;
                graf->zapisz(arr); // zapisuje najkrotsze sciezki do pliku
                graf->pokazWynik(arr); // wyswietla najkrotsze sciezki
                break;
            }
            case 5: {
                auto t1 = high_resolution_clock::now(); // poczatek mierzenia czasu
                for (int i = 0; i < 100; i++) {
                    arr = graf->dijkstraLista();
                }
                auto t2 = high_resolution_clock::now(); // koniec mierzenia czasu
                duration<double, std::milli> ms_double = t2 - t1; // obliczanie czasu
                cout << "ALGORYTM DJIKSTRY DLA LISTY";
                cout << endl << "Czas działania algorytmu: " << ms_double.count() << " ms." << endl;
                graf->zapisz(arr); // zapisuje najkrotsze sciezki do pliku
                graf->pokazWynik(arr); // wyswietla najkrotsze sciezki
                break;
            }
            case 0: {
                flaga = false;
                break;
            }
            default: {
                cout << "Błędny wybór. Spróbuj jeszcze raz" << endl;
                break;
            }
        }
    }
}

void testy() {
//    int liczbaKrawedzi, liczbaWierzcholkow, wierzcholekStartowy, waga;
//    float gestoscGrafu;
    Graf *graf;
    Dijkstra *arr;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    using std::chrono::seconds;

    ofstream plik, pomocniczy;
    string nazwaPliku;
    plik.open("TestyEfektywnosci.txt");
    int tab[5] = {10, 20, 50, 100, 200};
    float tab2[4] = {0.25, 0.5, 0.75, 1};
    plik << "TESTY MACIERZY \n";
    for (int k = 0; k < 5; k++) {
        plik << "Ilosc wiercholkow " << tab[k] << endl;
        for (int j = 0; j < 4; j++) {
            plik << "Gestosc " << tab2[j] << endl;
            Graf::UtworzGraf(tab[k],tab[j]);
            Graf::WczytajGraf(graf);
            auto t1 = high_resolution_clock::now(); // poczatek mierzenia czasu
            for (int i = 0; i < 100; i++) {
                arr = graf->dijkstraMacierz();
            }
            auto t2 = high_resolution_clock::now(); // koniec mierzenia czasu
            duration<double, std::milli> ms_double = (t2 - t1)/100; // obliczanie czasu
            plik << ms_double.count() << endl;
        }
    }
    plik << endl << endl;
    plik << "TESTY LISTY \n";
    for (int k = 0; k < 5; k++) {
        plik << "Ilosc wiercholkow " << tab[k] << endl;
        for (int j = 0; j < 4; j++) {
            plik << "Gestosc " << tab2[j] << endl;
            Graf::UtworzGraf(tab[k],tab[j]);
            Graf::WczytajGraf(graf);
            auto t1 = high_resolution_clock::now(); // poczatek mierzenia czasu
            for (int i = 0; i < 100; i++) {
                arr = graf->dijkstraLista();
            }
            auto t2 = high_resolution_clock::now(); // koniec mierzenia czasu
            duration<double, std::milli> ms_double = (t2 - t1)/100; // obliczanie czasu
            plik << ms_double.count() << endl;
        }
    }
    plik.close(); //TODO
}