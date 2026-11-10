/* ==========================================================================
   PROYECTO DE ALGEBRA LINEAL: NOTAS DE ESTUDIANTES CON MATRICES

   Datos:
     - 5 estudiantes y 3 unidades (matrices A1, A2, A3).
     - Cada matriz tiene 5 filas (estudiantes) y 3 columnas (actividades).
     - Columnas: Deberes, Lecciones, Proyectos.

   Vector de equivalencias:
     e = [0.30, 0.30, 0.40]

   Pasos (uno por opcion del menu):
     1. Datos: las tres matrices de notas.
     2. A1*e, A2*e, A3*e: cada nota multiplicada por su equivalencia.
     3. Notas por unidad: suma de las filas de cada matriz del paso 2.
     4. Suma de las unidades: U1 + U2 + U3  (matriz de 5x1).
     5. Promedio final: cada valor de la suma dividido para 3.

     Estudiante: Ana Cristina Piedra Pitizaca
     Fecha: 08/11/2026
   ========================================================================== */

#include <stdio.h>

/* ----------------------------- CONSTANTES ------------------------------- */
#define N_EST 5   /* numero de estudiantes (filas)    */
#define N_ACT 3   /* numero de actividades (columnas) */
#define N_UNI 3   /* numero de unidades (matrices)    */

/* ------------------------------- DATOS ---------------------------------- */
const char *NOMBRE_ACT[N_ACT] = {"Deberes", "Lecciones", "Proyectos"};

/* e = vector de equivalencias (debe sumar 1) */
double e[N_ACT] = {0.30, 0.30, 0.40};

/* A[unidad][estudiante][actividad] */
double A[N_UNI][N_EST][N_ACT] = {
    /* Unidad 1 -> A1 */
    { {8, 9, 7}, {6, 7, 8}, {9, 8, 10}, {5, 6, 7}, {10, 9, 9} },
    /* Unidad 2 -> A2 */
    { {7, 8, 9}, {8, 6, 7}, {9, 9, 8},  {6, 5, 6}, {9, 10, 10} },
    /* Unidad 3 -> A3 */
    { {9, 10, 8}, {7, 8, 9}, {10, 9, 9}, {7, 6, 8}, {8, 9, 10} }
};

/* ======================= FUNCIONES DE IMPRESION ========================== */

void imprimir_linea(void) {
    printf("--------------------------------------------------------------\n");
}

void imprimir_titulo(const char *texto) {
    printf("\n");
    imprimir_linea();
    printf("%s\n", texto);
    imprimir_linea();
}

void imprimir_equivalencias(void) {
    printf("Equivalencias (e): ");
    for (int j = 0; j < N_ACT; j++) {
        printf("%s = %.2f", NOMBRE_ACT[j], e[j]);
        if (j < N_ACT - 1) printf("  |  ");
    }
    printf("\n");
}

/* Imprime una matriz de N_EST x N_ACT con encabezados de actividades */
void imprimir_matriz(double M[N_EST][N_ACT]) {
    printf("%-10s", "");
    for (int j = 0; j < N_ACT; j++) printf("%14s", NOMBRE_ACT[j]);
    printf("\n");

    for (int i = 0; i < N_EST; i++) {
        printf("Est. %-5d", i + 1);
        for (int j = 0; j < N_ACT; j++) printf("%14.2f", M[i][j]);
        printf("\n");
    }
}

/* ============================== CALCULOS ================================= */

/* Paso 2: R = A[u] * e  (cada nota multiplicada por la equivalencia de su columna) */
void calcular_matriz_por_e(int u, double R[N_EST][N_ACT]) {
    for (int i = 0; i < N_EST; i++)
        for (int j = 0; j < N_ACT; j++)
            R[i][j] = A[u][i][j] * e[j];
}

/* Paso 3: notas por unidad = suma de las filas de A[u]*e  ->  N[u][i] */
void calcular_notas_unidad(double N[N_UNI][N_EST]) {
    double R[N_EST][N_ACT];
    for (int u = 0; u < N_UNI; u++) {
        calcular_matriz_por_e(u, R);
        for (int i = 0; i < N_EST; i++) {
            N[u][i] = 0;
            for (int j = 0; j < N_ACT; j++) N[u][i] += R[i][j];
        }
    }
}

/* Paso 4: suma de las unidades  ->  S[i] = U1 + U2 + U3 */
void calcular_suma_unidades(double S[N_EST]) {
    double N[N_UNI][N_EST];
    calcular_notas_unidad(N);
    for (int i = 0; i < N_EST; i++) {
        S[i] = 0;
        for (int u = 0; u < N_UNI; u++) S[i] += N[u][i];
    }
}

/* ======================== OPCIONES DEL MENU ============================== */

/* Opcion 1: datos (las tres matrices de notas) */
void opcion_datos(void) {
    imprimir_titulo("PASO 1: DATOS (5 estudiantes, 3 unidades)");
    imprimir_equivalencias();
    for (int u = 0; u < N_UNI; u++) {
        printf("\nMatriz A%d (Unidad %d)\n", u + 1, u + 1);
        imprimir_matriz(A[u]);
    }
}

/* Opcion 2: A1*e, A2*e, A3*e */
void opcion_matrices_por_e(void) {
    double R[N_EST][N_ACT];

    imprimir_titulo("PASO 2: CADA MATRIZ POR SU EQUIVALENCIA (A * e)");
    imprimir_equivalencias();
    for (int u = 0; u < N_UNI; u++) {
        calcular_matriz_por_e(u, R);
        printf("\nA%d*e  (cada nota de A%d por su equivalencia)\n", u + 1, u + 1);
        imprimir_matriz(R);
    }
}

/* Opcion 3: notas por unidad (suma de las filas de A*e) */
void opcion_notas_unidad(void) {
    double N[N_UNI][N_EST];
    calcular_notas_unidad(N);

    imprimir_titulo("PASO 3: NOTAS POR UNIDAD (suma de las filas de A*e)");
    printf("\n%-10s", "");
    for (int u = 0; u < N_UNI; u++) printf("%14s%d", "Unidad ", u + 1);
    printf("\n");
    for (int i = 0; i < N_EST; i++) {
        printf("Est. %-5d", i + 1);
        for (int u = 0; u < N_UNI; u++) printf("%15.2f", N[u][i]);
        printf("\n");
    }
}

/* Opcion 4: suma de las unidades 1, 2 y 3 (matriz de 5x1) */
void opcion_suma_unidades(void) {
    double N[N_UNI][N_EST], S[N_EST];
    calcular_notas_unidad(N);
    calcular_suma_unidades(S);

    imprimir_titulo("PASO 4: SUMA DE LAS UNIDADES (U1 + U2 + U3)");
    printf("\n");
    for (int i = 0; i < N_EST; i++) {
        printf("Est. %d:  %.2f + %.2f + %.2f = %.2f\n",
               i + 1, N[0][i], N[1][i], N[2][i], S[i]);
    }
}

/* Opcion 5: promedio final (cada valor de la suma dividido para 3) */
void opcion_promedio_final(void) {
    double S[N_EST];
    calcular_suma_unidades(S);

    imprimir_titulo("PASO 5: PROMEDIO FINAL (suma / 3)");
    printf("\n");
    for (int i = 0; i < N_EST; i++) {
        printf("Est. %d:  %.2f / %d = %.2f\n", i + 1, S[i], N_UNI, S[i] / N_UNI);
    }
}

/* ================================ MENU =================================== */

void mostrar_menu(void) {
    printf("\n==============================================================\n");
    printf("                PROYECTO DE MATRICES: NOTAS\n");
    printf("==============================================================\n");
    printf("  1. Datos (las tres matrices de notas)\n");
    printf("  2. Matrices A1*e, A2*e, A3*e\n");
    printf("  3. Notas por unidad (suma de las filas)\n");
    printf("  4. Suma de las unidades (U1 + U2 + U3)\n");
    printf("  5. Promedio final (suma / 3)\n");
    printf("  0. Salir\n");
    printf("--------------------------------------------------------------\n");
    printf("Elija una opcion: ");
}

int main(void) {
    int opcion = -1;

    do {
        mostrar_menu();

        if (scanf("%d", &opcion) != 1) {
            /* entrada no numerica: se limpia el buffer y se vuelve a pedir */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            if (c == EOF) break;
            opcion = -1;
        }

        switch (opcion) {
            case 1: opcion_datos();           break;
            case 2: opcion_matrices_por_e();  break;
            case 3: opcion_notas_unidad();    break;
            case 4: opcion_suma_unidades();   break;
            case 5: opcion_promedio_final();  break;
            case 0: printf("\nPrograma finalizado.\n"); break;
            default: printf("\nOpcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}
