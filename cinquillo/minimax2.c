#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cinquillo.h"
#include "minimax.h"
tNodo *PSEUDOminimax(tNodo *t) {
    tJugada mejorJ,J;
    mejorJ.num=-8; mejorJ.palo=-2;  //uno cualquiera
    int puntos = -2;
    int temp;
    tNodo *intento=malloc(sizeof(tNodo));
    printf("\n Mi turno: \n");
    for( J.palo= 0; J.palo < P; ++J.palo){
        for(J.num=0; J.num<N; ++J.num){
            if (esValida(t,MAX,J)) {
                intento=aplicaJugada(t,MAX,J); //Intenta jugada
                temp =terminal(intento); // Calcula el valor minimax
                if(temp > puntos) {
                    puntos = temp;
                    //actualizar mejor Jugada
                }
            }
        }}//fors
    t=aplicaJugada(t,MAX,mejorJ);
    return t;
}




tNodo *jugadaAdversario(tNodo *t) {
     tJugada jugada;
     int valida=0;
    dispNodo(t,MIN);
     printf("\n Introduce tu jugada (pon Palo 8 Numero 8, si pasas )");
     do {
        printf("\nJugada.Palo 0-Oros  1-Bastos ([0..1])?: ");
        scanf("%d", &jugada.palo);
        printf("\n Jugada.Numero [1..10])?: ");
        scanf("%d", &jugada.num);
        jugada.num=jugada.num-1;  //internamente se guardan de 0 a 9
        
         if (jugada.palo==8){
             printf("\n Pasas ...... \n");
             valida=1;
         }
         else {
             valida=esValida(t,MIN,jugada);
             if (!valida)
                 printf("\n  Intenta otra carta, esta no se puede o no la tienes \n");
             else {
                 dispJugada(jugada,MIN);
                 t=aplicaJugada(t,MIN,jugada);}
         }
        printf("\n");
     } while (!valida);
     return t;
}

