#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size[2] = {5, 5}, front[2] = {0, 0}, rear[2] = {0, 0};
int queue[2][5], element, qfull = 0, job, i;
float average_time, total_time = 0, total_rear;

int getRandom(int lower, int upper);
int getQueue(int job_num);
int dequeue(int job_num);

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
    srand(time(0));
    printf("Generating Jobs..\n\n");
    while (1)
    {
        job = getRandom(0, 1);
        element = getRandom(1, 10);

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
                total_time = total_time + element;
            }

            if (rear[0] == size[0] || rear[1] == size[1])
            {
                total_rear = rear[0] + rear[1];
                qfull = 1;
                printf("\nJob Generated..\n");
                printf("\nJob A = ");
                getQueue(0);
                printf("\nJob B = ");
                getQueue(1);
                printf("\n");
            }
            delay(1);
        }
        else
        {

            if (rear[1] == front[1])
            {
                if (rear[0] == front[0])
                {
                    printf("\nAll job empty");
                    average_time = (total_time / total_rear);
                    printf("\n\nAverage waiting time is %.2f seconds\n", average_time);
                    front[0] = 0;
                    front[1] = 0;
                    rear[0] = 0;
                    rear[1] = 0;
                    total_rear = 0;
                    total_time = 0;
                    qfull = 0;
                    //break;
                }
                else
                {
                    printf("\nDequeue Job A : ");
                    getQueue(0);
                    dequeue(0);
                }
            }
            else
            {
                printf("\nDequeue Job B : ");
                getQueue(1);
                dequeue(1);
            }
        }
    }
}

int getRandom(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int getQueue(int job_num)
{
    for (i = front[job_num]; i < rear[job_num]; i++)
    {
        printf("%d\t", queue[job_num][i]);
    }
}

int dequeue(int job_num)
{
    delay(queue[job_num][front[job_num]]);
    queue[job_num][i] = queue[job_num][i + 1];
    front[job_num] = front[job_num] + 1;
}