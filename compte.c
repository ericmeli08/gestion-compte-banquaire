#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "compte.h"

void attente(double j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()

{
    int choix;
    FILE *file;

    file=fopen("clients.txt","a+");
    newacc:
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2  AJOUTER UN CLIENT  \xB2\xB2\xB2\xB2");

    printf("\n\n\nEntrez le numero du compte:");
    scanf("%d",&check.acc_no);
    while(fscanf(file,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Numero de compte deja utilise !");
            attente(1000000000);
                goto newacc;
            }
    }
    add.acc_no=check.acc_no;
        
    printf("\nEntrer le nom:");
    scanf("%s",add.name);
    printf("\nEntrez la date d'anniversaire(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(file,"%d %s %d/%d/%d %d %s %s %.0lf %s %.0f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);

    fclose(file);
    printf("\nAccount created successfully!");
    new_invalid:
    printf("\n\n\n\t\tEntrez 1 pour aller au menu principale et  0 pour sortir: ");
    choix=getch();
    system("cls");
    if (choix=='1')
        menu();
    else if(choix=='0')
            close();
    else
        {
            printf("\nInvalid!\a");
            goto new_invalid;
        }
}
void view_list()
{
    FILE *list;
    int choix;
    list=fopen("clients.txt","r");
    int test=0;
    system("cls");
    printf("\nNo COMPTE\t    NAME\t\tADDRESSE\t\t     PHONE\n");

    while(fscanf(list,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%9d\t %7s\t\t%8s\t\t%10.0lf",add.acc_no,add.name,add.address,add.phone);
           test=1;
       }

    fclose(list);
    if (test==0)
        {   system("cls");
            printf("\nAUCUN COMPTE!!\n");
        }

        list_invalid:
    printf("\n\n\n\t\tEntrez 1 pour aller au menu principale et  0 pour sortir: ");
    choix=getch();
    system("cls");
    if (choix=='1')
        menu();
    else if(choix=='0')
            close();
    else
        {
            printf("\nInvalid!\a");
            goto list_invalid;
        }
}
void edit(void)
{
    int choice,choix,test=0;
    FILE *old,*new;
    old=fopen("clients.txt","r");
    new=fopen("new.txt","w");

    printf("\nEntrez le numero de compte du client dont tu veux changer les infos:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nquel info tu veux changer?\n1.Addresse\n2.Phone\n\nEntrez votre choice(1 pour addresse and 2 pour phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Entrez la nouvelle addresse:");
                scanf("%s",upd.address);
                fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Changement effectuer!");
                }
            else if(choice==2)
                {
                    printf("Entrez le nouveau numero de phone:");
                scanf("%lf",&upd.phone);
                fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                system("cls");
                printf("Entrez la nouvelle addresse");
                }

        }
        else
            fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
    }
    fclose(old);
    fclose(new);
    remove("clients.txt");
    rename("new.txt","clients.txt");

if(test!=1)
        {   system("cls");
            printf("\nAUCUN COMPTE!!\a\a\a");
        }
            edit_invalid:
printf("\n\n\n\t\tEntrez 1 pour aller au menu principale et  0 pour sortir: ");
 choix=getch();
    system("cls");
    if (choix=='1')
        menu();
    else if(choix=='0')
            close();
    else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
}

void transact(void)
{   
    int choice,choix,test=0;
    FILE *old,*new;
    old=fopen("clients.txt","r");
    new=fopen("new.txt","w");

    printf("\nEntrez le numero de compte du client dont tu veux changer les infos:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmp(add.acc_type,"fixed1")==0||strcmp(add.acc_type,"fixed2")==0||strcmp(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nTU NE PEUX PAS DEPOSER OU RETIRER DE L'ARGENT!!!!!");
                    attente(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nQue veux-tu ?\n1.Deposit\n2.Withdraw\n\nEntrez votre choice(1 pour deposit et 2 pour withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
            }
   }
   fclose(old);
   fclose(new);
   remove("clients.txt");
   rename("new.txt","clients.txt");
   if(test!=1)
   {
       printf("\n\nAUCUN COMPTE!!");
   }
       transact_invalid:
printf("\n\n\n\t\tEntrez 1 pour aller au menu principale et  0 pour sortir: ");
 choix=getch();
    system("cls");
    if (choix=='1')
        menu();
    else if(choix=='0')
            close();
    else
        {
            printf("\nInvalid!\a");
            goto transact_invalid;
        }

}
void erase(void)
{
    int choix,test=0;
    FILE *old,*new;
    old=fopen("clients.txt","r");
    new=fopen("new.txt","w");

    printf("\nEntrez le numero de compte du client dont tu veux supprimer les infos:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);

        else
            {test=1;
            printf("\nCompte supprimer successfully!\n");
            }
   }
 fclose(old);
   fclose(new);
   remove("clients.txt");
   rename("new.txt","clients.txt");
   if(test!=1)
   {
       printf("\n\nAUCUN COMPTE!!");
   }
       erase_invalid:
printf("\n\n\n\t\tEntrez 1 pour aller au menu principale et  0 pour sortir: ");
 choix=getch();
    system("cls");
    if (choix=='1')
        menu();
    else if(choix=='0')
            close();
    else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }

}

void see(void)
{
    FILE *file;
    int test=0;
    int choix;
    file=fopen("clients.txt","r");

    printf("\nEntrez votre numero de compte: ");    
        scanf("%d",&check.acc_no);

        while (fscanf(file,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nnumero de compte:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddresse:%s \nCitizenship:%s \nPhone number:%lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
            }
        }
    fclose(file);
     if(test!=1)
   {
       printf("\n\nAUCUN COMPTE!!");
   }
       see_invalid:
printf("\n\n\n\t\tEntrez 1 pour aller au menu principale et  0 pour sortir: ");
 choix=getch();
    system("cls");
    if (choix=='1')
        menu();
    else if(choix=='0')
            close();
    else
        {
            printf("\nInvalid!\a");
            goto see_invalid;
        }
}


void close(void)
{
    system("color C");
    printf("\n\n\n\n\t\t\t\tCE PROJET EN C A ETE DEVELOPPER PAR MELI ERIC !\n\n\n");
    for (int t=0;t<=9;t++)
    {
       attente(199999999);
       printf(".");
    }

     system("cls");
     system("color 7");
}


void menu(void)
{   int choix;
    system("cls");
    system("color 9");
    mistake:
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.cree un nouveau compte\n\t\t2.Modifier un compte existant\n\t\t3.pour une transaction\n\t\t4.verifier les infos d'un compte\n\t\t5.Supprimer un compte\n\t\t6.Voir la liste des clients\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    choix=getch();

    system("cls");
    switch(choix)
    {
        case '1':new_acc();
        break;
        case '2':edit();
        break;
        case '3':transact();
        break;
        case '4':see();
        break;
        case '5':erase();
        break;
        case '6':view_list();
        break;
        case '7':close();
        break;
        default:
            printf("\n INVALIDE !\a");
            attente(1000000);
            goto mistake;


    }



}