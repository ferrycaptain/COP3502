#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // malloc
    char mName[100];
    char *mDescription;
    // calloc
    char cName[100];
    char *cDescription;
    // realloc
    char rName[100];
    char *rDescription;

    strcpy(mName, "Karin Whiting");

    // malloc allocates an array of num bytes dynamically and leaves them initialized
    mDescription = malloc( 200 * sizeof(char) );

    if( mDescription == NULL )
    {
        fprintf(stderr, "Error - unable to malloc required memory\n");
    }
    else
    {
        strcpy( mDescription, "Karin Whiting is a UCF professor");
    }

    printf("\n---------- malloc ----------\n\n");
    printf("Name = %s\n", mName );
    printf("Description: %s\n", mDescription );

    // calloc
    strcpy(cName, "Karin Whiting");

    //calloc allocates an array of num elements each of which size in bytes will be size
    cDescription = calloc(200, sizeof(char));

    if( cDescription == NULL )
    {
        fprintf(stderr, "Error - unable to calloc required memory\n");
    }
    else
    {
        strcpy( cDescription, "Karin Whiting is a UCF professor");
    }

    printf("\n---------- calloc ----------\n\n");
    printf("Name = %s\n", cName );
    printf("Description: %s\n", cDescription );

    // free
    printf("\n---------- before free malloc ----------\n\n");
    printf("Name = %s\n", mName );
    printf("Description: %s\n", mDescription );

    /* release memory using free() function */
    free(mName);
    free(mDescription);

    printf("\n---------- after free malloc ----------\n\n");
    printf("Name = %s\n", mName );
    printf("Description: %s\n", mDescription );

    printf("\n---------- before free calloc ----------\n\n");
    printf("Name = %s\n", cName );
    printf("Description: %s\n", cDescription );

    /* release memory using free() function */
    free(cName);
    free(cDescription);

    printf("\n---------- after free calloc ----------\n\n");
    printf("Name = %s\n", cName );
    printf("Description: %s\n", cDescription );

    printf("\n---------- realloc ----------\n\n");

    // realloc re-allocates memory extending it up to newsize
   /* suppose you want to store bigger description */
   rDescription = realloc( rDescription, 300 * sizeof(char) );

   if( rDescription == NULL )
   {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else
   {
      strcat( rDescription, " teaches Computer Science I");
   }

   printf("Name = %s\n", rName );
   printf("Description: %s\n", rDescription );

}
