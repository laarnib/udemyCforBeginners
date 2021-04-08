#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SLEN 100
typedef struct Item
{
    char * itemName;
    int quantity;
    float price;
    float amount;
}ITEM;

void readItem (ITEM * item);
void printItem (ITEM * item);


int main(void)
{
    ITEM product, *productPtr = NULL;

    productPtr = &product;

    // Allocate memory for itemName
    productPtr->itemName = (char *)malloc(SLEN * sizeof(char));

    readItem(productPtr);
    printItem(productPtr);

    free(productPtr->itemName);

    return 0;
}

// Read item data
void readItem (ITEM * item)
{
    // Get the name of the item
    printf("Product Name: ");
    scanf(" ");
    fgets(item->itemName, SLEN, stdin);

    // Get price
    printf("Price: ");
    scanf(" %f", &item->price);

    // Get quantity
    printf("Quantity: ");
    scanf(" %i", &item->quantity);

    // Calculate the amount
    (*item).amount = (*item).quantity * (*item).price;

    return;
}

// Print items
void printItem (ITEM * item)
{
    printf("\n\n");
    printf("Product Name: %s", item->itemName);
    printf("Quantity: %i\n", item->quantity);
    printf("Price: $%.2f\n", item->price);
    printf("Amount: $%.2f\n", item->amount);
}