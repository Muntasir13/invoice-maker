#include <stdio.h>
#include <string.h>
char account()
{
    char a[50], b[35], c[8], d[17], q[20], f[30], g[30], p[30], k, address[80], company[50];
    int h, i;
    FILE *fp;
    char j;
    printf ("First name: ");
    gets(a);
    printf ("Last name: ");
    scanf ("%s",b);
    printf ("Sex: ");
    scanf ("%s",c);
    printf ("Nationality: ");
    scanf("%s%c",d,&k);
    printf ("Date of birth: ");
    memset (q,0,20);
    scanf ("%s%c",q,&k);
    printf ("Email address: ");
    scanf ("%s",f);
    printf ("Password: ");
    scanf ("%s",g);
    printf ("(Alternative) mobile number: ");
    scanf ("%d%c",&h,&k);
    printf ("Now, we would like you to give us the name of the company under which you are going to make the invoices.\n");
    gets(company);
    printf ("Address of the company: ");
    gets (address);
    fp=fopen ("company.txt","w");
    fprintf (fp,"\t\t\t\t");
    fprintf (fp,company);
    fprintf (fp,"\n");
    fprintf (fp,"\t\t");
    fprintf (fp,address);
    fprintf (fp,"\n\n");
    fclose (fp);
    strcpy (p,f);
    strcat (p,g);
    strcat (p,".txt");
    fp = fopen (p,"w");
    fputs ("\t\tPERSONAL INFORMATION:\n\n",fp);
    fputs ("Name: ",fp);
    fputs (a,fp);
    fputs (" ",fp);
    fputs (b,fp);
    fputs ("\n",fp);
    fputs ("Sex: ",fp);
    fputs (c,fp);
    fputs ("\n",fp);
    fputs ("Nationality: ",fp);
    fputs (d,fp);
    fputs ("\n",fp);
    fputs ("Date of birth: ",fp);
    fputs (q,fp);
    fputs ("\n",fp);
    fputs ("Email address: ",fp);
    fputs (f,fp);
    fputs ("\n",fp);
    fputs ("Mobile number: ",fp);
    fprintf (fp,"+880 ");
    fprintf (fp,"%d",h);
    fputs ("\n",fp);
    fputs ("\t\tINFORMATION ABOUT THE COMPANY:\n\n",fp);
    fputs (company,fp);
    fputs ("\n",fp);
    fputs (address,fp);
    fputs ("\n",fp);
    fclose (fp);
}
void invoice(char date[20], char f[30], char sumt[50], char summ[50])
{
    char account_of[50], address1[80], notify[50], no[50], address2[80], tel[20], invoice_no[25], sales[25];
    char portl[30], portd[30], transport[12], item[100];
    char i, c[11], co[11], pr[10], print[10];
    int j, x, y=0, k;
    float z, sumtotal1=0.00, sumtotal2=0.00;
    struct descrip
    {
        char style_no[8];
        int qty, gkg, nkg, car1, car2;
        float cbm, usd;
    }container[100];
    int cartotal=0, qtytotal=0, gkgtotal=0, nkgtotal=0;
    float cbmtotal=0.0, usdtotal=0.0;
    FILE *fp, *fn;
    printf ("Invoice no.: ");
    scanf ("%s",invoice_no);
    scanf ("%c",&i);
    printf ("SALES CONTRACT NO: ");
    scanf ("%s",sales);
    scanf ("%c",&i);
    printf ("ON ACCOUNT & RISK OF:\n");
    gets (account_of);
    printf ("Address: ");
    gets (address1);
    printf ("NOTIFY:\n");
    gets (notify);
    printf ("Address: ");
    gets (address2);
    printf ("TEL: ");
    scanf ("%s",tel);
    scanf ("%c",&i);
    printf ("TYPE OF ITEM: ");
    gets (item);
    printf ("PORT OF LOADING: ");
    gets (portl);
    printf ("PORT OF DELIVERY: ");
    gets (portd);
    printf ("SHIPED BY S.S: ");
    gets (transport);
    printf ("\n\n\nFrom here, the invoice making starts:\n");
    for (j=1;;j++)
    {
        printf ("CARTON NO.: ");
        scanf ("%d%c%d",&container[j].car1,&i,&container[j].car2);
        scanf ("%c",&i);
        cartotal=cartotal+(container[j].car2-container[j].car1)+1;
        printf ("STYLE NO.: ");
        gets (container[j].style_no);
        printf ("QTY/DOZ: ");
        scanf ("%d",&container[j].qty);
        qtytotal+=container[j].qty;
        printf ("PRICE USD/DOZEN: ");
        scanf ("%f",&container[j].usd);
        usdtotal=usdtotal+(container[j].usd*container[j].qty);
        printf ("CBM: ");
        scanf ("%f",&container[j].cbm);
        cbmtotal+=container[j].cbm;
        printf ("G.W.KGS: ");
        scanf ("%d",&container[j].gkg);
        scanf ("%c",&i);
        gkgtotal+=container[j].gkg;
        printf ("N.W.KGS: ");
        scanf ("%d",&container[j].nkg);
        scanf ("%c",&i);
        nkgtotal+=container[j].nkg;
        printf ("TYPE 'END' TO END MAKING INVOICES\n");
        strcpy (c,"END");
        scanf ("%s",co);
        scanf ("%c",&i);
        x=strcmpi (c,co);
        if (x==0)
        {
            strcpy (no,notify);
            strcat (no," ");
            strcat (no,date);
            strcat (no,".txt");
            fp=fopen (no,"w");
            fn=fopen ("company.txt","r");
            while ((i=fgetc (fn))!=EOF)
            {
                fprintf (fp,"%c",i);
            }
            fclose (fn);
            fputs ("INVOICE NO: ",fp);
            fputs (invoice_no,fp);
            fputs ("                                         DT: ",fp);
            fputs (date,fp);
            fputs ("\n",fp);
            fputs ("SALES CONTRACT NO: ",fp);
            fputs (sales,fp);
            fputs ("\n\n",fp);
            fputs ("ON ACCOUNT & RISK OF :\n",fp);
            fputs (account_of,fp);
            fputs ("\n",fp);
            fputs (address1,fp);
            fputs ("\n\n",fp);
            fputs ("NOTIFY:\n",fp);
            fputs (notify,fp);
            fputs ("\n",fp);
            fputs (address2,fp);
            fputs ("\n",fp);
            fputs ("TEL: ",fp);
            fputs (tel,fp);
            fputs ("\n\nMARKS & NUMBER:\n",fp);
            fputs ("CARTON NO.\n",fp);
            for (k=1;k<=j;k++)
            {
                fprintf (fp,"%d-%d",container[k].car1,container[k].car2);
                fputs (" STYLE NO # ",fp);
                fputs (container[k].style_no,fp);
                fputs ("\n",fp);
            }
            fputs ("\n",fp);
            fputs ("INVOICE OF        : ",fp);
            fprintf (fp,"%d CARTON %d DOZEN PAIR OF %s\n",cartotal,qtytotal,item);
            fputs ("PORT OF LOADING   : ",fp);
            fputs (portl,fp);
            fputs ("\n",fp);
            fputs ("PORT OF DELIVERY  : ",fp);
            fputs (portd,fp);
            fputs ("\n",fp);
            fputs ("SHIPED PER S.S.   : ",fp);
            fputs (transport,fp);
            fputs ("\n\n",fp);
            fputs ("SL.NO.    CARTON NO.    TOTAL CARTON    STYLE NO.     QTY/DOZ   CBM    G.W.KGS   N.W.KGS\n",fp);
            for (k=1;k<=j;k++)
            {
                if (container[k].car1<100)
                {
                    fprintf (fp,"  %d.        %d-%d            %d        ",k,container[k].car1,container[k].car2,container[k].car2-container[k].car1+1);
                    fputs (container[k].style_no,fp);
                    fprintf (fp,"         %d   %.4f   %d     %d\n",container[k].qty,container[k].cbm,container[k].gkg,container[k].nkg);
                }
                else if (container[k].car1<1000)
                {
                    fprintf (fp,"  %d.        %d-%d           %d        ",k,container[k].car1,container[k].car2,container[k].car2-container[k].car1+1);
                    fputs (container[k].style_no,fp);
                    fprintf (fp,"         %d     %.4f   %d     %d\n",container[k].qty,container[k].cbm,container[k].gkg,container[k].nkg);
                }
            }
            fputs ("\n",fp);
            fputs ("SALES CONTRACT NO: ",fp);
            fputs (sales,fp);
            fputs ("\n",fp);
            fputs ("CONTAINER OF ",fp);
            fputs (item,fp);
            fputs ("\n",fp);
            fputs ("AS PER PROFORMA INVOICE NO: ",fp);
            fputs (invoice_no,fp);
            fputs (" DATE: ",fp);
            fputs (date,fp);
            fputs ("\n\n",fp);
            fputs ("STYLE       QTY/DZ PAIR     PRICE USD/DOZEN         TOTAL PRICE\n",fp);
            for (k=1;k<=j;k++)
            {
                fputs (container[k].style_no,fp);
                fputs ("        ",fp);
                fprintf (fp,"%d               $ %.2f               ",container[k].qty,container[k].usd);
                fprintf (fp,"$ %.2f\n",container[k].qty*container[k].usd);
            }
            fputs ("\nTOTAL:              ",fp);
            fprintf (fp,"%d DZ PAIR                  US$ %.2f\n\n",qtytotal,usdtotal);
            fprintf (fp,"TOTAL QUANTITY    : %d DOZEN PAIR\n",qtytotal);
            fprintf (fp,"GROSS WEIGHT      : %d KGS\n",gkgtotal);
            fprintf (fp,"NET WEIGHT        : %d KGS\n",nkgtotal);
            fprintf (fp,"TOTAL CARTON      : %d CARTONS\n",cartotal);
            fputs ("\n",fp);
            fputs ("------------------------------------------------------------------------------------------\n",fp);
            fputs ("\t\t\t\tINVO",fp);
            fclose (fp);
            sumtotal1+=usdtotal;
            sumtotal2+=usdtotal;
            fp=fopen (sumt,"r");
            fn=fopen ("sample.txt","w");
            while ((i=fgetc(fp))!=EOF)
            {
                fprintf (fn,"%c",i);
            }
            fclose (fp);
            fclose (fn);
            fp=fopen (sumt,"w");
            fn=fopen ("sample.txt","r");
            while ((i=fgetc(fn))!=EOF)
            {
                fprintf (fp,"%c",i);
            }
            fseek (fn,24,SEEK_SET);
            while ((fscanf (fn,"%f",&z))!=EOF)
            {
                sumtotal1=sumtotal1+z;
            }
            fseek (fp,24,SEEK_SET);
            fprintf (fp,"%.2f",sumtotal1);
            fclose (fp);
            fclose (fn);
            fp=fopen (summ,"r");
            fn=fopen ("sample.txt","w");
            while ((i=fgetc(fp))!=EOF)
            {
                fprintf (fn,"%c",i);
            }
            fclose (fp);
            fclose (fn);
            fp=fopen (summ,"w");
            fn=fopen ("sample.txt","r");
            while ((i=fgetc(fn))!=EOF)
            {
                fprintf (fp,"%c",i);
            }
            fseek (fn,28,SEEK_SET);
            while ((fscanf (fn,"%f",&z))!=EOF)
            {
                sumtotal2=sumtotal2+z;
            }
            fseek (fp,28,SEEK_SET);
            fprintf (fp,"%.2f",sumtotal2);
            fclose (fp);
            fclose (fn);
            printf ("If you want to see the invoice created, type 'PRINT'\n");
            strcpy (print,"PRINT");
            scanf ("%s%c",pr,&i);
            k=strcmpi (pr,print);
            if (k==0)
            {
                fp=fopen (no,"r");
                while ((i=fgetc(fp))!=EOF)
                    putchar (i);
                fclose (fp);
            }
            break;
        }
        else
            continue;
    }
}
void tutoriala()
{
    printf ("\n");
    printf ("If you want to start the process of making invoices, just type START THE DAY\n");
    printf ("If you want to stop the process of making invoices, just type STOP FOR THE DAY\n");
    printf ("If you want to see the sum total of the day, type SUM TOTAL OF TODAY\n");
    printf ("If you want to see the sum total of the month, type SUM TOTAL OF MONTH\n");
    printf ("If you want to see the grad sheet of a certain month, type REPORT OF [the month]\n");
    printf ("N.B.- for going to the next invoice making, simply type NEXT\n");
    printf ("\n");
}
void program(char f[30], char date[20], char sumt[50], char summ[50]);
int main()
{
    char l;
    FILE *fp;
    int i, j, k;
    char sign[20], cr[15], log_in[8], f[30], g[30], tutorial[11], tu[11], date[20], sumt[50], summ[50];
    printf ("\t\t\t\tWELCOME TO INVO\n");
    printf ("\t\t\texpertise in export and import business\n");
    printf ("If you don't have an account, simply type 'SIGN UP' to create an account or simply LOG IN to log in\n\n");
    strcpy (cr,"SIGN UP");
    strcpy (log_in,"LOG IN");
    gets (sign);
    i=strcmpi (cr,sign);
    j=strcmpi (log_in,sign);
    if (i==0)
    {
        printf ("Firstly, your personal information:\n");
        account();
        printf ("\n\t\tCONGRATULATIONS!!! Your account has been created\n");
        printf ("At first, we would like you to go through the tutorials. For that just type, TUTORIAL\n");
        strcpy (tutorial,"TUTORIAL");
        scanf ("%s",tu);
        k=strcmpi (tu,tutorial);
        if (k==0)
            tutoriala();
    }
    else if (j==0)
    {
        printf ("Email address: ");
        scanf ("%s",f);
        printf ("Password: ");
        scanf ("%s%c",g,&l);
        strcat (f,g);
        strcat (f,".txt");
        fp = fopen(f,"r");
        if (fp==NULL)
        {
            printf ("USERNAME OR PASSWORD IS INVALID\n");
            while (1)
            {
                printf ("Email address: ");
                scanf ("%s",f);
                printf ("Password: ");
                scanf ("%s%c",g,&l);
                strcat (f,g);
                strcat (f,".txt");
                fp = fopen(f,"r");
                if (fp==NULL)
                {
                    printf ("USERNAME OR PASSWORD IS INVALID\n");
                    continue;
                }
                else
                {
                    fclose(fp);
                    printf ("\t\t\t\tYOU ARE LOGGED IN\n\n");
                    printf ("\t\t\t   Hello, ");
                    fp=fopen (f,"r");
                    fseek(fp,33,SEEK_SET);
                    while ((l=fgetc(fp))!='\n')
                        putchar(l);
                    fclose(fp);
                    printf ("\n");
                    printf ("Please, type today's date: ");
                    memset (date,0,50);
                    scanf ("%s%c",date,&l);
                    strcpy (sumt,"SUM TOTAL OF ");
                    strcat (sumt,date);
                    strcat (sumt,".txt");
                    fp=fopen (sumt,"w");
                    fprintf (fp,"SUM TOTAL OF TODAY: US$ 0.00");
                    fclose (fp);
                    strcpy (summ,"SUM TOTAL OF THE MONTH OF ");
                    if (date[3]=='0' && date[4]=='1')
                        strcat (summ,"JANUARY");
                    else if (date[3]=='0' && date[4]=='2')
                        strcat (summ,"FEBRUARY");
                    else if (date[3]=='0' && date[4]=='3')
                        strcat (summ,"MARCH");
                    else if (date[3]=='0' && date[4]=='4')
                        strcat (summ,"APRIL");
                    else if (date[3]=='0' && date[4]=='5')
                        strcat (summ,"MAY");
                    else if (date[3]=='0' && date[4]=='6')
                        strcat (summ,"JUNE");
                    else if (date[3]=='0' && date[4]=='7')
                        strcat (summ,"JULY");
                    else if (date[3]=='0' && date[4]=='8')
                        strcat (summ,"AUGUST");
                    else if (date[3]=='0' && date[4]=='9')
                        strcat (summ,"SEPTEMBER");
                    else if (date[3]=='1' && date[4]=='0')
                        strcat (summ,"OCTOBER");
                    else if (date[3]=='1' && date[4]=='1')
                        strcat (summ,"NOVEMBER");
                    else if (date[3]=='1' && date[4]=='2')
                        strcat (summ,"DECEMBER");
                    strcat (summ,".txt");
                    program(f,date,sumt,summ);
                    break;
                }
            }
        }
        else
        {
            fclose(fp);
            printf ("\t\t\t\tYOU ARE LOGGED IN\n\n");
            printf ("\t\t\t   Hello, ");
            fp=fopen (f,"r");
            fseek(fp,33,SEEK_SET);
            while ((l=fgetc(fp))!='\n')
                putchar(l);
            fclose(fp);
            printf ("\n");
            printf ("Please, type today's date: ");
            memset (date,0,50);
            scanf ("%s%c",date,&l);
            strcpy (sumt,"SUM TOTAL OF ");
            strcat (sumt,date);
            strcat (sumt,".txt");
            fp=fopen (sumt,"w");
            fprintf (fp,"SUM TOTAL OF TODAY: US$ 0.00");
            fclose (fp);
            strcpy (summ,"SUM TOTAL OF THE MONTH OF ");
            if (date[3]=='0' && date[4]=='1')
                strcat (summ,"JANUARY");
            else if (date[3]=='0' && date[4]=='2')
                strcat (summ,"FEBRUARY");
            else if (date[3]=='0' && date[4]=='3')
                strcat (summ,"MARCH");
            else if (date[3]=='0' && date[4]=='4')
                strcat (summ,"APRIL");
            else if (date[3]=='0' && date[4]=='5')
                strcat (summ,"MAY");
            else if (date[3]=='0' && date[4]=='6')
                strcat (summ,"JUNE");
            else if (date[3]=='0' && date[4]=='7')
                strcat (summ,"JULY");
            else if (date[3]=='0' && date[4]=='8')
                strcat (summ,"AUGUST");
            else if (date[3]=='0' && date[4]=='9')
                strcat (summ,"SEPTEMBER");
            else if (date[3]=='1' && date[4]=='0')
                strcat (summ,"OCTOBER");
            else if (date[3]=='1' && date[4]=='1')
                strcat (summ,"NOVEMBER");
            else if (date[3]=='1' && date[4]=='2')
                strcat (summ,"DECEMBER");
            strcat (summ,".txt");
            program(f,date,sumt,summ);
        }
    }
    return 0;
}
void program(char f[30], char date[20], char sumt[50], char summ[50])
{
    char start[16], stop[20], sum_month[30], sum_day[50], report[21], info[7], tutorial [12], next[7], EXIT[10];
    strcpy (start,"START THE DAY");
    strcpy (stop,"STOP FOR THE DAY");
    memset (sum_day,0,50);
    strcpy (sum_day,"SUM TOTAL OF TODAY");
    memset (sum_month,0,30);
    strcpy (sum_month,"SUM TOTAL OF THE MONTH");
    strcpy (report,"REPORT OF");
    strcpy (info,"INFO");
    strcpy (tutorial,"TUTORIAL");
    strcpy (next,"NEXT");
    strcpy (EXIT,"EXIT");
    char all[50], c;
    int i, x, j, m, n, o, p, r, s, k, l;
    FILE *fp;
    while (1)
    {
        printf ("\nSTART THE DAY\t INFO\t   TUTORIAL   SUM TOTAL OF TODAY   SUM TOTAL OF THE MONTH\t   EXIT\n");
        gets (all);
        i=strcmpi (all,start);
        m=strcmpi (all,sum_month);
        n=strcmpi (all,sum_day);
        o=strcmpi (all,report);
        p=strcmpi (all,info);
        r=strcmpi (all,tutorial);
        l=strcmpi (all,EXIT);
        if (i==0)
        {
            invoice(date,f,sumt,summ);
            printf ("\n\n\n");
            while (1)
            {
                printf ("\nNEXT\t   TUTORIAL   SUM TOTAL OF TODAY   SUM TOTAL OF THE MONTH   STOP FOR THE DAY\n");
                gets (all);
                j=strcmpi (all,stop);
                m=strcmpi (all,sum_month);
                n=strcmpi (all,sum_day);
                o=strcmpi (all,report);
                r=strcmpi (all,tutorial);
                s=strcmpi (all,next);
                if (s==0)
                {
                    invoice(date,f,sumt,summ);
                    printf ("\n\n\n");
                }
                else if (m==0)
                {
                    printf ("\n");
                    fp=fopen (summ,"r");
                    while ((c=fgetc (fp))!=EOF)
                        putchar (c);
                    fclose (fp);
                    printf ("\n\n\n\n");
                }
                else if (n==0)
                {
                    printf ("\n");
                    fp=fopen (sumt,"r");
                    while ((c=fgetc (fp))!=EOF)
                        putchar (c);
                    fclose (fp);
                    printf ("\n\n\n\n");
                }
                else if (j==0)
                {
                    break;
                }
                else if (r==0)
                {
                    tutoriala();
                    printf ("\n\n\n");
                }
            }
        }
        else if (p==0)
        {
            printf ("\n");
            fp = fopen (f,"r");
            while ((c=getc(fp))!=EOF)
                putchar(c);
            printf ("\n\n\n\n");
        }
        else if (n==0)
        {
            printf ("\n");
            fp=fopen (sumt,"r");
            while ((c=fgetc (fp))!=EOF)
                putchar (c);
            fclose (fp);
            printf ("\n\n\n\n");
        }
        else if (m==0)
        {
            printf ("\n");
            fp=fopen (summ,"r");
            while ((c=fgetc (fp))!=EOF)
                putchar (c);
            fclose (fp);
            printf ("\n\n\n\n");
        }
        else if (r==0)
        {
            tutoriala();
            printf ("\n\n\n");
        }
        else if (l==0)
        {
            break;
        }
    }
}
