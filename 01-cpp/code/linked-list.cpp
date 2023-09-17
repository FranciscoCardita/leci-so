#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "linked-list.h"

namespace base
{

   Node *destroy(Node *list)
   {
      return NULL;
   }

   Node *append(Node *list, uint32_t nmec, char *name)
   {
      assert(name != NULL);
      assert(nmec > 0);

      char *nameCopy = strdup(name);
      Node *node = (Node *)malloc(sizeof(Node));
      node->reg.nmec = nmec;
      node->reg.name = nameCopy;
      node->next = NULL;

      if (list == NULL)
      {
         return node;
      }
      else
      {
         Node *current = list;
         while (current->next != NULL)
         {
            current = current->next;
         }
         current->next = node;
      }
      return list;
   }

   void print(Node *list)
   {
      Node *current = list;
      while (current != NULL)
      {
         printf("%d - %s\n", current->reg.nmec, current->reg.name);
         current = current->next;
      }
   }

   int exists(Node *list, uint32_t nmec)
   {
      return 0;
   }

   Node *remove(Node *list, uint32_t nmec)
   {
      assert(nmec > 0);
      assert(list != NULL);

      if (list->reg.nmec == nmec)
      {
         Node *next = list->next;
         free(list);
         return next;
      }

      Node *prev = list;
      Node *current = list->next;
      while (current != NULL)
      {
         if (current->reg.nmec == nmec)
         {
            prev->next = current->next;
            free(current);
            current = NULL;
            return list;
         }
         else
         {
            prev = current;
            current = current->next;
         }
      }
      return list;
   }

   const char *search(Node *list, uint32_t nmec)
   {
      assert(nmec > 0);
      assert(list != NULL);

      while (list != NULL)
      {
         if (list->reg.nmec == nmec)
            return list->reg.name;
         list = list->next;
      }

      return NULL;
   }

   Node *sort_by_name(Node *list)
   {
      assert(list != NULL);

      Node *prev, *current, *last;
      Student aux;

      for (last = NULL; last != list->next; last = prev)
      {
         for (prev = list; prev->next != last; prev = prev->next)
         {
            current = prev->next;
            if (strcmp(prev->reg.name, current->reg.name) > 0)
            {
               aux = prev->reg;
               prev->reg = current->reg;
               current->reg = aux;
            }
         }
      }
      return list;
   }

   Node *sort_by_number(Node *list)
   {
      assert(list != NULL);

      Node *prev, *current, *last;
      Student aux;

      for (last = NULL; last != list->next; last = prev)
      {
         for (prev = list; prev->next != last; prev = prev->next)
         {
            current = prev->next;
            if (prev->reg.nmec > current->reg.nmec)
            {
               aux = prev->reg;
               prev->reg = current->reg;
               current->reg = aux;
            }
         }
      }
      return list;
   }
}
