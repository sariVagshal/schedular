# schedular
simulate the OS schedular

Here is a project that simulates the action of the OS:
In fact, even if we have a single processor on the computer, we can run several programs at the same time.
What really happens is simulated parallelism, and it happens because of the scheduler.
Each task is divided into several slices and its level of priority for running.
The scheduler holds a queue for the sub-tasks and runs every single slice of time for one sub-task.
The queue is managed by a minimum heap (a data structure) so that the more important the task, the sooner it will do.
I have provided examples of two tasks here, and of course they are just examples and can be extended to many more options, and yes, the time for each task I have wrapped up in the department that will deal with its affairs.
You can of course add a time class that runs for Windows ...