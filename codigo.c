#include <stdio.h>

void main (){
    float C1 = 0.0;
    float C2 = 0.0;
    float C3 = 0.0;
    float NL= 0.0;
    float NC= 0.0;
    float NF= 0.0;

    printf("Ingrese la nota del primer certamen:\n");
    scanf("%f", &C1);

    printf("Ingrese la nota del segundo certamen:\n");
    scanf("%f", &C2);

    printf("Ingrese la nota de laboratorio:\n");
    scanf("%f", &NL);

    C3= ((3*(60-(NL * 0.3))) / 0.7) - C1 - C2;
    NC= (C1 + C2 + C3) / 3;
    NF= (NC * 0.7) + (NL * 0.3); 

    printf("La nota minima que debes sacar en el tercer certamen es: %.2f\n", C3);

    printf("Su promedio de certamenes es: %.2f\n", NC);
    printf("Su nota final es:%.2f /100\n", NF);
}
