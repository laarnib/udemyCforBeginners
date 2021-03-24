#include<stdio.h>

enum Company {
    GOOGLE,
    FACEBOOK,
    XEROX,
    YAHOO = 10,
    EBAY,
    MICROSOFT
};

typedef enum Company Company;

int main(void)
{
    Company xerox = XEROX;
    Company google = GOOGLE;
    Company ebay = EBAY;

    printf("%i\n%i\n%i\n", xerox, google, ebay);

    return 0;
}