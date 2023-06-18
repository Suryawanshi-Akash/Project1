#include<stdio.h>

int Arithmatic(int No1, char Sign, int No2 )
{
    int Ans = 0;

    switch(Sign)
    {
        case'+':
            Ans = No1 + No2;
            break;

        case'-':
            Ans = No1 - No2;
            break;

        case'*':
            Ans = No1 * No2;
            break;

        case'/':
            Ans = No1 / No2;
            break;

        default:
            printf("Upadte the calculator \n");
    }
    return Ans;
}


int main()
{
    int Value1 = 0;
    int Value2 = 0;
    char Operator = '\0';
    int iRet = 0;

    printf("Enter the Arithmatic Sign : \n");
    scanf("%c",&Operator);

    printf("Enter the first Number : \n");
    scanf("%d",&Value1);

    printf("Enter the Second Number : \n");
    scanf("%d",&Value2);

    iRet = Arithmatic(Value1,Operator,Value2);

    printf("The Answer is : %d", iRet);


    return 0;
}