#include <stdio.h>
#include <stdlib.h>
#include "minimaxAlum.h"
#include "suma15.h"

int main()
{
    int jugador;  //+1 o -1
    int primero,ganador;
    tNodo *juego=crearNodo(tablero_inicial);
    dispNodo(juego);

    printf("El Agente Inteligente juega con X \n El Jugador Humano con O \n Elige el turno 1:Primero o 2:Segundo ");
    scanf("%d",&primero); printf("\n");
    if (primero==1)
       jugador=-1; // Turno de Min
    else
        jugador=1; // Turno de Max

    ganador=terminal(juego);
    while(juego->vacias>0 && ganador==0){
       if (jugador==1){
    	   //juego=(tNodo *) minimaxLim(juego, jugador);
    	   juego=(tNodo *) poda_ab(juego);
       }else{
    	   //juego=(tNodo *)jugadaAdversario(juego);
    	   //juego=(tNodo *) minimaxLim2(juego, jugador);
    	   juego=(tNodo *) poda_ab2(juego);
       }

       printf("\nN Vacias: %d\n",juego->vacias);
       dispNodo(juego);
       ganador=terminal(juego);
       jugador=opuesto(jugador);// turno del adversario
    }
    switch(ganador){
     case 100:
          printf("\n HE GANADOOOO\n"); break;
     case 0:
           printf("\n EMPATE, vaya tienes que practicar más para poder ganarme ... \n"); break;
     case -100:
          printf("\n Increible pero has ganado tu :(( \n\n"); break;
     default: printf("\n algo ha salido mal en el juego ..\n");
     }


    //system("pause");
    return 0;
}
