#include "main.h"
/**
 * times_table - prints the 9 times table
 */
void times_table(void)
{
    int n;
    int i;
    int resultat;

    for ( n= 0; n < 10; n++)
    {
        for ( i = 0; i <10; i++)
        {
            resultat = n * i;
            if (resultat >= 10)
            {
                _putchar(resultat / 10 + '0');
                _putchar(resultat % 10 + '0');
            }
            else
            {
            _putchar(resultat + '0');
            }

            if (i > 0)
            {
                _putchar(' ');
                _putchar(' ');
                _putchar(',');
            }

            if (resultat >= 10)
            {
                _putchar(' ');
                _putchar(',');
            }
        }
        
    }
    
}