#include "dijkstra.h"

void Graf::pokazWynik(Dijkstra* arr) {
    cout << "Wierzcholek |  Dystans od zaznaczonego" << endl;
    for (int i = 0; i < liczbaWierzcholkow; i++)
    {
        cout << "\t" << i << " \t\t|\t\t\t" << arr[i].dlugoscSciezki << endl;
    }
}

int Graf::minimum(Dijkstra* arr) {
	int min = -1;
	int minimalnyDystans = INT_MAX;

	for (int i = 0; i < liczbaWierzcholkow; i++) {
		if (!arr[i].czyPowtorzony && arr[i].dlugoscSciezki < minimalnyDystans) { // AND
            // jesli niepowtorzony i dlugosc sciezki jest mniejsza od aktualnego minimum -> zmiana aktualnego minimum
			min = i;
			minimalnyDystans = arr[i].dlugoscSciezki;
		}
	}
	return min;
}

// ALGORYTM DIJKSTRY DLA MACIERZY SĄSIEDZTWA
Dijkstra* Graf::dijkstraMacierz() {

	Dijkstra* arr = new Dijkstra[liczbaWierzcholkow]; // iniciuje strukture Djikstry
	droga = new int[liczbaWierzcholkow];

    // Poczatkowe ustawienie parametrow
	for (int i = 0; i < liczbaWierzcholkow; i++) {
		if (i == wierzcholekStartowy) {
			arr[i].dlugoscSciezki = 0; // Ustawia dlugosc sciezki do aktualnego wiercholka na zero - "zaznacza" wiercholek
		} else {
			arr[i].dlugoscSciezki = INT_MAX; // Ustawia dlugosc sciezki na nieskonczonosc
		}
		arr[i].czyPowtorzony = false;
		droga[i] = -1; // Warotsc ktora nie moze oznaczac numeru wiecholka o najmniejszym dystansie
	}

	int min = minimum(arr); // iniciuje zmienna min przetrzyujaca wierzcholek

	while (min != -1) { // Dopkoi min nie jest wartoscia domyslna
		arr[min].czyPowtorzony = true;
		for (int i = 0; i < liczbaWierzcholkow; i++) {
			if (macierzSasiedztwa[min][i] > 0 && arr[min].dlugoscSciezki + macierzSasiedztwa[min][i] < arr[i].dlugoscSciezki) { // AND
                // Jesli krawedz istnieje i aktualna dlugosc sciezki + waga sa mniejsze od dlugosci sciezki celu
				arr[i].dlugoscSciezki = arr[min].dlugoscSciezki + macierzSasiedztwa[min][i]; // Przypisuje nowa dlugosc sciezki
				droga[i] = min; // Zaznaczam aktualny wiercholek na dordze
			}
		}
		min = minimum(arr);
	}
	return arr;
}

/// ALGORYTM DIJKSTRY DLA LISTY SĄSIEDZTWA
Dijkstra* Graf::dijkstraLista() {

	Dijkstra* arr = new Dijkstra[liczbaWierzcholkow];
	droga = new int[liczbaWierzcholkow];
    Element* temp;

    // Poczatkowe ustawienie parametrow
	for (int i = 0; i < liczbaWierzcholkow; i++) {
		if (i == wierzcholekStartowy) {
			arr[i].dlugoscSciezki = 0; // Ustawia dlugosc sciezki do aktualnego wiercholka na zero - "zaznacza" wiercholek
		} else {
			arr[i].dlugoscSciezki = INT_MAX; // Ustawia dlugosc sciezki na nieskonczonosc
		}
		arr[i].czyPowtorzony= false;
		droga[i] = -1; // Warotsc ktora nie moze oznaczac numeru wiecholka o najmniejszym dystansie
	}

	int min = minimum(arr);

	while (min != -1) { // Dopkoi min nie jest wartoscia domyslna
		arr[min].czyPowtorzony = true;
		temp = listaSasiedztwa[min];
		
		for (temp = listaSasiedztwa[min]; temp; temp = temp->Nastepny) {
			if (arr[min].dlugoscSciezki + temp->waga < arr[temp->wezel].dlugoscSciezki) {
                // Jesli aktualna dlugosc sciezki + waga sa mniejsze od dlugosci sciezki celu
				arr[temp->wezel].dlugoscSciezki = arr[min].dlugoscSciezki + temp->waga; // Przypisuje nowa dlugosc sciezki
				droga[temp->wezel] = min; // Zaznaczam aktualny wiercholek na dordze
			}			
		}
		min = minimum(arr);
	}
	return arr;
}