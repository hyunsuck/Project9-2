#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node

{

    int data;

    struct Node* nextNode;

    struct Node* prevNode;

};

struct Node first_node(struct Node* Node_arr, int* node_data, struct Node* marker_node);

struct Node insert_node(int* insert_location, struct Node* marker_node);
struct Node delete_node(int* delete_location, struct Node* marker_node);

int node_check(struct Node* marker_node);

int main()

{

    int node_data, i;

    int insert_location, delete_location;

    struct Node* Node_arr;

    struct Node* marker_node;

    printf("First Data Insert : ");

    scanf("%d", &node_data);

    Node_arr = (struct Node*)malloc(sizeof(struct Node));

    marker_node = Node_arr;

    first_node(Node_arr, &node_data, marker_node);

    node_check(marker_node);

    for (;;)

    {

        printf("=====MENU===== \n 1. INSERT \n 2. DELETE \n 3. PRINT \n 0. EXIT  \nEnter the Menu :");

        scanf("%d", &i);

        if (i == 1)

        {

            printf("Enter the position : ");

            scanf("%d", &insert_location);

            insert_node(&insert_location, marker_node);

            node_check(marker_node);

        }

        else if (i == 2)

        {

            printf("Delete :");

            scanf("%d", &delete_location);

            delete_node(&delete_location, marker_node);

            node_check(marker_node);

        }

        else if (i == 3)

        {

            node_check(marker_node);

        }

        else if (i == 0)

        {

            printf("EXIT \n");

            break;

        }

        else

        {

            printf("Invalid Menu. Please select again.. \n");

        }



    }



    return 0;

}

int node_check(struct Node* marker_node)

{

    int i = 0;

    struct Node* location;

    location = marker_node;



    for (;;)

    {

        printf("Data No.%d = %d \n", i + 1, location->data);

        i++;

        if (location->nextNode == marker_node)

        {

            break;

        }

        else

        {

            location = location->nextNode;

        }

    }



    return 0;

}

struct Node first_node(struct Node* Node_arr, int* node_data, struct Node* marker_node)

{

    int i;

    Node_arr->data = *node_data;

    Node_arr->nextNode = Node_arr;

    Node_arr->prevNode = Node_arr;

    return *marker_node;

}

struct Node insert_node(int* insert_location, struct Node* marker_node)

{

    int data_add;

    int i = 0;

    struct Node* new_location;

    struct Node* temp_location;

    printf("Enter the Number : ");

    scanf("%d", &data_add);

    new_location = (struct Node*)malloc(sizeof(struct Node));

    new_location->data = data_add;

    if (*insert_location > 0)

    {

        temp_location = marker_node;

        for (i = 0; i < *insert_location; i++)

        {

            temp_location = temp_location->nextNode;

        }

        new_location->nextNode = temp_location;

        new_location->prevNode = temp_location->prevNode;

        (temp_location->prevNode)->nextNode = new_location;

        temp_location->prevNode = new_location;

    }

    else if (*insert_location == 0)

    {

        temp_location = marker_node;

        marker_node = new_location;

        new_location->nextNode = temp_location;

        new_location->prevNode = temp_location->prevNode;

        (temp_location->prevNode)->nextNode = new_location;

        temp_location->prevNode = new_location;

    }

    else

    {

        printf("음수는 입력할 수 없습니다. \n");

        free(new_location);

    }

    return *marker_node;

}

struct Node delete_node(int* delete_location, struct Node* marker_node)

{

    struct Node* temp_location1, * temp_location2;

    int i;

    temp_location1 = marker_node->nextNode;

    temp_location2 = marker_node->prevNode;

    if (delete_location < 0)

    {

        printf("음수는 입력할 수 없습니다. \n");

    }

    else if (delete_location == 0)

    {

        free(marker_node);

        marker_node = temp_location1;

        temp_location1->prevNode = marker_node;

        temp_location2->nextNode = marker_node;

    }

    else

    {

        for (i = 0; i < *delete_location - 1; i++)

        {

            temp_location1 = temp_location1->nextNode;

        }

        temp_location2 = temp_location1->prevNode;

        temp_location2->nextNode = temp_location1->nextNode;

        temp_location2 = temp_location1->nextNode;

        temp_location2->prevNode = temp_location1->prevNode;

        free(temp_location1);

    }

    return *marker_node;

}