#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

// swap elements
void swap(struct Person *a, struct Person *b)
{
    struct Person temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify based on age
void minHeapify(struct Person heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].age < heap[smallest].age)
    {
        smallest = left;
    }

    if (right < n && heap[right].age < heap[smallest].age)
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Max-heapify based on weight
void maxHeapify(struct Person heap[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].weight > heap[largest].weight)
    {
        largest = left;
    }

    if (right < n && heap[right].weight > heap[largest].weight)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

// Build Min-Heap based on age
void buildMinHeap(struct Person heap[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(heap, n, i);
    }
}

// Build Max-Heap based on weight
void buildMaxHeap(struct Person heap[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(heap, n, i);
    }
}

// Insert a new person into the Min-Heap
void insertMinHeap(struct Person heap[], int *n, struct Person newPerson)
{
    heap[*n] = newPerson;
    (*n)++;
    int i = (*n) - 1;

    // Fix the min-heap property if violated
    while (i != 0 && heap[(i - 1) / 2].age > heap[i].age)
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete the oldest person from the Min-Heap
void deleteOldestPerson(struct Person heap[], int *n)
{
    if (*n == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
}

// Display the weight of the youngest person
void displayWeightOfYoungest(struct Person heap[], int n)
{
    if (n == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    printf("Weight of youngest student: %.2f kg\n", heap[0].weight * 0.453592); // Convert pounds to kg
}

// Read data from file
void readData(struct Person **persons, int *n)
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fscanf(file, "%d", n);
    *persons = (struct Person *)malloc(*n * sizeof(struct Person));

    for (int i = 0; i < *n; i++)
    {
        fscanf(file, "%d %s %d %d %d", &(*persons)[i].id, (*persons)[i].name, &(*persons)[i].age, &(*persons)[i].height, &(*persons)[i].weight);
    }

    fclose(file);
}

// Display menu and handle user input
void menu(struct Person *persons, int n)
{
    struct Person *heap = (struct Person *)malloc(n * sizeof(struct Person));
    int heapSize = 0;
    int option;
    do
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            readData(&persons, &n);
            printf("Data loaded.\n");
            break;

        case 2:
            memcpy(heap, persons, n * sizeof(struct Person));
            heapSize = n;
            buildMinHeap(heap, heapSize);
            printf("Min-heap created based on age.\n");
            break;

        case 3:
            memcpy(heap, persons, n * sizeof(struct Person));
            heapSize = n;
            buildMaxHeap(heap, heapSize);
            printf("Max-heap created based on weight.\n");
            break;

        case 4:
            displayWeightOfYoungest(heap, heapSize);
            break;

        case 5:
        {
            struct Person newPerson;
            printf("Enter new person details (Id Name Age Height Weight):\n");
            scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
            insertMinHeap(heap, &heapSize, newPerson);
            printf("New person inserted into Min-heap.\n");
            break;
        }

        case 6:
            deleteOldestPerson(heap, &heapSize);
            printf("Oldest person deleted from Min-heap.\n");
            break;

        case 7:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 7);

    free(heap);
}

int main()
{
    struct Person *persons = NULL;
    int n = 0;
    menu(persons, n);
    free(persons);
    return 0;
}
