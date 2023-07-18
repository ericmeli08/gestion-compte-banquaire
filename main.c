#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "compte.h"


int main()
{
    char pass[10],password[10]="melieric";
    int i=0,choix,user,No,caractere;
    again:
    system("cls");
    printf("\n\n\t\t LOGIN :\n\n\t\t\t1. USER\n\n\t\t\t2. ADMINISTRATOR");
    printf("\n\n\t\tQuel est votre choix : ");
    user=getch();
    if (user!='1' && user!='2') 
    {
        printf("\n\t\tInvalid ! \a");
        attente(999999999);
        goto again;
    }
    system ("cls");

    if (user=='2')
    {
        printf("\n\n\t\tEntrez le mot de passe pour vous connecter:");

        do{

            caractere = getch();
            if (caractere==13) 
                break;
            else if( caractere == 8)
                printf("\b \b");
            else {
                printf("*");
                pass[i++]=caractere;
            }
        }while(1);


        printf("\nLOADING");
        for(i=0;i<7;i++)
            {
                attente(444444444);
                printf(".");
            }

        if (strcmp(pass,password)==0)
            {
                system("cls");
                system("color A");
                printf("\n\n\tPassword Match!\n\n");
                printf("\t\t\t\xB2\xB2\xB2 BIENVENE MONSIEUR MELI ERIC \xB2\xB2\xB2");
            
            attente(1000000000);
            attente(1000000000);
            attente(1000000000);
                
                    system("cls");
                menu();
            }
        else
            {   printf("\n\nMot de passe incorrect!!\a");
                login:
                printf("\nEnter 1 pour reessayer et 0 pour exit:");
                scanf("%d",&choix);
                if (choix==1)
                        {
                            system("cls");
                            main();
                        }

                else if (choix==0)
                        {
                        system("cls");
                        close();
                        }
                else{
                        printf("\nInvalid!\a");
                        attente(1000000000);
                        system("cls");
                        goto login;
                        }
            }
    }
    else
    {
        printf("\n\n\t\t1. Voir vos informations\n\n\t\t2. Changer vos informations\n\n\n    Quel est votre choix ? ");
        int c=getch();
        if (c =='1')
            see();
        else 
            edit();
                back:
                printf("\nEnter 1 pour reessayer et 0 pour exit:");
                choix=getch();
                if (choix=='1')
                        {
                            system("cls");
                            main();
                        }

                else if (choix=='0')
                        {
                        system("cls");
                        close();}
                else
                        {printf("\nInvalid!\a");
                        attente(1000000000);
                        system("cls");
                        goto back;}
    }   
    
        return 0;
}
