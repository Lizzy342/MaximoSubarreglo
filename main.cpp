#include <iostream>
#include <vector>

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


int main(){
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

    return 0;
}