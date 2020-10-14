#import<stdio.h>
#import<cs50.h>

int temp[20];
long num;
int c, tsum, sum, sum2, n, n1, z, x, count = 0;

int main(void)
{     
    do
    {
        num = get_long("NUMBER:\n");
    }
    while (num < 0);
    long k = num;
    /*determining the length and second element of the given number.*/
    while (k > 10)
    {   
        z = k % 10;
        k = k / 10;
        count += 1;
    }
    count += 1;
    /*determining length and loding individual numbers into an array for implementing Luhn's Algorithm*/
    for (c = 0; c < count; c++)
    {
        /*determining the first digit*/
        x = num % 10;
        /*if the length of the card number is even*/
        if (count % 2 == 0)
        {
            temp[c] = num % 10;
            /*printf("arrr==%d",temp[c]);*/
            num = num / 10;     
            if (c % 2 != 0)
            {   
                n = temp[c] * 2;
                if (n > 9)
                {   
                    sum = sum + n % 10 + 1;
                }
                else
                {
                    sum = sum + n;
                }                    
            }
            else 
            {  
                sum2 = sum2 + temp[c];
            }
                
        }
        /*if the length of the card number is odd*/
        else
        {
            temp[c] = num % 10;
            /*printf("arrr==%d",temp[c]);*/
            num = num / 10;     
            if (c % 2 != 0)
            {   
                n = temp[c] * 2;
                if (n > 9)
                {   
                    sum = sum + n % 10 + 1;
                }
                else
                {
                    sum = sum + n; 
                }
            }
            else 
            {  
                sum2 = sum2 + temp[c];
                            
            }
        }
    }
    tsum = sum + sum2;
    if (tsum % 10 == 0)
    {  
        /*American Express numbers start with 34 or 37 and having a length of 15*/
        if ((z == 4 || z == 7) && x == 3 && count == 15)
        {   
            printf("AMEX\n");
        }
        /*MasterCard numbers start with 51, 52, 53, 54, or 55 and having a length of 16*/
        else if ((x == 5) && ((z == 5 || z == 4 || z == 3 || z == 2 || z == 1)) && (count == 16))
        { 
            printf("MASTERCARD\n");
        }
        /*VISA numbers start with 4 and having a length of either 13 or 15*/
        else if ((x == 4) && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        /*If the sum%10 is 0 but not satisfying the card length then its INVALID*/
        else
        {
            printf("INVALID\n");
        }
    }
    /*if the sum id not ending with 0, it dosent satisfy Luhn's algorithm.*/
    else 
    {
        printf("INVALID\n");
    }
}
