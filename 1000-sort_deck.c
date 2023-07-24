#include "deck.h"

int _strcmp (const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
        /* Compare characters until a difference is found or the end of a string is reached */
        while (*s1 && *s2 && *s1 == *s2)
        {
                 /* Move to the next character in s1 */
                s1++;
                /* Move to the next character in s2 */
                s2++;
        }

        if (*s1 != *s2)
                /* Return the difference between the corresponding characters in s1 and s2 */
                return (*s1 - *s2);
         /* If s1 and s2 are equal, return 0 */
        return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
        if (_strcmp(card->card->value, "Ace") == 0)
                return (0);  /* If the card value is "Ace", return 0 */

        if (_strcmp(card->card->value, "1") == 0)
                return (1);  /* If the card value is "1", return 1 */

        if (_strcmp(card->card->value, "2") == 0)
                return (2);  /* If the card value is "2", return 2 */

        if (_strcmp(card->card->value, "3") == 0)
                return (3);  /* If the card value is "3", return 3 */

        if (_strcmp(card->card->value, "4") == 0)
                return (4);  /* If the card value is "4", return 4 */

        if (_strcmp(card->card->value, "5") == 0)
                return (5);  /* If the card value is "5", return 5 */

        if (_strcmp(card->card->value, "6") == 0)
                return (6);  /* If the card value is "6", return 6 */

        if (_strcmp(card->card->value, "7") == 0)
                return (7);  /* If the card value is "7", return 7 */

        if (_strcmp(card->card->value, "8") == 0)
                return (8);  /* If the card value is "8", return 8 */

        if (_strcmp(card->card->value, "9") == 0)
                return (9);  /* If the card value is "9", return 9 */

        if (_strcmp(card->card->value, "10") == 0)
                return (10); /* If the card value is "10", return 10 */

        if (_strcmp(card->card->value, "Jack") == 0)
                return (11); /* If the card value is "Jack", return 11 */

        if (_strcmp(card->card->value, "Queen") == 0)
                return (12); /* If the card value is "Queen", return 12 */

        return (13);    /* If the card value is not matched, return 13 */
}


/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
        deck_node_t *iter, *insert, *tmp;

        for (iter = (*deck)->next; iter != NULL; iter = tmp)
        {
                tmp = iter->next;
                insert = iter->prev;
                /* Move the current card towards the beginning of the suit until it is in the correct position */
                while (insert != NULL && insert->card->kind > iter->card->kind)
                {
                        /* Set the next node of insert to the next node of iter */
                        insert->next = iter->next;
                        if (iter->next != NULL)
                                /* If iter has a next node, set its previous node to insert */
                                iter->next->prev = insert;
                         /* Set the previous node of iter to the previous node of insert */
                        iter->prev = insert->prev;
                        /* Set the next node of iter to insert */
                        iter->next = insert;

                        if (insert->prev != NULL)
                                /* If insert has a previous node, set its next node to iter */
                                insert->prev->next = iter;
                        else
                                /* If insert is the first node, update the deck head to iter */
                                *deck = iter;
                        /* Set the previous node of insert to iter */
                        insert->prev = iter;
                        /* Update insert to the previous node */
                        insert = iter->prev;
                }
        }
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
        deck_node_t *iter, *insert, *tmp;

        /* Iterate through the deck starting from the second card */
        for (iter = (*deck)->next; iter != NULL; iter = tmp)
        {
                /* Store the next node before potential reordering */
                tmp = iter->next;
                /* Start with the preceding node of the current node */
                insert = iter->prev;

                /* Compare the kind and value of cards to determine the correct position */
                while (insert != NULL &&
                       insert->card->kind == iter->card->kind &&
                       get_value(insert) > get_value(iter))
                {
                         /* Adjust the next pointer of the preceding node */
                        insert->next = iter->next;
                        if (iter->next != NULL)
                                /* Adjust the previous pointer of the following node */
                                iter->next->prev = insert;
                        /* Set the previous pointer of the current node to the previous of the preceding node */
                        iter->prev = insert->prev;
                        /* Set the next pointer of the current node to the preceding node */
                        iter->next = insert;

                        if (insert->prev != NULL)
                                /* Adjust the next pointer of the preceding node */
                                insert->prev->next = iter;
                        else
                                 /* Update the head of the deck if the preceding node is NULL (indicating it is the new head) */
                                *deck = iter;
                         /* Set the previous pointer of the preceding node to the current node */
                        insert->prev = iter;
                        /* Move to the previous node */
                        insert = iter->prev;
                }
        }
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
        /* Check if the deck is empty or has only one card */
        if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
                return;

        /* Sort the deck based on card kind (spades to diamonds) */
        insertion_sort_deck_kind(deck);

        /* Sort the deck based on card value (ace to king) within each kind */
        insertion_sort_deck_value(deck);
}

