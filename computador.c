#include <stdio.h>

int main() {

int cant_docu = 0;
int cant_imag = 0;
int cant_video = 0;
int cant_programa = 0;
int cap_disco = 0;

float tam_docu = 0.0;
float tam_imag = 0.0;   
float tam_video = 0.0;
float tam_programa = 0.0;

/*SE INGRESA LA CANTIDAD DE DOCUMENTOS,IMAGENES,VIDEOS Y PROGRAMAS*/
printf("Ingresa la cantidad de documentos: ");
scanf("%d", &cant_docu);

printf("Ingresa la cantidad de imagenes: ");
scanf("%d", &cant_imag);

printf("Ingresa la cantidad de videos: ");
scanf("%d", &cant_video);

printf("Ingresa la cantidad de programas: ");
scanf("%d", &cant_programa);

printf("Ingrese la capacidad del disco duro en GB: ");
scanf("%d", &cap_disco);

/*SE INGRESA EL TAMAÑO DE DOCUMENTOS,IMAGENES,VIDEOS Y PROGRAMAS EN MB*/
printf("Ingrese el tamaño de documentos en MB: ");
scanf("%f", &tam_docu);

printf("Ingrese el tamaño de imagenes en MB: ");
scanf("%f", &tam_imag);

printf("Ingrese el tamaño de videos en MB: ");
scanf("%f", &tam_video);

printf("Ingrese el tamaño de programas en MB: ");
scanf("%f", &tam_programa);

float espacio_documentos, espacio_imagenes, espacio_videos, espacio_programas;
espacio_documentos = cant_docu * tam_docu;
espacio_imagenes = cant_imag * tam_imag;
espacio_videos = cant_video * tam_video;
espacio_programas = cant_programa * tam_programa;

float espacio_total = 0.0;
espacio_total = espacio_documentos + espacio_imagenes + espacio_videos + espacio_programas;
float GB_usados;
GB_usados = espacio_total / 1024;
float porcentaje;
porcentaje = ((GB_usados / cap_disco) * 100);

printf("El espacio de los documentos es: %.2f MB\n", espacio_documentos);
printf("El espacio de las imagenes es: %.2f MB\n", espacio_imagenes);
printf("El espacio de los videos es: %.2f MB\n", espacio_videos);
printf("El espacio de los programas es: %.2f MB\n", espacio_programas);
printf("El espacio total utilizado es: %.2f MB\n", espacio_total);
printf("El porcentaje de almacenamiento utilizado es: %.2f%%\n", porcentaje);
printf("Los GB usados son: %.2f GB\n", GB_usados);
printf("La capacidad del disco duro es: %d GB\n", cap_disco);


}
