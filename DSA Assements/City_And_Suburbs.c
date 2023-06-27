// A Given city is divided in the Suburbs,town, corporation where corporation is the smallest unit.

// Find whether two corporation shares common town ,  Suburbs, City



// Example:
// City: Bangalore: 

// Suburbs: Bangalore East, Bangalore West

// Town: Bangalore East - > A, B, Bangalore West-> C, D

// Corporations: A-> 56001, 56002 B-> 56003, 56004 , C-> 56005, 56006, d-> 56007, 56008

// I/P:		 O/P

// 56001, 56008 -> Bangalore

// 56001, 56002 -> A, Bangalore East, Bangalore

// 56008, 56005 -> Bangalore West, Bangalore



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// char *cityData[15][15];

typedef struct cityData
{
    char *data;

}cityData;

struct cityData* nodes[15];

void addCorporations(int parentPos)
{
    char *corporation = malloc(sizeof(char) * 100);

    gets(corporation);

    nodes[parentPos] = malloc(sizeof(struct cityData));
    nodes[parentPos]->data = malloc(strlen(corporation)+1);

    strcpy(nodes[parentPos]->data,corporation);
}

void addTown(int parentPos)
{
    char *town = malloc(sizeof(char) * 100);

    gets(town);

    nodes[parentPos] = malloc(sizeof(struct cityData));
    nodes[parentPos]->data = malloc(strlen(town)+1);

    strcpy(nodes[parentPos]->data,town);

    printf("\nEnter Corporation 1 for %s: ", town);
    addCorporations((parentPos*2)+1);

    printf("\nEnter Corporation 2 for %s: ", town);
    addCorporations((parentPos*2)+2);
}



void addSuburbs(int parentPos)
{
    char *suburb = malloc(sizeof(char) * 100);

    gets(suburb);

    nodes[parentPos] = malloc(sizeof(struct cityData));
    nodes[parentPos]->data = malloc(strlen(suburb)+1);

    strcpy(nodes[parentPos]->data,suburb);

    printf("\nEnter Town 1 for %s: ", suburb);
    addTown((parentPos*2)+1);

    printf("\nEnter Town 2 for %s: ", suburb);
    addTown((parentPos*2)+2);
}




void addCity()
{
    char *city = malloc(sizeof(char) * 100);

    int parentPos = 0;

    printf("\nEnter city: ");
    gets(city);

    nodes[parentPos] = malloc(sizeof(struct cityData));
    nodes[parentPos]->data = malloc(strlen(city)+1);

    strcpy(nodes[parentPos]->data,city);

    printf("\nEnter Suburb 1 for %s: ", city);
    addSuburbs((parentPos*2)+1);

    printf("\nEnter Suburb 2 for %s: ", city);
    addSuburbs((parentPos*2)+2);
}


int main()
{
    addCity();

    for(int i=0; i<15; i++)
    {
        printf("%s, ", nodes[i]->data);
    }

    return 0;
}