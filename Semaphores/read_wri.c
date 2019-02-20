
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int rc=0,val,wc=0;
pthread_mutex_t mutex1,mread;
pthread_t tr1,tw1,tr2,tw2,tw3;
pthread_attr_t tr1attr,tw1attr,tr2attr,tw2attr,tw3attr;

void *reader();
void *writer();

int main()
{
 pthread_mutex_init(&mutex1,NULL);
 pthread_mutex_init(&mread,NULL);

 pthread_attr_init(&tr1attr);
 pthread_attr_init(&tr2attr);
 pthread_attr_init(&tw1attr);
 pthread_attr_init(&tw2attr);
 pthread_attr_init(&tw3attr);
 
 printf("\n Writer 1 created");
 pthread_create(&tw1,&tw1attr,writer,NULL);
 
 printf("\n Reader 1 created");
 pthread_create(&tr1,&tr1attr,reader,NULL);
 
 printf("\n Writer 2 created");
 pthread_create(&tw2,&tw2attr,writer,NULL);
 
 printf("\n Reader 2 created");
 pthread_create(&tr2,&tr2attr,reader,NULL);
 
 printf("\n Writer 3 created");
 pthread_create(&tw3,&tw3attr,writer,NULL);
 

 pthread_join(tw1,NULL);
 pthread_join(tr1,NULL);
 pthread_join(tw2,NULL);
 pthread_join(tr2,NULL); 
 pthread_join(tw3,NULL);

 return 0;
}

void *writer()
{
 pthread_mutex_lock(&mutex1);
 wc++;
 printf("\n Enter data:  ");
 scanf("%d",&val);
 pthread_mutex_unlock(&mutex1);
 printf("\n writer %d levng",wc);
 pthread_exit(0);
 
}
  
void *reader()
{
 pthread_mutex_lock(&mread);
 rc++;
 if(rc==1)
  pthread_mutex_lock(&mutex1);
 pthread_mutex_unlock(&mread);

 printf("\n Value read by reader %d: %d",rc,val);

 pthread_mutex_lock(&mread);
 rc--;
 if(rc==0)
  pthread_mutex_unlock(&mutex1);
 pthread_mutex_unlock(&mread);
 printf("\n Reader %d levng",rc+1);
 pthread_exit(0);
 
}