Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:
1 x y : Insert a book with  pages at the end of the  shelf.
2 x y : Print the number of pages in the  book on the  shelf.
3 x : Print the number of books on the  shelf.
Snow Howler has got an assistant, Oshie, provided by the Department of Education. Although inexperienced, Oshie can handle all of the queries of types 2 and 3.

Help Snow Howler deal with all the queries of type 1.

Oshie has used two arrays:

int* total_number_of_books;
/*
 * This stores the total number of books on each shelf.
 */

int** total_number_of_pages;
/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
Input Format

The first line contains an integer , the number of shelves in the library.
The second line contains an integer , the number of requests.
Each of the following  lines contains a request in one of the three specified formats.

Constraints

For each query of the second type, it is guaranteed that a book is present on the  shelf at  index.
Both the shelves and the books are numbered starting from 0.
Maximum number of books per shelf .
Output Format

Write the logic for the requests of type 1. The logic for requests of types 2 and 3 are provided.

Sample Input 0

5
5
1 0 15
1 0 20
1 2 78
2 2 0
3 0
Sample Output 0

78
2
Explanation 0

There are  shelves and  requests, or queries.
- 1 Place a  page book at the end of shelf .
- 2 Place a  page book at the end of shelf .
- 3 Place a  page book at the end of shelf .
- 4 The number of pages in the  book on the  shelf is 78.
- 5 The number of books on the  shelf is 2.

######################## CODE ################################

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;
int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    total_number_of_books=(int*)calloc(total_number_of_shelves,sizeof(int));
    total_number_of_pages=(int**)malloc(total_number_of_shelves*sizeof(int*));
    
    for (int i=0; i<total_number_of_shelves; i++) {
       total_number_of_pages[i]=NULL;
    }
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            total_number_of_books[x]++;
            total_number_of_pages[x]=(int*)realloc(total_number_of_pages[x],total_number_of_books[x] *sizeof(int));
            total_number_of_pages[x][total_number_of_books[x]-1]=y;

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
