
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep 
	
sem_t semaphores[6]; // five semaphores ( 5 forks) 1 , 2 , 3 ,4 ,5

void* func(void *i)                 // function to be called by each thread 
{

	int temp ;
	int a = *((int *) i);
	printf("hello from philosopher  %d \n",a);

	//-------------
	if(a == 5)
		temp = (int)((temp +1 ) % 5);
	else
		temp = a+1;
	if((sem_trywait(&semaphores[a]) == 0) && (sem_trywait(&semaphores[temp]) != 0))
	{
		sem_wait(&semaphores[temp]);
		printf("semaphore %d and %d  locked by philosopher %d \n" ,a,temp,a);
		printf("philosopher %d BEGAN EATING -----------------------------------------------\n",a);
		sleep(1);
		printf("philosopher %d DONE  EATING -----------------------------------------------\n",a);
		sem_post(&semaphores[a]);
		sem_post(&semaphores[temp]);
	}
		
	else if ((sem_trywait(&semaphores[a]) != 0)  && (sem_trywait(&semaphores[temp]) != 0))
	{
		printf("semaphore %d locked by philosopher %d and value to temp = %d \n" ,a,a,temp);
		printf("philosopher is thinking \n");	
    	sem_wait(&semaphores[a]); 
	} 

	
	//------------
	
	return NULL;
}


int main()
{
	int loop = 0;
	
	int i;
	pthread_t threads[6];  // five threads 1 ,2 ,3, 4, 5
	while(loop<200)
	{
		//-------Initialize the semaphore
		int sem_resp;
		for(i =1 ;i<6 ;i++)
		{
			sem_resp = sem_init(&semaphores[i],0,0);
			if(sem_resp==-1)
			{
				perror("semaphore initialization failed");
				exit(1);
			}
		}
		//---------Call the threads
		for(i =1 ;i<6 ;i++)
		{
			int *arg = malloc(sizeof(*arg));
			*arg = i;
			pthread_create(&threads[i], NULL, &func, arg);
			
			printf("Done It Worked\n" );
			sem_post(&semaphores[i]);
		}
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
/*
void *foo(void *i) {
    int a = *((int *) i);
    free(i);
}

int main() {
    pthread_t thread;
    for ( int i = 0; i < 10; ++1 ) {
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }

        *arg = i;
        pthread_create(&thread, 0, foo, arg);
    }

     Wait for threads, etc  

    return 0;
}*/
