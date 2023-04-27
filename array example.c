#include <stdio.h>
#include <stdlib.h>


int main()
{
    int eleman_number;
    int sum = 0;
     int array[eleman_number];

    printf("eleman sayısı gir: ");
    scanf("%d", &eleman_number);
    
   
    
    printf("elemanları gir:\n");
    for (int i = 0; i < eleman_number; i++)
    {
        scanf("%d", &array[i]);
        sum += array[i];
    }
    
    printf("toplam: %d\n", sum);
    
    return 0;
}
