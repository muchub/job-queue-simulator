#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size[2] = {5, 5}, front = 0, rear[2] = {0, 0};
int queue[2][5], element, qfull = 0, job, i;
float average_time, max_time = 3, total_time = 0, total_rear;

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
        element = getRandom(0, 10);
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

            if (rear[1] == front)
            {
                if (rear[0] == front)
                {
                    printf("\nAll job empty");
                    break;
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

    /*
    printf("Job A = %d", queue[0][0]);
    printf("\nJob B = %d", queue[1][0]);
    */
   //printf("Rear A = %d\n Rear B = %d", rear[0], rear[1]);
   average_time = (total_time/total_rear);
   printf("\n\nAverage waiting time is %f seconds", average_time);
   //printf("\n\ntotal time is %.1f", total_time);
   //printf("\n\ntotal rear is %.1f", total_rear);
}

int getRandom(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int getQueue(int job_num)
{
    for (i = 0; i < rear[job_num]; i++)
    {
        printf("%d\t", queue[job_num][i]);
    }
}

int dequeue(int job_num)
{
    int new_job;
    if (queue[job_num][front] <= max_time)
    {
        delay(queue[job_num][front]);
        for (i = front; i < rear[job_num]; i++)
        {
            queue[job_num][i] = queue[job_num][i + 1];
        }
        rear[job_num] = rear[job_num] - 1;
    }
    else
    {
        new_job = queue[job_num][front] - max_time;
        delay(max_time);
        for (i = front; i < rear[job_num]; i++)
        {
            queue[job_num][i] = queue[job_num][i + 1];
            queue[job_num][rear[job_num] - 1] = new_job;
        }
        //queue[job_num][rear[job_num]] = new_job;
        //printf("rear = %d", rear[job_num]);
    }
}