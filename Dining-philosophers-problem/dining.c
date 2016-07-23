/*https://docs.oracle.com/cd/E19205-01/820-0619/gepit/index.html

https://www.youtube.com/watch?v=M3CNoX8wetM

*/
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>

#define PHILS 5
#define RICE 55

pthread_mutex_t chopsticks[PHILS];
pthread_mutex_t rice;
pthread_t philos[PHILS];

void * runPhil(void *);
int riceLeft();

int main(int argn, char* argv[])
{int i;
	for(i=0;i<PHILS;i++)
		pthread_mutex_init(&chopsticks[i], NULL);
	pthread_mutex_init(&rice, NULL);
	for(i=0;i<PHILS;i++) 
		pthread_create(&philos[i], NULL, runPhil,(void*)i);

	for(i=0;i<PHILS;i++)
		pthread_join(philos[i],NULL);
	return 0;

}

void * runPhil(void * id)
{
	int i;
	i=(int)id;
	int r=i;
	int l=(i+1)%PHILS;
	int riceleft;

	while(riceleft=riceLeft())
	{
		//to avoid deadlock we delay the first thread i.e. first philosopher by 30 seconds

		if(i==1)
			sleep(30);

		//lock right and left chopsticks to use them for ith philosopher
	
		pthread_mutex_lock(&chopsticks[r]);
		printf("Philosopher %d: picked up %d in right hand\n",i,r);		
		pthread_mutex_lock(&chopsticks[l]);
		printf("Philosopher %d: picked up %d in left hand\n",i,l);		
		
		printf("Philosopher %d: is eating",i);

		//this delay for philosopher to eat one unit of rice out of the amount of units left

		sleep(0.005*(RICE-riceleft+1));

		//free the left and right chopsticks respectively

		pthread_mutex_unlock(&chopsticks[l]);
		pthread_mutex_unlock(&chopsticks[r]);
		
	}

	printf("Philosopher %d is done eating\n",i);


}

int riceLeft()
{
	static int ricetotal=RICE;
	int riceleft;

	//lock the rice which is also a shared resource till we use it
		
	pthread_mutex_lock(&rice);

	//check if its available and decrease by one unit if available

	if(ricetotal>0)
		ricetotal--;
	pthread_mutex_unlock(&rice);

	riceleft=ricetotal;
	return riceleft;
}
