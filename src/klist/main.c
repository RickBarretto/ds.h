#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "klist.h"


#define clear_buffer                                                    \
        do {                                                            \
                char ch;                                                \
                while ((ch = getchar()) != '\n' and ch != EOF )         \
                        continue;                                       \
        } while (false)

#define defer(var, res) if (not (var)) return res
#define loop(block) { while (true) block }
#define print(line) printf(line "\n")
#define unless(var, block) if (not (var)) block

// Main menu
void display_menu(klist_t *list);
void print_menu_options();
uint8_t choice();

// Secondary menus
bool insertion_option(klist_t *list);
bool multi_insertion_option(klist_t *list);


void display_menu(klist_t *list) loop({
        print_menu_options();
        uint8_t user_choice = choice();
        clear_buffer;

        switch (user_choice)
        {
        case 1:
                insertion_option(list);
                clear_buffer;
                break;

        case 2:
                multi_insertion_option(list);
                clear_buffer;
                break;

        case 3:
                clear_list(list);
                break;

        case 4:
                print("Exiting application");
                exit(EXIT_SUCCESS);

        default:
                clear_buffer;
                print("Input not recorgnized. Please, try again!");
        }

        print("Your actual linked-list's content:");
        traverse_klist(list);
})


bool insertion_option(klist_t *list)
{
        size_t number;

        print("Insert a number");
        defer(scanf("%ld", &number), false);

        insert_klist(list, number);

        return true;
}


bool multi_insertion_option(klist_t *list)
{
        size_t number;

        print("Insert multiple numbers separated by space.");
        do {
                defer(scanf(" %ld", &number), false);
                insert_klist(list, number);
        } while (getchar() != '\n');

        return true;
}


uint8_t choice()
{
        size_t choice;
        printf(">>> ");
        defer(scanf("%ld", &choice), -1);

        return choice;
}


void print_menu_options()
{
        print("Linked List Manager");
        print("\t" "1. Ordered Insertion.");
        print("\t" "2. Multiple Ordered Insertion.");
        print("\t" "3. Clear list.");
        print("\t" "4. Exit.");
}


int main()
{
        klist_t *list = new_klist();
        display_menu(list);
}