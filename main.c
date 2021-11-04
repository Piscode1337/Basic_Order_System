/*
 * @Title: Basic Order System
 * Course: CCC101 Computer Programming I (Prelim Exam Part 2)
 * @Author: Princetoniño B. Piscos - CCC101 B182
 * @Date: 11/03/21 10:45:18 GMT +08:00
 */

#include <stdio.h>
#include <stdbool.h>

double item_A_price = 3400.00;
double item_B_price = 1024.00;
double item_C_price = 240.50;
double item_D_price = 2019.00;
double item_E_price = 9500.00;

void printValues(double itemPrice, int itemAmount, bool isBundle, int bundleNum)
{
    double getTotalAmount;
    double getDiscount;
    if (itemAmount == 2 && !isBundle)
    {
        getTotalAmount = itemPrice * itemAmount;
        getDiscount = getTotalAmount * 0.15;

        printf("Total Purchase: %.2lf Php (x%d)\nTotal Discount: %.2lf Php (15%%)\nTotal: %.2lf Php", getTotalAmount, itemAmount, getDiscount, getTotalAmount - getDiscount);
    }

    if (itemAmount == 3 && !isBundle)
    {
        getTotalAmount = itemPrice * itemAmount;
        getDiscount = getTotalAmount * 0.18;

        printf("Total Purchase: %.2lf Php (x%d)\nTotal Discount: %.2lf Php (18%%)\nTotal: %.2lf Php", getTotalAmount, itemAmount, getDiscount, getTotalAmount - getDiscount);
    }

    if (isBundle && bundleNum == 1)
    {
        getTotalAmount = (item_A_price * 1) + (item_B_price * 2);
        getDiscount = getTotalAmount * 0.16;

        printf("Total Purchase: %.2lf Php (x%d)\nTotal Discount: %.2lf Php (16%%)\nTotal: %.2lf Php", getTotalAmount, itemAmount, getDiscount, getTotalAmount - getDiscount);
    }

    if (isBundle && bundleNum == 2)
    {
        getTotalAmount = (item_C_price * 1) + (item_A_price * 1) + (item_E_price * 1);
        getDiscount = getTotalAmount * 0.16;

        printf("Total Purchase: %.2lf Php (x%d)\nTotal Discount: %.2lf Php (16%%)\nTotal: %.2lf Php", getTotalAmount, itemAmount, getDiscount, getTotalAmount - getDiscount);
    }
}

void askInput(double item_price, int item_qty, bool isBundle, int bundleNum)
{
    scanf(" %d", &item_qty);
    printValues(item_price, item_qty, isBundle, bundleNum);
}

int main()
{
    int amount_item_1 = 0, amount_item_2 = 0, amount_item_3 = 0, amount_item_4 = 0, amount_item_5 = 0, amount_itemBundle_1 = 1, amount_itemBundle_2 = 1;

    char initBundleResponse;
    char chooseBundle1;
    char chooseBundle2;

    char browseResponse;

    do
    {
        int options = 0;

        printf("--------------------------------------------------------------------------------------------|\n");
        printf("If you buy 3 of the same item, you'll get an 18%% discount on its total price.               |\n");
        printf("If you buy 2 of the same item, you'll get a 15%% discount.                                   |\n");
        printf("If you purchase in bundles, you'll get a 16%% discount per bundle:                           |\n");
        printf("[Bundle 1: Item_A (x1) + Item_B (x2)], [Bundle 2: Item_C (x1) + Item_A (x1) + Item_E (x1)]. |\n");
        printf("--------------------------------------------------------------------------------------------|\n");

        printf("--Options--|\n");
        printf("[1] Item A |\n");
        printf("[2] Item B |\n");
        printf("[3] Item C |\n");
        printf("[4] Item D |\n");
        printf("[5] Item E |\n");
        printf("-----------|\n");

        printf("Enter Item number you would like to order: ");
        scanf("%d", &options);
        if (options)
        {
            switch (options)
            {
                case 1:
                    printf("Would you like to purchase bundle instead? (Y/N)\n> ");
                    scanf(" %c", &initBundleResponse);

                    if (initBundleResponse == 'Y' || initBundleResponse == 'y')
                    {
                        printf("Bundle 1 offers Item_A (x1) & Item_B (x2). Do you like Bundle 1 instead? (Y/N)\n> ");
                        scanf(" %c", &chooseBundle1);
                        if (chooseBundle1 == 'Y' || chooseBundle1 == 'y')
                        {
                            printValues(0, amount_itemBundle_1, true, 1);
                        }

                        if (chooseBundle1 == 'N' || chooseBundle1 == 'n')
                        {
                            printf("Bundle 2 offers Item_C (x1) & Item_A (x1) & Item_E (x1). Do you like Bundle 2 instead? (Y/N)\n> ");
                            scanf(" %c", &chooseBundle2);
                            if (chooseBundle2 == 'Y' || chooseBundle2 == 'y')
                            {
                                printValues(0, amount_itemBundle_2, true, 2);
                            } else {

                                printf("How many [Item A] would you like to order?\n> ");
                                askInput(item_A_price, amount_item_1, false, 0);
                            }
                        }
                    } else {

                        printf("How many [Item A] would you like to order?\n> ");
                        askInput(item_A_price, amount_item_1, false, 0);
                    }
                break;
                case 2:
                    printf("Would you like to purchase bundle instead? (Y/N)\n> ");
                    scanf(" %c", &initBundleResponse);

                    if (initBundleResponse == 'Y' || initBundleResponse == 'y')
                    {
                        printf("Bundle 1 offers Item_A (x1) & Item_B (x2). Do you like Bundle 1 instead? (Y/N)\n> ");
                        scanf(" %c", &chooseBundle1);
                        if (chooseBundle1 == 'Y' || chooseBundle1 == 'y')
                        {
                            printValues(0, amount_itemBundle_1, true, 1);
                        }

                        if (chooseBundle1 == 'N' || chooseBundle1 == 'n')
                        {
                            printf("Bundle 2 offers Item_C (x1) & Item_A (x1) & Item_E (x1). Do you like Bundle 2 instead? (Y/N)\n> ");
                            scanf(" %c", &chooseBundle2);
                            if (chooseBundle2 == 'Y' || chooseBundle2 == 'y')
                            {
                                printValues(0, amount_itemBundle_2, true, 2);
                            } else {

                                printf("How many [Item B] would you like to order?\n> ");
                                askInput(item_B_price, amount_item_2, false, 0);
                            }
                        }
                    } else {

                        printf("How many [Item B] would you like to order?\n> ");
                        askInput(item_B_price, amount_item_2, false, 0);
                    }
                break;
                case 3:
                    printf("Would you like to purchase bundle instead? (Y/N)\n> ");
                    scanf(" %c", &initBundleResponse);

                    if (initBundleResponse == 'Y' || initBundleResponse == 'y')
                    {
                        printf("Bundle 1 offers Item_A (x1) & Item_B (x2). Do you like Bundle 1 instead? (Y/N)\n> ");
                        scanf(" %c", &chooseBundle1);
                        if (chooseBundle1 == 'Y' || chooseBundle1 == 'y')
                        {
                            printValues(0, amount_itemBundle_1, true, 1);
                        }

                        if (chooseBundle1 == 'N' || chooseBundle1 == 'n')
                        {
                            printf("Bundle 2 offers Item_C (x1) & Item_A (x1) & Item_E (x1). Do you like Bundle 2 instead? (Y/N)\n> ");
                            scanf(" %c", &chooseBundle2);
                            if (chooseBundle2 == 'Y' || chooseBundle2 == 'y')
                            {
                                printValues(0, amount_itemBundle_2, true, 2);
                            } else {

                                printf("How many [Item C] would you like to order?\n> ");
                                askInput(item_C_price, amount_item_3, false, 0);
                            }
                        }
                    } else {

                        printf("How many [Item C] would you like to order?\n> ");
                        askInput(item_C_price, amount_item_3, false, 0);
                    }
                break;
                case 4:
                    printf("Would you like to purchase bundle instead? (Y/N)\n> ");
                    scanf(" %c", &initBundleResponse);

                    if (initBundleResponse == 'Y' || initBundleResponse == 'y')
                    {
                        printf("Bundle 1 offers Item_A (x1) & Item_B (x2). Do you like Bundle 1 instead? (Y/N)\n> ");
                        scanf(" %c", &chooseBundle1);
                        if (chooseBundle1 == 'Y' || chooseBundle1 == 'y')
                        {
                            printValues(0, amount_itemBundle_1, true, 1);
                        }

                        if (chooseBundle1 == 'N' || chooseBundle1 == 'n')
                        {
                            printf("Bundle 2 offers Item_C (x1) & Item_A (x1) & Item_E (x1). Do you like Bundle 2 instead? (Y/N)\n> ");
                            scanf(" %c", &chooseBundle2);
                            if (chooseBundle2 == 'Y' || chooseBundle2 == 'y')
                            {
                                printValues(0, amount_itemBundle_2, true, 2);
                            } else {

                                printf("How many [Item D] would you like to order?\n> ");
                                askInput(item_D_price, amount_item_4, false, 0);
                            }
                        }
                    } else {

                        printf("How many [Item D] would you like to order?\n> ");
                        askInput(item_D_price, amount_item_4, false, 0);
                    }
                break;
                case 5:
                    printf("Would you like to purchase bundle instead? (Y/N)\n> ");
                    scanf(" %c", &initBundleResponse);

                    if (initBundleResponse == 'Y' || initBundleResponse == 'y')
                    {
                        printf("Bundle 1 offers Item_A (x1) & Item_B (x2). Do you like Bundle 1 instead? (Y/N)\n> ");
                        scanf(" %c", &chooseBundle1);
                        if (chooseBundle1 == 'Y' || chooseBundle1 == 'y')
                        {
                            printValues(0, amount_itemBundle_1, true, 1);
                        }

                        if (chooseBundle1 == 'N' || chooseBundle1 == 'n')
                        {
                            printf("Bundle 2 offers Item_C (x1) & Item_A (x1) & Item_E (x1). Do you like Bundle 2 instead? (Y/N)\n> ");
                            scanf(" %c", &chooseBundle2);
                            if (chooseBundle2 == 'Y' || chooseBundle2 == 'y')
                            {
                                printValues(0, amount_itemBundle_2, true, 2);
                            } else {

                                printf("How many [Item E] would you like to order?\n> ");
                                askInput(item_E_price, amount_item_5, false, 0);
                            }
                        }
                    } else {

                        printf("How many [Item E] would you like to order?\n> ");
                        askInput(item_E_price, amount_item_5, false, 0);
                    }
                break;
                default: printf("Invalid item!");
            }

            printf("\n\nDo you like to browse more? (Y/N)\n> ");
            scanf(" %c", &browseResponse);
        } else printf("Invalid input!");
    } while (browseResponse == 'Y' || browseResponse == 'y');

    return 0;
}