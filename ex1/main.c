/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp;
    int  a[] = {0,1,2};
    int ra[3];
    char b[] = "ABC";
    char rb[4]; 
    float c[] = {1.1,1.2,1.3};
    float rc[3];
    
    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(a), 1, fp);
    fwrite(b, sizeof(b), 1, fp);
    fwrite(c, sizeof(c), 1, fp);
    fseek(fp, 0, SEEK_SET);
    fread(ra,sizeof(a), 1, fp);
    fread(rb,sizeof(b), 1, fp);
    fread(rc,sizeof(c), 1, fp);
    for (int i = 0; i < 3; i++){
        printf("%d", ra[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++){
        printf("%c", (char)(rb[i]));
    }
    printf("\n");
    for (int i = 0; i < 3; i++){
        printf("%f", rc[i]);
    }
    fclose(fp);
    return 0;
}
