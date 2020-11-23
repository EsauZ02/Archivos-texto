/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: esauzavaleta
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int creaArchivo();
int escribirArchivo();
int escrituraAlFinal(); 
int leerArchivo();
int modificacionArchivo();

int main(int argc, char** argv) {

int n, opcion;

    do
    {
        printf( "\n   1. Creacion de archivo");
        printf( "\n   2. Escritura en archivo nuevo" );
        printf( "\n   3. escritura al final en archivo existente");
        printf( "\n   4. lectura de archivo");
        printf( "\n   5. Modificacion de archivo");
        printf( "\n   6. Salir." );
        printf( "\n\n   Introduzca opcion (1-6): ");

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: creaArchivo();
                    break;

            case 2: escribirArchivo();
                    break;

            case 3: escrituraAlFinal();
                    break;
                    
            case 4: leerArchivo();
                    break;
                    
            case 5: modificacionArchivo();
                    break;
         }

       

    } while ( opcion != 6 );

    
    return (EXIT_SUCCESS);
}

int creaArchivo(){
    FILE *fd;
    char direccion[] = "esauzavaleta\\escritorio\\hola.rtf";
	
	fd = fopen(direccion,"w"); 
	if(fd==NULL){
		printf("No se encontro el lugar para crear el archivo");
	}else{
		printf("Archivo creado");
		printf("\nUbicacion: %s",direccion);
	}return 0;

}

int escribirArchivo(){
    FILE *fp;
 	
 	char cadena[] = "Hola como estan.\n";
 	
 	fp = fopen ( "hola.rtf", "r+" );
 	
 	fwrite( cadena, sizeof(char), sizeof(cadena), fp ); 
 	
 	fclose ( fp );
        return 0;
}

int escrituraAlFinal(){
    char cadena1 [] = "hola a todos, espero esten bien.\n";
        
    FILE* fichero;
    fichero = fopen("hola.rtf", "w+");
    fputs(cadena1, fichero);
    fclose(fichero);
    printf("Proceso completado");
    return 0;
}

int leerArchivo(){
    char caracter;
    FILE*archivo;
    
    archivo=fopen("/Users/esauzavaleta/Desktop/hola.rtf", "r");
    
    if(archivo!=NULL){
        printf("");
        
        fscanf(archivo,"%s", &caracter);
        printf("%s", caracter);
        
        
    }else{
        printf("El archivo no existe \n");
    }
    fclose(archivo);
    return 0;
}

int modificacionArchivo(){
    FILE *fp;
 	
 	char buffer[100] = "hola de nuevo.";
 	
 	fp = fopen ( "hola.rtf", "r+" );
 	
 	fprintf(fp, buffer);
 	fprintf(fp, "%s", "\nSeguimos escribiendo en el archivo.");
 	
 	fclose ( fp );
        return 0;
}