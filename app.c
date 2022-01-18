#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int lower, int upper);

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int main()
{
    int size[2] = {5, 5}, front = 0, rear[2] = {0, 0};
    int queue[2][5], element, qfull = 0, job, i, j;

    srand(time(0));
    printf("Generating Jobs..\n\n");
    while (1)
    {
        delay(1);
        job = getRandom(0, 1);
        element = getRandom(0, 999);
        //printf("%d\t", element);

        if (qfull == 0)
        {
            if (rear[job] == size[job])
            {
                printf("\nQueue Full\n");
                break;
            }
            else
            {
                queue[job][rear[job]] = element;
                rear[job] = rear[job] + 1;
            }
            
            
            if (rear[0] == size[0] || rear[1] == size[1])
            {
                qfull = 1;
                printf("\nJob Generated..\n");
                printf("\nJob A = ");
                for (i = 0; i < rear[0]; i++)
                {
                    printf("%d\t", queue[0][i]);
                }
                printf("\nJob B = ");
                for (i = 0; i < rear[1]; i++)
                {
                    printf("%d\t", queue[1][i]);
                }
                printf("\n");
            }
            
        }
        else
        {
            
            if (rear[1] == front)
            {
                if (rear[0] == front)
                {
                    printf("\nAll job empty");
                    break;
                }
                else
                {
                    printf("\nDequeue Job A %d", queue[0][front]);
                    for (i = front; i < rear[0]; i++)
                    {
                        queue[0][i] = queue[0][i + 1];
                    }
                    rear[0] = rear[0] - 1;
                }
            }
            else
            {
                printf("\nDequeue Job B = %d", queue[1][front]);
                for (i = front; i < rear[1]; i++)
                {
                    queue[1][i] = queue[1][i + 1];
                }
                rear[1] = rear[1] - 1;
            }
            
        }
    }

    /*
    printf("Job A = %d", queue[0][0]);
    printf("\nJob B = %d", queue[1][0]);
    */
}

int getRandom(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}