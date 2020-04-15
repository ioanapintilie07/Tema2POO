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
    int i, j, nrVectori, nrStive, nrCozi, nrInstructiuni, pozitie;
    char instructiune[10];
    Complex valoare;
    fin >> nrVectori;
    for (i = 0; i < nrVectori; ++i) {
        elemente = new Vector;
        fin >> *elemente >> nrInstructiuni;
        for (j = 0; j < nrInstructiuni; ++j) {
            fin >> instructiune;
            if (strcmp(instructiune, "adauga") == 0) {
                fin >> valoare >> pozitie;
                fout << "Vectorul initial: " << *elemente << "\nA fost adaugata valoarea " << valoare << " pe pozitia "
                     << pozitie << "\n";
                elemente->adaugare(valoare, pozitie);
                fout << "Vectorul modificat: " << *elemente << "\n";
            } else if (strcmp(instructiune, "sterge") == 0) {
                fin >> pozitie;
                fout << "Vectorul initial: " << *elemente << "\n";
                valoare = elemente->stergere(pozitie);
                fout << "A fost eliminata valoarea  " << valoare << "\nVectorul modificat: " << *elemente << "\n";
            }
            fout << "\n";
        }
        delete elemente;
    }
    fin >> nrStive;
    for (i = 0; i < nrStive; ++i) {
        elemente = new Stiva;
        fin >> *elemente >> nrInstructiuni;
        if (elemente->purImaginar() == 1)
            fout << "Stiva  fara modificari este pur imaginara.\n";
        else fout << "Stiva fara modificari NU este pur imaginara.\n";
        for (j = 0; j < nrInstructiuni; ++j) {
            fin >> instructiune;
            if (strcmp(instructiune, "push") == 0) {
                fin >> valoare;
                fout << "Stiva initiala: " << *elemente << "\nA fost adaugata valoarea " << valoare << "\n";
                elemente->adaugare(valoare, -1);
                fout << "Stiva modificata: " << *elemente << "\n";
            } else if (strcmp(instructiune, "pop") == 0) {
                fout << "Stiva initiala: " << *elemente << "\n";
                valoare = elemente->stergere(-1);
                fout << "A fost eliminata valoarea  " << valoare << "\nStiva modificata: " << *elemente << "\n";
            }
            fout << "\n";
        }
        delete elemente;
    }
    fin >> nrCozi;
    for (i = 0; i < nrStive; ++i) {
        elemente = new Coada;
        fin >> *elemente >> nrInstructiuni;
        if (elemente->purImaginar() == 1) fout << "Coada fara modificari este pur imaginara. \n";
        else fout << "Coada fara modificari NU este pur imaginara.\n";
        for (j = 0; j < nrInstructiuni; ++j) {
            fin >> instructiune;
            if (strcmp(instructiune, "queue") == 0) {
                fin >> valoare;
                fout << "Coada initiala: " << *elemente << "\nA fost adaugata valoarea " << valoare << "\n";
                elemente->adaugare(valoare, 0);
                fout << "Coada modificata: " << *elemente << "\n";
            } else if (strcmp(instructiune, "dequeue") == 0) {
                fout << "Coada initiala: " << *elemente << "\n";
                valoare = elemente->stergere(0);
                fout << "A fost eliminata valoarea  " << valoare << "\nCoada modificata: " << *elemente << "\n";
            }
            fout << "\n";
        }
        delete elemente;
    }
    fin.close();
    fout.close();
    return 0;
}
