#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
//#include <exprtk.hpp>


        // Aproximarea unei integrale folosind metoda trapezelor


    // Functia integralei

double f(double x)
{
    return(1/(x+1));
}

    // Functie de verificare input

double Validare(const char *prompt)
{
    double var;
    char input[100];
    bool esteValid = false;

    do
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%lf", &var) == 1)
        {
            esteValid = true;
        }
        else
        {
            printf("Input invalid. Te rog sa introduci un numar.\n\n");
        }
    } while (!esteValid);
    printf("\n");
    return var;
}

int main()
{
    // Input

    double a, b, e;

    a = Validare("Introduceti limita inferioara a intervalului: ");
    b = Validare("Introduceti limita superioara a intervalului: ");
    e = Validare("Introduceti precizia: ");


    // Initializare
    double n = 1;


    // Aproximare initiala
    double II, IO, h, s, i;
    II = ((f(a)+f(b)) * (b-a))/2 ;


    // Rafinare aproximare
    do
    {
        n  = 2500*n;
        h = (b-a)/n ;
        IO = II;
        s = 0;
        for(i=1; i<=n-1; i++)
        {
            s = s + f(a+i*h);
        }
        II = ( f(a) + 2*s + f(b) ) * h/2 ;
    }while( fabs(II-IO) <= e );


    // Output
    printf("Valoarea integralei, obtinuta cu precizia %f este %f", e, II);
}