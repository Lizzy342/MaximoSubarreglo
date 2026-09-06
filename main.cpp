#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>

int cubico(const std::vector<int>& A){
    int maximo = A[0];
    for (int i = 0; i < A.size(); i++){
        for (int j = i; j < A.size(); j++){
            int parcial = 0;
            for (int k = i; k <= j; k++){
                parcial += A[k];
            }
            if (parcial > maximo){
                maximo = parcial;
            }
        }
    }
    return maximo;
}

int cuadratico(const std::vector<int>& A){
    int maximo = A[0];
    for (int i = 0; i < A.size(); i++){
        int parcial = 0;
        for (int j = i; j < A.size(); j++){
            parcial += A[j];
            if (parcial > maximo){
                maximo = parcial;
            }
        }
    }
    return maximo;
}

int kadane(const std::vector<int>& A){
    int maximo = A[0];
    int parcial = 0;
    for (int i = 0; i < A.size(); i++){
        parcial += A[i];
        if (parcial > maximo){
            maximo = parcial;
        }
        if (parcial < 0){
            parcial = 0;
        }
    }
    return maximo;
}

std::vector<int> generarArreglo(int n){
    std::vector<int> A(n);
    for (int i = 0; i < n; i++){
        A[i] = rand() % 401 - 200;
    }
    return A;
}

double medirTiempo(int (*funcion)(const std::vector<int>&), const std::vector<int>& A){

    auto inicio = std::chrono::high_resolution_clock::now();

    volatile int resultado = funcion(A);

    auto fin = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> tiempo = fin - inicio;

    return tiempo.count();
}

int main(){

    //Implementacion
    srand(42);

    bool correctas = true;
    for (int prueba = 1; prueba <= 100; prueba++){
        int n = 5 + rand() % 46;
        std::vector<int> A = generarArreglo(n);
        int r1 = cubico(A);
        int r2 = cuadratico(A);
        int r3 = kadane(A);

        if (r1 != r2 || r2 != r3){

            std::cout << "ERROR en prueba " << prueba << "\n";
            std::cout << "Cubico:      " << r1 << "\n";
            std::cout << "Cuadratico:  " << r2 << "\n";
            std::cout << "Kadane:      " << r3 << "\n\n";

            correctas = false;
            break;
        }
    }

    if (correctas){
        std::cout << "Las 100 pruebas fueron correctas\n";
    }

    //Medicion 
   /*
        std::vector<int> tamanos = {
        1000,
        2000,
        4000,
        8000,
        10000
    };

    std::cout << std::left
        << std::setw(10) << "N"
        << std::setw(18) << "Cubico"
        << std::setw(18) << "Razon"
        << std::setw(18) << "Cuadratico"
        << std::setw(18) << "Razon"
        << std::setw(18) << "Kadane"
        << std::setw(18) << "Razon"
        << "\n";

    std::cout << std::string(118, '-') << "\n";

    double anteriorCubico = 0;
    double anteriorCuadratico = 0;
    double anteriorKadane = 0;

    for (int n : tamanos){
        std::vector<int> A = generarArreglo(n);

        double tiempoCubico = medirTiempo(cubico, A);

        double tiempoCuadratico = medirTiempo(cuadratico, A);

        double tiempoKadane = medirTiempo(kadane, A);

        double razonCubico = 0;
        double razonCuadratico = 0;
        double razonKadane = 0;

        if (anteriorCubico > 0){
            razonCubico = tiempoCubico / anteriorCubico;
        }

        if (anteriorCuadratico > 0){
            razonCuadratico = tiempoCuadratico / anteriorCuadratico;
        }

        if (anteriorKadane > 0){
            razonKadane = tiempoKadane / anteriorKadane;
        }

        std::cout << std::left
             << std::setw(10) << n
             << std::setw(18) << std::fixed << std::setprecision(6) << tiempoCubico
             << std::setw(18) << razonCubico
             << std::setw(18) << tiempoCuadratico
             << std::setw(18) << razonCuadratico
             << std::setw(18) << tiempoKadane
             << std::setw(18) << razonKadane
             << "\n";

        anteriorCubico = tiempoCubico;
        anteriorCuadratico = tiempoCuadratico;
        anteriorKadane = tiempoKadane;
    }
    */
    srand(42);

    int n = 100000000; // 10^8
    std::vector<int> A = generarArreglo(n);

    double tiempoKadane = medirTiempo(kadane, A);

    std::cout << std::left
              << std::setw(10) << "N"
              << std::setw(18) << "Kadane (s)"
              << "\n";
    std::cout << std::string(28, '-') << "\n";

    std::cout << std::left
              << std::setw(10) << n
              << std::setw(18) << std::fixed << std::setprecision(6) << tiempoKadane
              << "\n";

    return 0;


    return 0;
}