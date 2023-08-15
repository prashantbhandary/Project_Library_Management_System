/* LIBRARY MANAGEMNET SYSTEMM BY BEI079 << PRASHANT SIDDHANT NANDITA RIJUTAA >> */
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void displaymenu();
void performaction(int choice);
void addbook();//1
void searchbook();//2
void displaybook();//3
void issue();//4
void bookreturn();//5
void delete_book();//6
void addmember();//7

struct lib_book{
	int book_id;
	char book_name[20];
	char author_name[20];
}book; 		// structure create garemm yesma chai lib bookk banney jun lay chai book ko kaam handle garxa...

struct lib_member
{
  int mid;
  char mname[25] ;
  char department[25];
  int phone;

}member;		// yo chai aaba member ko data haru handle garna ko lagi hooo 

FILE *lib_record;			// forr book ko data store garna ko lagii file 1
FILE *member_record; // lib member ko data ko ko member xan bane ra data store garna ko lagi bana ko file 2

int main() {
    int choice = 0;
	printf("\t\t+---------------------------------------------------+\n");
	printf("\t\t|                                                   |\n");
    printf("\t\t|   ** Welcome to the Library Management System **  |\n");
    printf("\t\t|                                                   |\n");
    printf("\t\t|  BEI (PRASHANT << SIDDHANT << NANDITA << RIJUTA ) |\n");
    printf("\t\t|                                                   |\n");
	printf("\t\t+---------------------------------------------------+\n");
    do {
        displaymenu();
        
        printf("** Enter your choice <1-8>: ");
        scanf("%d", &choice);
        performaction(choice);
    } while (choice != 8);
    
    return 0;
}
void displaymenu() {
    printf("\n");
    printf("\t\t+--------------------------------------------+\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|             M A I N    M E N U             |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t+--------------------------------------------+\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|  1. Add A New Book                         |\n");
    printf("\t\t|  2. Search a Book                          |\n");
    printf("\t\t|  3. Display Books                          |\n");
    printf("\t\t|  4. Issue a Book                           |\n");
    printf("\t\t|  5. Return a Book                          |\n");
    printf("\t\t|  6. Delete a Book                          |\n");
    printf("\t\t|  7. Add New Member                         |\n");
    printf("\t\t|  8. Exit the Program                       |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t+--------------------------------------------+\n");
}
void performaction(int choice) {
    switch (choice) {
        case 1:
            addbook();
            break;
        case 2:
            searchbook();
            break;
        case 3:
            displaybook();
            break;
        case 4:
            issue();
            break;
        case 5:
            bookreturn();
            break;
        case 6:
            delete_book();
            break;
        case 7:
        	
            addmember();
            break;
        case 8:
        	    printf("\n");
			    printf("\t\t+----------------------------------------------------------------+\n");
			    printf("\t\t|                                                                |\n");
			    printf("\t\t|            E X I T I N G     T H E     P R O G R A M           |\n");
			    printf("\t\t|                                                                |\n");
			    printf("\t\t|        Thank you for using the Library Management System.      |\n");
			    printf("\t\t|                        Have a great day!                       |\n");
			    printf("\t\t+----------------------------------------------------------------+\n");
            exit(0);
            break;
        default:
            printf("\nInvalid Input. Please select a valid option.\n");
    }
}
void addbook() {
    int i;
    lib_record = fopen("lib_record.txt", "a+");

    printf("\n");
    printf("\t\t+-------------------------------------------------------+\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t|            A D D    N E W    B O O K                  |\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t+-------------------------------------------------------+\n");
    
    printf("\t\tEnter the book_id: ");
    scanf("%10d", &book.book_id);
	
    printf("\t\tEnter The Name of The Book: ");
    scanf("%20s", book.book_name);
    
    printf("\t\tEnter The Name of Author: ");
    scanf("%20s", book.author_name);
    fprintf(lib_record, "\n%-12d%-25s%-25s", book.book_id, book.book_name, book.author_name);
    fclose(lib_record);

    printf("\t\t <<<---- A New Book has been Added Successfully ---->>>\n");
}
void searchbook() {
    char Target[25];
    int Found = 0;
    lib_record = fopen("lib_record.txt", "r");
    printf("\n");
    printf("\t\t+-------------------------------------------------------+\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t|                S E A R C H    B O O K                 |\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t+-------------------------------------------------------+\n");
    if (lib_record == NULL) {
        printf("\t\tError opening the file.\n");
        return;
    }
    printf("\t\tEnter the name of the book to search: ");
    scanf("%s", Target);
    printf("\n\t\tSearch Result:\n");

    while (fscanf(lib_record, "%d %s %s", &book.book_id, book.book_name, book.author_name) != EOF) {
        if (strcmp(book.book_name, Target) == 0) {
            printf("\n\t\tBook id: %d", book.book_id);
            printf("\n\t\tBook Name: %s", book.book_name);
            printf("\n\t\tAuthor: %s", book.author_name);
            Found = 1;
        }
    }
    fclose(lib_record);

    if (Found == 0) {
        printf("\n\t\t<<<<----No record found for \"%s\"---->>>>\n", Target);
    }
}
void displaybook() {
    printf("\n");
    printf("\t\t+--------------------------------------------------------------------+\n");
    printf("\t\t|                                                                    |\n");
    printf("\t\t|                     D I S P L A Y    B O O K S                     |\n");
    printf("\t\t|                                                                    |\n");
    printf("\t\t+--------------------------------------------------------------------+\n");
    printf("\t\t|                                                                    |\n");
    printf("\t\t|   %-12s%-25s%-25s   |\n", "Bookid", "Name", "Author");
    lib_record = fopen("lib_record.txt", "r");
    if (lib_record == NULL) {
        printf("\t\t|   No books found.                                              |\n");
    } else {
        while (fscanf(lib_record, "%d %s %s", &book.book_id, &book.book_name,&book.author_name) != EOF) {
            printf("\t\t|   %-12d%-25s%-25s   |\n", book.book_id, book.book_name, book.author_name);
        }
        fclose(lib_record);
    }
    printf("\t\t|                                                                    |\n");
    printf("\t\t+--------------------------------------------------------------------+\n");
}
void addmember()//7
{
    int i;
    member_record = fopen("member_record.txt", "a+");

    printf("\n");
    printf("\t\t+--------------------------------------------+\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|        A D D   N E W   M E M B E R         |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t+--------------------------------------------+\n");

    printf("\t\tEnter The userid of the Member(Int) ---- >> ");
    scanf("%10d", &member.mid);

    printf("\t\tEnter The Name of the Member        ---- >> ");
    scanf("%20s", member.mname);

    printf("\t\tEnter The Department                ---- >> ");
    scanf("%20s", member.department);

    printf("\t\tEnter The phone number of the member---- >> ");
    scanf("%10d", &member.phone);

    fprintf(member_record, "\n%-12d%-25s%-25s%-10d ", member.mid, member.mname, member.department, member.phone);
    fclose(member_record);
    printf("\n\t\t<<< --- Added  A New member Successfully --->>> \n");
}
void issue()//4
{
    int mid, i, Found1 = 0, Found2 = 0, book_id;
    char issubookname[20];
    printf("\n");
    printf("\t\t+--------------------------------------------+\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|           I S S U E   A   B O O K          |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t+--------------------------------------------+\n");
    printf("\t\tEnter The userid of the Member : ");
    scanf("%d", &mid);
    if ((member_record = fopen("member_record.txt", "r")) == NULL)
        printf("\t\t<<< The file is empty >>>\n");

    while (fscanf(member_record, "%d %s %s %d", &member.mid, &member.mname, &member.department, &member.phone) != EOF) {
        if (member.mid == mid) {
            Found1 = 1;
            break;
        }
    }
    fclose(member_record);
    if (Found1 == 0) {
        printf("\t\tMember with userid %d not found.\n", mid);
        return;
    }
    printf("\t\tEnter the book_id to be issued: ");
    scanf("%d", &book_id);

    lib_record = fopen("lib_record.txt", "r");

    while (fscanf(lib_record, "%d %s %s", &book.book_id, &book.book_name, &book.author_name) != EOF) {
        if (book.book_id == book_id) {
            Found2 = 1;
            strcpy(issubookname, book.book_name);
            break;
        }
    }
    fclose(lib_record);
    if (Found2 == 0) {
        printf("\t\tBook with book_id %d not found.\n", book_id);
        return;
    }
    printf("\t\tBook '%s' with book_id %d has been issued to member with userid %d.\n", issubookname, book_id, mid);
}

void bookreturn() //5
{
    int mid, book_id;
    printf("\n");
    printf("\t+------------------------------------------+\n");
    printf("\t|                                          |\n");
    printf("\t|           R E T U R N    B O O K          |\n");
    printf("\t|                                          |\n");
    printf("\t+------------------------------------------+\n");

    printf("\nEnter the userid of the member: ");
    scanf("%20d", &mid);

    printf("\nEnter the book_id to return: ");
    scanf("%20d", &book_id);

    // Open the library record file for appending
    lib_record = fopen("lib_record.txt", "a+");

    fprintf(lib_record, "\n%20d  %20s  %20s", book_id, book.book_name, book.author_name);
    fclose(lib_record);
    printf("Book with book_id %d has been returned by member with userid %d.\n", book_id, mid);
}

void delete_book()//6
{
    int book_id;
    printf("\n");
    printf("\t+-----------------------------------------+\n");
    printf("\t|                                         |\n");
    printf("\t|         D E L E T E    B O O K          |\n");
    printf("\t|                                         |\n");
    printf("\t+-----------------------------------------+\n");

    printf("Enter the book_id to delete: ");
    scanf("%20d", &book_id);

    FILE *tempFile = fopen("temp_lib_record.txt", "w");
    lib_record = fopen("lib_record.txt", "r");
    int found = 0;
    while (fscanf(lib_record, "%d %s %s", &book.book_id, book.book_name, book.author_name) != EOF) {
        if (book.book_id != book_id) {
            fprintf(tempFile, "%d %s %s\n", book.book_id, book.book_name, book.author_name);
        } else {
            found = 1;   
        }
    }
    fclose(lib_record);
    fclose(tempFile);

    if (!found) {
        printf("Book with book_id %d not found.\n", book_id);
        remove("temp_lib_record.txt");
    } else {
        remove("lib_record.txt");
        rename("temp_lib_record.txt", "lib_record.txt"); // rename garni purano file laii
        printf("Book with book_id %d has been deleted.\n", book_id);
    }
}
