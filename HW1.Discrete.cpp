#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void PrimeF(int number)
{
    int flag;
    for (int i = 1; i <= number; i++)
    {
        flag = 0;
        if (number % i == 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (i % j == 0)    flag=1;
            }
            if (flag == 1)
                cout << "\nThe Factor is=" << number;
        }
    }
}

void chinese(int a1[10], int a2[10])
{
    int  md[10], mmod[10];
    int M = 1, Y = 0;

    cout << "Enter the number of equations=";
    int n;
    cin >> n;

    for (int i = 0;i < n;i++)
    {  
        for (int i = 0;i < n;i++)
        {
            M = M * a2[i];
        }

        cout << "\nM = " << M;

        for (int i = 0;i < n;i++)
        {
            md[i] = M / a2[i];
            cout << "\nmd" << i << "= " << md[i];
        }

        for (int i = 0;i < n;i++)
        {
            mmod[i] = md[i] % a2[i];
            cout << "\nmd" << i << " The inverse is= " << mmod[i];
        }

        for (int i = 0;i < n;i++)
        {
            Y = Y + (a1[i] * md[i] * mmod[i]);
            cout << Y << "=" << Y << "+" << "(" << a1[i] << "*" << md[i] << "*" << mmod[i] << ")";
        }
        cout << "\n\nY = " << Y;
        Y = Y % M;
        cout << "\n\nx=" << Y;
    }

}
    int gcd(int a, int b, int* x, int* y)
    {
        if (a == 0)
        {
            *x = 0, * y = 1;
            return b;
        }

        int xx, yy;
        int gcdd = gcd(b % a, a, &xx, &yy);
        *x = yy - (b / a) * xx;
        *y = xx;
        return gcdd;
    }
    void Inv(int a, int b)
    {
        int c, w, result;
        int gcd1 = gcd(a, b, &c, &w);
        if (gcd1 != 1)
            cout << "There is no inverse.";
        else
        {
            result = (c % b + b) % b;
            cout << "The inverse is " << result;
        }
    }


    int main()
    {

        FILE* fp = NULL;
        char f[10] = {};
        int Q1[4] = {};
        int Q2a[4] = {};
        int Q2b[4] = {};
        int Q3[2] = {};
        
        cout << "Please write the name of file:" << endl;
        cin >> f;
        if ((fp = fopen(f, "r")) == NULL)
        {
            printf("cannot open the file.\n");
            exit(1);
        }

        for (int i = 0; i < 4;i++)
        {
            fscanf(fp, "%d", &Q1[i]);
        }

        for (int i = 0; i <= 3;i++)
        {
            fscanf(fp, "%d", &Q2a[i]);
        }
        for (int i = 0; i < 4;i++)
        {
            fscanf(fp, "%d", &Q2b[i]);
        }

        for (int i = 0; i < 2;i++)
        {
            fscanf(fp, "%d", &Q3[i]);
        }

         //cout << Q1[0] << "\n";
         //cout << Q2a[0] << "\n" << Q2a[1] << "\n" << Q2a[2] << "\n" << Q2a[3] << "\n";
        //cout << Q2b[0] << "\n" << Q2b[1] << "\n" << Q2b[2] << "\n" << Q2b[3] << "\n";
         //cout << Q3[0] << "\n";

        cout << ".............THE LIST..............\n\n";
        cout << "    Please enter the number:\n\n";
        cout << "1- Find the prime factorization.\n";
        cout << "2- The Chinese Remainder Theorem.\n";
        cout << "3- Find an inverse of a modulo b.\n\n";
        cout << "The number:";
        int number;
        cin >> number;
        cout << "\n";

        switch (number)
        {
        case 1:  cout << "\nThe question is (Find the prime factorization).\n\n";
            int nn;
            cout << "which the num of value of the group of num in the file? ";
            cin >> nn;
            PrimeF(Q1[nn]);
            break;


        case 2:   cout << "\nThe question is (The Chinese Remainder Theorem).\n";

            chinese(Q2a,Q2b); 
            break;


        case 3:   cout << "\nThe question is (Find an inverse of a modulo b).\n";
           
            Inv(Q3[1],Q3[2]);
            break;
        }

    }



