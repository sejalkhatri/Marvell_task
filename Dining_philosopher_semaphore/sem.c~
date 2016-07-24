
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep 
	
sem_t semaphores[6]; // five semaphores ( 5 forks) 1 , 2 , 3 ,4 ,5

void* func(void *i)                 // function to be called by each thread 
{

	int temp ;
	int check_flag;
	int a = *((int *) i);
	printf("hello from philosopher  %d \n",a);
		
	if(a == 5)
		temp = (int)((a +1 ) % 5);
	else
		temp = a+1;


	if ((sem_trywait(&semaphores[a]) == 0)  && (sem_trywait(&semaphores[temp]) == 0))
	{
		printf("semaphore %d locked by philosopher %d and value of temp = %d \n" ,a,a,temp);
		sem_post(&semaphores[a]);
		sem_post(&semaphores[temp]);

    	sem_wait(&semaphores[a]); 
		sem_wait(&semaphores[temp]);
		printf("semaphore %d and %d  locked by philosopher %d \n" ,a,temp,a);
		printf("philosopher %d BEGAN EATING -----------------------------------------------\n",a);
		sleep(a);
		printf("philosopher %d DONE  EATING -----------------------------------------------\n",a);
		sem_post(&semaphores[a]);
		sem_post(&semaphores[temp]);	
		
	}
	else
	{
		printf("Philosopher %d is Thinking \n\n",a);
		sleep(a);
	} 
	return NULL;
}


int main()
{
	int loop = 0;
	int sem_resp;
		
	int i;
	pthread_t threads[6];  // five threads 1 ,2 ,3, 4, 5
	

	while(loop<200)
	{
			//-------Initialize the semaphore
		for(i =1 ;i<6 ;i++)
		{
			sem_resp = sem_init(&semaphores[i],0,0);
			if(sem_resp==-1)
			{
				perror("semaphore initialization failed");
				exit(1);
			}
		}
		for(i =1 ;i<6 ;i++)
		{
			sem_post(&semaphores[i]);
		}
	
		//---------Call the threads
		for(i =1 ;i<6 ;i++)
		{
			int *arg = malloc(sizeof(*arg));
			*arg = i;
			pthread_create(&threads[i], NULL, &func, arg);
			sleep(1);
			//pthread_join(threads[i], NULL);
		}
		printf("Threads created \n" );
		for(i =1 ;i<6 ;i++)
		{
			int *arg = malloc(sizeof(*arg));
			*arg = i;
			pthread_join(threads[i], NULL);
		}
	
		loop++;
	}
	return 0;
}
