/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float em_milimetros(float valor){
    return valor * 25.4;
}

int main(){
    float e_polegadas, s_milimetro;
    printf("Digite um valor em polegadas: ");
    scanf("%f",&e_polegadas);
    printf("%.2f mm\n",em_milimetros(e_polegadas));
    return 0;
}
