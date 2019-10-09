#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int FASTESTWAY(int a[][3], int t[][2], int* e, int* x, int n){
    
    //INICIALIZO MIS DOS FILAS
    int f1[n];
    int f2[n];

    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[0][1];

    //CONCATENANDO DATOS QUEMADOS QUE DE ENTRADA SIEMPRE SON ASI
    string p1 = to_string(e[0]) + ", " + to_string(a[0][0]);
    string p2 = to_string(e[0]) + ", " + to_string(a[0][1]);

    for (int j = 1; j < n; j++ ) {
        
        string tempp1 = p1;
        string tempp2 = p2;

        //ACA HAGO MIS COMPARACIONES CON LAS DOS FILAS ENSAMBLADAS

        //FILA 1
        if (f1[j-1] + a[0][j] <= f2[j-1] + t[1][j-1] + a[0][j]) {
            f1[j] = f1[j-1] + a[0][j];
            p1 = tempp1 + " , " + to_string(a[0][j]);
        } else {
            f1[j] = f2[j-1] + t[j-1][1] + a[0][j];
            p2 = tempp2 + " , " + to_string(a[0][j]);
        }

        //FILA 2
        if (f2[j-1] + a[1][j] <= f1[j-1] + t[0][j-1] + a[1][j]){
            f2[j] = f2[j-1] + a[1][j];
            p2 = tempp2 + " , " + to_string(a[1][j]);
        } else {
            f2[j] = f1[j-1] + t[0][j-1] + a[1][j];
            p1 = tempp1 + " , " + to_string(a[1][j]);
        }
    }

//COMPARANDO CUAL DE LAS DOS FILAS TIENE MENOR TIEMPO
//DESPLIEGA LA FILA QUE MAS LE CONVENGA

    if (f1[n-1] + x[0] <= f2[n-1] + x[1]){
        cout << p1 << " , " << x[0];
        printf("\ntiempo:");
        return f1[n-1] + x[0];
    }else{
        cout << p2 << " , " << x[1];
        printf("\ntiempo:");
        return f2[n-1] + x[1];
    }
}

//MAIN

int main(){
    //METEMOS LOS DATOS DE NUESTRA MATRIZ
    int lines[2][3] = {{3,2,4},{4,2,5}};

    //LE DAMOS LOS TIEMPOS
    int times[][2] = {{3,3}, {2,4}};

    //ENTRADAS FIJAS
    int e[] = {2, 3};

    //SALIDAS FIJAS
    int x[] = {1, 2};

    //MANDO A LLAMAR LA FUNCION
    printf("\n%d",FASTESTWAY(lines, times, e, x, 3));
    return 0;
}