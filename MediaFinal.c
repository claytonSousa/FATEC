/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float em_media(float p1, float p2, float t){
    return ((p1*0.3)+(p2*0.5)+(t*0.2));
}

int main(){
    float e_prova1,e_prova2,e_trabalho, s_media;
    printf("Nota P1: ");
    scanf("%f",&e_prova1);
    printf("Nota P2: ");
    scanf("%f",&e_prova2);
    printf("Nota Trabalho: ");
    scanf("%f",&e_trabalho);
    //s_milimetro = 100 * e_metro;
    return 0;
}