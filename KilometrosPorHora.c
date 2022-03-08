/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float em_kilometro_por_hora(float ms){
    return (ms*3.6);
}

int main(){
    float e_metros_segundos, s_kilometros_por_hora;
    printf("Digite uma velocidade em m/s: ");
    scanf("%f",&e_metros_segundos);
    printf("%.2f km/h\n",em_kilometro_por_hora(e_metros_segundos));
    return 0;
}