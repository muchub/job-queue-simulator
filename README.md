# Job Queue Simulator

This program simulates a job queue system with two separate queues, A and B. Jobs are generated randomly and added to their respective queues until either of the queues becomes full. Once a queue is full, jobs are dequeued and their processing time is simulated.

## Features

- Simulates a job queue system with two separate queues
- Generates jobs randomly and adds them to the queues
- Dequeues jobs once a queue becomes full and simulates their processing time
- Calculates the average waiting time for all jobs

## Usage

1. Compile the program using a C compiler.
2. Run the compiled executable.
3. The program will continuously generate and process jobs until interrupted.
4. Once a queue becomes full, the program will dequeue jobs and simulate their processing time.
5. After all jobs are processed, the program will display the average waiting time for the jobs.

## Notes

- Jobs are generated randomly with processing times ranging from 1 to 10 seconds.
- Each queue has a maximum capacity of 5 jobs.
- The program uses a delay function to simulate job processing time.
- The average waiting time is calculated as the total processing time divided by the total number of jobs processed.
