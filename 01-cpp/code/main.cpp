#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <alloca.h>

#include "linked-list.h"

using namespace base;

static Node* list = NULL;

/* ******************************************** */

static void printMenu(void)
{
   printf("\n"
         "+===============================================+\n"
         "|            Manipulation functions             |\n"
         "+===============================================+\n"
         "| 0 --- quit                                    |\n"
         "| 1 --- append new student                      |\n"
         "| 2 --- print list                              |\n"
         "| 3 --- remove student, through number          |\n"
         "| 4 --- get student's name, given the number    |\n"
         "| 5 --- sort list by name                       |\n"
         "| 6 --- sort list by number                     |\n"
         "+===============================================+\n");
}

/* ******************************************** */
/* menu handling functions */
/* ******************************************** */

void menuChoiceAppend()
{
   printf("NMec: ");
   u_int32_t nmec;
   scanf("%d", &nmec);

   printf("Name: ");
   char name[256];
   scanf("%s", name);

   list = append(list, nmec, name);
}

/* ******************************************** */

/* n ->  <=>  (*n). */
void menuChoicePrint()
{
   print(list);
}

/* ******************************************** */

void menuChoiceRemove()
{
   printf("NMec: ");
   u_int32_t nmec;
   scanf("%d", &nmec);

   list = remove(list, nmec);
}

/* ******************************************** */

void menuChoiceSearch()
{
   printf("NMec: ");
   u_int32_t nmec;
   scanf("%d", &nmec);

   const char *name = search(list, nmec);

   if (name == NULL)
      printf("Student not found!\n");
   else
      printf("Student name: %s\n", name);
}

/* ******************************************** */

void menuChoiceSortByName()
{
   print(sort_by_name(list));
}

/* ******************************************** */

void menuChoiceSortByNumber()
{
   print(sort_by_number(list));
}

/* ******************************************** */

/* The main function */
int main()
{
   int terminate = 0;
   while (!terminate)
   {
      printMenu();
      printf("Your command: ");
      int cmd;
      int res = scanf("%d", &cmd);
      if (res != 1)
      {
         fprintf(stderr, "Wrong input format (unsigned integer number required)\n");
         scanf("%*s"); // consume and ignore standard input
      }
      else
      {
         printf("\n");
         switch(cmd) 
         {
            case 0:
               terminate = 1;
               break;
            case 1:
               menuChoiceAppend();
               break;
            case 2:
               menuChoicePrint();
               break;
            case 3:
               menuChoiceRemove();
               break;
            case 4:
               menuChoiceSearch();
               break;
            case 5:
               menuChoiceSortByName();
               break;
            case 6:
               menuChoiceSortByNumber();
               break;
            default:
               fprintf(stderr, "Wrong action required (%d)\n", cmd);
         }
      }
   }

   return 0;
}     /* end of main */

