#include <iostream>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

void ordenarFechas(Fecha fechas[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            // Comparar las fechas
            if (fechas[j].anio > fechas[j + 1].anio ||
                (fechas[j].anio == fechas[j + 1].anio && fechas[j].mes > fechas[j + 1].mes) ||
                (fechas[j].anio == fechas[j + 1].anio && fechas[j].mes == fechas[j + 1].mes && fechas[j].dia > fechas[j + 1].dia)) {
                // Intercambiar las fechas si están en el orden incorrecto
                Fecha temp = fechas[j];
                fechas[j] = fechas[j + 1];
                fechas[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int tam = 5;
    Fecha fechas[tam];

    // Solicitar las fechas al usuario
    for (int i = 0; i < tam; i++) {
        std::cout << "Ingrese la fecha " << (i + 1) << " (dd mm aaaa): ";
        std::cin >> fechas[i].dia >> fechas[i].mes >> fechas[i].anio;
    }

    // Ordenar las fechas
    ordenarFechas(fechas, tam);

    // Mostrar las fechas ordenadas
    std::cout << "Fechas ordenadas ascendentemente:\n";
    for (int i = 0; i < tam; i++) {
        std::cout << fechas[i].dia << "/" << fechas[i].mes << "/" << fechas[i].anio << "\n";
    }

    return 0;
}

