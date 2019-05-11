/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ignacio
 *
 * 
 */
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

/*
 * 
 */

int* Crea_Vector(int* origen, int principio, int final)
    {   
        int* subvector;
        int aux=0; 
        int tamaño;
        //int i;
        tamaño=final-inicio;
        subvector=(int*)malloc(tam* sizeof(int));
        
        for(int i=inicio;i<final;i++)
        { 
            *(subvector+auxiliar)=*(origen+i);
            aux= aux+1;
        }
        
        return subvector;
    }
    
    void mostrar(int nombre_proceso, int tam_subvector, int* subvector)
    {
        //int i;
        cout << "Sub Vector: " << nombre_proceso);
	    for (int i=0;i<tam_subvector;++i)
            {
		cout << *(sub_vector+i);
	    }
    }

    
    float promedio(int vector[],int suma,int largo)
    {
   
        for (int i=0; i<largo ; i++)
        {
        vector[i]=rand(); // se asignan valores random al vector
        suma=vector[i] + suma;
        cout << "Elemento" << "[" << i << "]" << ":" << vector[i] << endl;
        promedio=suma/largo;
        return promedio;
        }
    }
    
    
int main(int argc, char** argv) {
    
    int largo=100000; // se define el largo del vector
    int vector[largo];
    int opcion;
    float suma=0;
    float promedio=0;
    float var=0;
    float varianza=0;
    float desv_std=0;
    
     srand(time(NULL));
    
    int num_procesos; 
    int nombre_proceso; 
    int vector[largo];
    int* subvector=NULL;
    int tam_subvector;
    
    MPI_Init(NULL, NULL); //iniciando MPI
    MPI_Comm_size(MPI_COMM_WORLD, &num_procesos);
    MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);    
    tam_subvector = tamaño/num_procesos;

    
    

    
    
    
    
    
    cout << "Mostrando elementos del vector:  \n" << endl;
    
    
    
    
    if (nombre_proceso!=0) 
    {
		
        subvector=(int*)malloc(tam_subvector * sizeof(int));
	MPI_Recv(subvector,tam_subvector,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	mostrar(nombre_proceso,tam_subvector,subvector);
	cout << "El Promedio del subvector del proceso es: " << nombre_proceso,promedio(subvector,tam_subvector));
    } 
    
    for (int i=1;i<num_procesos;i++) 
    {
        sub_vector=Crea_Vector(i*tam_subvector,(i*tam_subvector)+tam_subvector,vector);
	MPI_Send(sub_vector,tam_subvector,MPI_INT,i,0,MPI_COMM_WORLD);
    }
    
    subvector=Crea_Vector(0,num_subvector,vector);
    mostrar(nombre_proceso,tam_subvector,subvector);	
    cout <<"El promedio del subvector es: "<< nombre_proceso,promedio(subvector,tam_subvector));
    
    MPI_Finalize();
    
    
    
    for(int i=0; i<largo; i++)
    {
        var= pow((vector[i]-promedio),2) + var;
    }
                  
    varianza=(var/largo);   
    desv_std=sqrt(varianza);
}                   
    
    
    /*cout << "-------------------------------------------------------------------" << endl;
    
    while(opcion!=4)
    {
        cout << "" << endl;
        cout << "Menu de Opciones \n" << endl;
        cout << " Opcion 1: Promedio de los elementos del vector \n";
        cout << " Opcion 2: Varianza de los elementos del vector \n ";
        cout << "Opcion 3: Desviacion Estandar de los elementos del vector \n";
        cout << " Opcion 4: Salir \n";
    
        cout << " Seleccione una opcion: ";
        cin >> opcion;
    
        
        while(opcion > 4 or opcion < 1)
        {
            cout << " Error: Opcion ingresada no valida \n";
            cout << " Seleccione una opcion: ";
            cin >> opcion;
        }
        
    
        switch(opcion)
        {
    
            case 1: cout << " El promedio de los elementos del vector es: " << promedio << endl;
                    break;
        
            case 2: cout << " La varianza de los elementos del vector es: " << varianza << endl;;
                    break;
        
            case 3: cout << " La desviacion estandar de los elementos del vector es: " <<  desv_std << endl;
                    break;
        
            
        }
    
     
   
    }
    
     }
