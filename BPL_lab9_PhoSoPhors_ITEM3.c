//
// Subject                  : BPL - Lab 9
// Department ans Class     : ITE-M3
// Instrutor                : Dr. Kor SokChea
// Name                     : Pho SoPhors
//

#include<stdio.h>
#define MAX 20

void create(int set[])      // Option 1 (Craete set A and B)
    {
        int num, i, x;
        set[0] = 0;

        scanf("%d", &num);
        printf("    => Enter elements of set : ");
        
        for(i = 1; i <= num; i++)
            scanf("%d", &set[i]);
                set[0] = num;
    }

void  Output(int set[])     // Option 2 (Output set A and B)
    {
        int i, num;
        num = set[0];

        for(i = 1; i <= num; i++)
        printf("%d  ", set[i]);
    }

int member(int set[],int x)
    {
        int i, num;
        num = set[0];

        for(i = 1; i <= num; i++)
            if(x == set[i])
            return(1);
        return(0);
    }

void Union(int setA[], int setB[], int setC[], int setD[])   // Option 3 (Union of set)
    {
        int i, num;
        setC[0] = 0;

//Union of setA, setB = setA + (setB - setA)
        num = setA[0];
        for(i = 0; i <= num; i++)
            setC[i] = setA[i];

        num = setB[0];
        for(i = 1; i <= num; i++)
            if(!member (setC, setB[i]))
                setC[++setC[0]] = setB[i]; 
    }

void Intersection(int setA[], int setB[], int setC[], int setD[]) // Option 4 (Intersection of set)
    {
        int i, num;
        setC[0] = 0; 
        
        num = setA[0];
        for(i = 1; i <= num; i++)
            if(member   (setB, setA[i]))
                setC[++setC[0]] = setA[i];
    }

 void set_difference (int setA[], int setB[], int setC[], int setD[]) // Option 5 (set difference of set)
    {
        int i, num;
        setC[0] = 0;
        setD[0] = 0;

//Calculate setA - setB
        
        num = setA[0];
        for(i = 1;i <= num; i++)
            if(!member (setB, setA[i]))
                setC[++setC[0]] = setA[i]; 

//Calculate setB - setA

        num = setB[0];
        for(i = 1 ; i <= num; i++)
            if(!member(setA, setB[i]))
                setD[++setD[0]] = setB[i];
    }

int main()
    {
        int setA[MAX], setB[MAX], setC[MAX], setD[MAX];
        int x, options;

        setA[0] = setB[0] = setC[0] = 0;

        do{
            printf("\n\n+========= Welcome to BPL Lab 9 =========+\n");
            printf("\n\t1. Create.\n\t2. Output set A and B.\n\t3. Union\n\t4. Intersection.");
            printf("\n\t5. Set Difference\n\t6. Exit Program.");

            printf("\n\t+=> Chooes one options : ");
            scanf("%d", &options);
            printf("+=======================================+\n");

            switch(options){
                case 1: printf("\nEnter number of element of set A : ");
                        create(setA);
                        printf("\nEnter number of element of set B : ");
                        create(setB);   break;

                case 2: printf("\nNUMBER OF SET A IS : ");
                        Output(setA);
                        printf("\nNUMBER OF SET B IS : ");
                        Output(setB);   break;

                case 3: Union(setA, setB, setC, setD);
                        printf("\n=> (𝑨 ∪ 𝑩) = { x|x€A or x€B } \n");
                        printf("\nYOUR UNION (𝑨 ∪ 𝑩) IS : ");
                        Output(setC);   break;

                case 4: Intersection(setA, setB, setC, setD);
                        printf("\n=> (𝑨 ∩ 𝑩) = { x|x€A & x€B } \n");
                        printf("\nYOUR INTERSECTION (𝑨 ∩ 𝑩) IS : ");
                        Output(setC);   break;

                case 5: set_difference(setA, setB, setC, setD);
                        printf("\nYOUR DIFFERENCE ( A - B ) IS : ");
                        Output(setC);
                        printf("\nYOUR DIFFERENCE ( B - A ) IS : ");
                        Output(setD);   break;
                }
        }
        while(options != 6);
 }
