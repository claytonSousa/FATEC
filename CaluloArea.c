/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
float s_area;
void em_area(float b, float a){
    s_area = (b*a);
}

int main(){
    float e_base, e_altura;
    
    printf("Vamos calcular a área de um quadrado\nEntre com um valor para a base: ");
    scanf("%f",&e_base);
    printf("\nEntre com um valor para a altura: ");
    scanf("%f",&e_altura);
    em_area(e_base,e_altura);
    printf("A área é %.2f unidades quadradas\n",s_area);
    return 0;
}