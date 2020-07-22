#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

string get_txt(void);
bool len_check(int n);
bool alpha_check(string key, int n);
bool dupe_check(string key, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1; 
    }    
    
    int n = strlen(argv[1]);
    string key = argv[1];
    bool check;
    
    if (len_check(n))
    {
        if (alpha_check(key, n))
        {
            if (dupe_check(key, n))
            {
                check = true;
            }
            else
            {
                printf("No repeated characters\n");
                return 1;
            }
        }
        else
        {
            printf("Only alphabetic characters\n");
            return 1;
        }
    }
    else
    {
        printf("Needs to be 26 characters\n");
        return 1;
    }
    
    if (check)
    {
        string txt = get_txt();
        int m = strlen(txt);
        char cipher[m];
        int index[m];
    
        for (int i = 0; i < m; i++)
        {
            if (isupper(txt[i]))
            {
                index[i] = txt[i] - 65;
                cipher[i] = toupper(key[index[i]]);
            }
            else if (islower(txt[i]))
            {
                index[i] = txt[i] - 97;
                cipher[i] = tolower(key[index[i]]);
            }
            else
            {
                cipher[i] = txt[i];
            }
        }
        
        printf("ciphertext: ");
        for (int j = 0; j < m; j++)
        {
            printf("%c", cipher[j]);
        }
        printf("\n");
        return 0;
    }
}

//get key
string get_txt(void)
{
    string txt = get_string("plaintext: ");
    return txt;
}

//length check
bool len_check(int n)
{
    if (n == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//alphabetic check
bool alpha_check(string key, int n)
{
    bool check;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(key[i]))
        {
            check = true;
        }
        else
        {
            check = false;
            i = n;
        }
    }
    return check;
}

//duplicate check
bool dupe_check(string key, int n)
{
    bool check;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                check = false;
                j = n;
                i = n;
            }
            else
            {
                check = true;
            }
        }
    }
    return check;
}
