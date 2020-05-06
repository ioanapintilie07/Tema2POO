#include <iostream>
#include <fstream>
#include <cstring>
#include "Complex.h"
#include "Vector.h"
#include "Stiva.h"
#include "Coada.h"

using namespace std;

int main() {
    ifstream fin("intrare.in");
    ofstream fout("iesire.out");
    Vector *elemente;
    Coada *coada;
    int nrInstructiuni, nrStructuri, i, j, pozitie;
    Complex valoare;
    string instructiune;
    fin >> nrStructuri;
    for (i = 0; i < nrStructuri; ++i) {
        elemente = new Vector;
        fin >> *elemente;
        fin >> nrInstructiuni;
        fout << "Initial: " << *elemente << "\n";
        for (j = 0; j < nrInstructiuni; ++j) {
            fin >> instructiune;
            if (instructiune == "adauga") {
                fin >> valoare >> pozitie;
                elemente->adauga(valoare, pozitie);
                fout << "Adaugat " << valoare << ": " << *elemente << "\n";
            } else if (instructiune == "sterge") {
                fin >> pozitie;
                valoare = elemente->sterge(pozitie);
                fout << "Eliminat " << valoare << ": " << *elemente << "\n";
            }
        }
        if (elemente->purImaginar(0, elemente->getDim() - 1)) fout << "Vector pur imaginar \n\n";
        else fout << "Vectorul nu este pur imaginar\n\n";
        delete elemente;
    }

    fin >> nrStructuri;
    for (i = 0; i < nrStructuri; ++i) {
        fin >> nrInstructiuni;
        elemente = new Stiva;
        for (j = 0; j < nrInstructiuni; ++j) {
            fin >> instructiune;
            if (instructiune == "adauga") {
                fin >> valoare;
                elemente->adauga(valoare, -1);
                fout << "Adaugat " << valoare << ": " << *elemente << "\n";
            } else if (instructiune == "sterge") {
                valoare = elemente->sterge(-1);
                fout << "Eliminat " << valoare << ": " << *elemente << "\n";
            }
        }
        if (elemente->purImaginar(0, elemente->getDim() - 1)) fout << "Stiva pur imaginara \n\n";
        else fout << "Stiva nu este pur imaginara\n\n";
        delete elemente;
    }

    fin >> nrStructuri;
    for (i = 0; i < nrStructuri; ++i) {
        fin >> nrInstructiuni;
        coada = new Coada;
        for (j = 0; j < nrInstructiuni; ++j) {
            fin >> instructiune;
            if (instructiune == "adauga") {
                fin >> valoare;
                coada->adauga(valoare, -1);
                fout << "Adaugat " << valoare << ": " << *coada << "\n";
            } else if (instructiune == "sterge") {
                valoare = coada->sterge(-1);
                fout << "Eliminat " << valoare << ": " << *coada << "\n";
            }
        }
        if (coada->purImaginar(coada->getFirst(), coada->getLast())) fout << "Coada pur imaginara \n\n";
        else fout << "Coada nu este pur imaginara\n\n";
        delete coada;
    }
    fin.close();
    fout.close();
    return 0;
}
