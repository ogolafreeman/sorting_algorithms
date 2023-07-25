#include "deck.h"

int _strcmp (const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - ...
 * @s1: ...
 * @s2: ...
 * Return: ...
 */
int _strcmp(const char *s1, const char *s2)
{
        while (*s1 && *s2 && *s1 == *s2)
        {
                s1++;
                s2++;
        }

        if (*s1 != *s2)
                return (*s1 - *s2);
        return (0);
}

/**
 * get_value - ...
 * @card: ...
 * Return:...
 */
char get_value(deck_node_t *card)
{
        if (_strcmp(card->card->value, "Ace") == 0)
                return (0);

        if (_strcmp(card->card->value, "1") == 0)
                return (1);

        if (_strcmp(card->card->value, "2") == 0)
                return (2);

        if (_strcmp(card->card->value, "3") == 0)
                return (3);

        if (_strcmp(card->card->value, "4") == 0)
                return (4);

        if (_strcmp(card->card->value, "5") == 0)
                return (5);

        if (_strcmp(card->card->value, "6") == 0)
                return (6);

        if (_strcmp(card->card->value, "7") == 0)
                return (7);

        if (_strcmp(card->card->value, "8") == 0)
                return (8);

        if (_strcmp(card->card->value, "9") == 0)
                return (9);

        if (_strcmp(card->card->value, "10") == 0)
                return (10);

        if (_strcmp(card->card->value, "Jack") == 0)
                return (11);

        if (_strcmp(card->card->value, "Queen") == 0)
                return (12);

        return (13);
}


/**
 * insertion_sort_deck_kind - ...
 * @deck: ...
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
        deck_node_t *iter, *insert, *tmp;

        for (iter = (*deck)->next; iter != NULL; iter = tmp)
        {
                tmp = iter->next;
                insert = iter->prev;
                while (insert != NULL && insert->card->kind > iter->card->kind)
                {
                        insert->next = iter->next;
                        if (iter->next != NULL)
                                iter->next->prev = insert;
                        iter->prev = insert->prev;
                        iter->next = insert;

                        if (insert->prev != NULL)
                                insert->prev->next = iter;
                        else
                                *deck = iter;
                        insert->prev = iter;
                        insert = iter->prev;
                }
        }
}

/**
 * insertion_sort_deck_value - ...
 * @deck: ...
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
        deck_node_t *iter, *insert, *tmp;

        for (iter = (*deck)->next; iter != NULL; iter = tmp)
        {
                tmp = iter->next;
                insert = iter->prev;

                while (insert != NULL &&
                       insert->card->kind == iter->card->kind &&
                       get_value(insert) > get_value(iter))
                {
                        insert->next = iter->next;
                        if (iter->next != NULL)
                                iter->next->prev = insert;
                        iter->prev = insert->prev;
                        iter->next = insert;

                        if (insert->prev != NULL)
                                insert->prev->next = iter;
                        else
				*deck = iter;
                        insert->prev = iter;
                        insert = iter->prev;
                }
        }
}

/**
 * sort_deck - ...
 * @deck: ...
 */
void sort_deck(deck_node_t **deck)
{
        if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
                return;

        insertion_sort_deck_kind(deck);

        insertion_sort_deck_value(deck);
}

