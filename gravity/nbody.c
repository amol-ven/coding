#include <stdio.h> 
#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds

#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>

#include <sys/time.h>

#define NIL (0)       // A name for the void pointer

//#define GRAVITY_CONST (1.61 * pow(10, 0))
//#define GRAVITY_CONST (1.61E0)
#define GRAVITY_CONST (5.0E0)


#define delt 0.001

//#define REFLECTIVE
#define COLL_CHECK

#define WIDTH 1000
#define HEIGHT 1000

#define MAX_MASS 100000

#define NUM_OF_BODIES 100

typedef struct vector
{
	float x;
	float y;
}vec_t;

typedef struct body
{
	int mass;
	int exists;
	vec_t pos;
	vec_t vel;
}body_t;

void addvec(vec_t *sum, vec_t arg1, vec_t arg2)
{
	sum->x = arg1.x + arg2.x;
	sum->y = arg1.y + arg2.y;
}

vec_t getacc(body_t subject, body_t cause)
{
	if(subject.mass==0 || cause.mass==0)
	{
		vec_t zero = {0, 0};
		return zero;
	}
	
	double G = GRAVITY_CONST;
	
	float r = sqrt((subject.pos.x-cause.pos.x)*(subject.pos.x-cause.pos.x) + (subject.pos.y-cause.pos.y)*(subject.pos.y-cause.pos.y));
	
			
	
	float Asub = G*cause.mass/(r*r);
	
	//printf("S=%d   C=%d   a=%lf\n", subject.mass, cause.mass, Asub);
	
	float Asub_dir_x = cause.pos.x - subject.pos.x;
	float Asub_dir_y = cause.pos.y - subject.pos.y;
	
	float Asub_dir_mag = sqrt(Asub_dir_x*Asub_dir_x + Asub_dir_y*Asub_dir_y);
	
	float Asub_x = Asub*Asub_dir_x/Asub_dir_mag;
	float Asub_y = Asub*Asub_dir_y/Asub_dir_mag;
	
	/*
	subject.vel.x = subject.vel.x + Asub_x*delt;
	subject.vel.y = subject.vel.y + Asub_y*delt;
	
	subject.pos.x = subject.pos.x + subject.vel.x*delt;
	subject.pos.y = subject.pos.y + subject.vel.y*delt;
	*/
	
	vec_t acc = {Asub_x, Asub_y};
	return acc;
}


void updatebody(body_t * bodies, int count, int this)
{
	static int bcount = NUM_OF_BODIES;
	vec_t acc = {0, 0};
	
	int i=0;
	
	if(bodies[this].exists!=1)
	{
		return;
	}
	
	#ifdef COLL_CHECK
	//detect collisions of this body with all bodies
	for(i=0; i<count; i++)
	{
		if(i==this || bodies[i].exists!=1)
		{
			continue;
		}
		float r = sqrt((bodies[this].pos.x-bodies[i].pos.x)*(bodies[this].pos.x-bodies[i].pos.x) + (bodies[this].pos.y-bodies[i].pos.y)*(bodies[this].pos.y-bodies[i].pos.y));
		//printf("r = %lf", r);
		
		
		//printf("r = %lf  cd = %d", r, (bodies[this].mass+bodies[i].mass)/(MAX_MASS/2));
		
		if(r < 2/*(bodies[this].mass+bodies[i].mass)/(MAX_MASS/2)*/)
		{
			bcount--;
			printf("\ncoll\n");
			printf("r = %lf  cd = %d     i=%d i.exist=%d  this=%d   this.exist=%d\n", r, (bodies[this].mass+bodies[i].mass)/(MAX_MASS/20000), i, bodies[i].exists, this, bodies[this].exists);
			fflush(stdout);
			//collision
			
			printf("(%d)  mass = %d  velx = %lf   vely = %lf\n", i, bodies[i].mass, bodies[i].vel.x, bodies[i].vel.y);
			printf("(%d)  mass = %d  velx = %lf   vely = %lf\n", this, bodies[this].mass, bodies[this].vel.x, bodies[this].vel.y);
			
			
			
			if(bodies[this].mass < bodies[i].mass)
			{
				bodies[this].exists = 0;
				
				float newvx, newvy;
				int newmass = bodies[this].mass+bodies[i].mass;
				newvx = (bodies[this].mass*bodies[this].vel.x + bodies[i].mass*bodies[i].vel.x)/(newmass);
				newvy = (bodies[this].mass*bodies[this].vel.y + bodies[i].mass*bodies[i].vel.y)/(newmass);
				
				bodies[i].vel.x = newvx;
				bodies[i].vel.y = newvy;
				bodies[i].mass = newmass;
				
				printf("(%d)  mass = %d  velx = %lf   vely = %lf\n", i, bodies[i].mass, bodies[i].vel.x, bodies[i].vel.y);
				
			}
			else
			{
				bodies[i].exists= 0;
				
				float newvx, newvy;
				int newmass = bodies[this].mass+bodies[i].mass;
				newvx = (bodies[this].mass*bodies[this].vel.x + bodies[i].mass*bodies[i].vel.x)/(newmass);
				newvy = (bodies[this].mass*bodies[this].vel.y + bodies[i].mass*bodies[i].vel.y)/(newmass);
				
				bodies[this].vel.x = newvx;
				bodies[this].vel.y = newvy;
				bodies[this].mass = newmass;
				
				printf("(%d)  mass = %d  velx = %lf   vely = %lf\n", this, bodies[this].mass, bodies[this].vel.x, bodies[this].vel.y);
			}
			break;
				
		}
		//else
		//printf("\n");
	}
	
//	printf("here %d\n", this);
	
	if(bodies[this].exists!=1)
	{
		return;
	}
	#endif
	
	for(i=0; i<count; i++)
	{
		
		if(i==this || bodies[i].exists!=1)
		{
			//printf("this = %d\n", i);
			continue;
		}
		addvec(&acc, acc, getacc(bodies[this], bodies[i]));
	}
	
	
	
	bodies[this].vel.x = bodies[this].vel.x + acc.x*delt;
	bodies[this].vel.y = bodies[this].vel.y + acc.y*delt;
	
	bodies[this].pos.x = bodies[this].pos.x + bodies[this].vel.x*delt;
	bodies[this].pos.y = bodies[this].pos.y + bodies[this].vel.y*delt;
	
	
	#ifdef REFLECTIVE
	
	if(bodies[this].pos.x <= 0 )
	{
		bodies[this].pos.x = 0;
		bodies[this].vel.x = -bodies[this].vel.x/2;  //slow down a bit
	}
	if(bodies[this].pos.x >= WIDTH )
	{
		bodies[this].pos.x = WIDTH;
		bodies[this].vel.x = -bodies[this].vel.x/2;
	}
	
	if(bodies[this].pos.y <= 0 )
	{
		bodies[this].pos.y = 0;
		bodies[this].vel.y = -bodies[this].vel.y/2;  //slow down a bit
	}
	if(bodies[this].pos.y >= HEIGHT )
	{
		bodies[this].pos.y = HEIGHT;
		bodies[this].vel.y = -bodies[this].vel.y/2;  
	}
	
	#endif
	
	
	printf("(%d)  [%d %d]  {%lf %lf} <%lf %lf>  \n", this, (int)bodies[this].pos.x, (int)bodies[this].pos.y, bodies[this].vel.x, bodies[this].vel.y, acc.x, acc.y);
	
}



void update(body_t *bodies, int count)
{
	int i=0;
	#pragma omp parallel for
	for(i=0; i<count; i++)
	{
		updatebody(bodies, count, i);
	}
}


int main()
{
	
	
	
	
	
      // Open the display
      Display *dpy = XOpenDisplay(NIL);
      assert(dpy);

      // Get some colors
      int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
      int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

      // Create the window
      Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 
				     WIDTH, HEIGHT, 0, blackColor, blackColor);

      // We want to get MapNotify events
      XSelectInput(dpy, w, StructureNotifyMask);

      // "Map" the window (that is, make it appear on the screen)
      XMapWindow(dpy, w);

      // Create a "Graphics Context"
      GC gc = XCreateGC(dpy, w, 0, NIL);

      // Tell the GC we draw using the white color
      XSetForeground(dpy, gc, whiteColor);

      // Wait for the MapNotify event
      for(;;)
      {
	    XEvent e;
	    XNextEvent(dpy, &e);
	    if (e.type == MapNotify)
		  break;
      }
	printf("WE R HERE");
   int ox = WIDTH/2;
	int oy = HEIGHT/2;
	
	int num_of_bodies = NUM_OF_BODIES;
	int max_mass = MAX_MASS;
	int max_vel = 100;
	
/*
	body_t bodies[num_of_bodies];
	
	int j=0;
	for(j=0; j<num_of_bodies; j++)
	{
		bodies[j].mass = 100;//rand() % max_mass;
		//bodies[j].pos.x = (rand() % (WIDTH-200))+100;
		//bodies[j].pos.y = (rand() % (HEIGHT-200))+100;
		bodies[j].pos.x = (rand() % WIDTH);
		bodies[j].pos.y = (rand() % HEIGHT);
		
		bodies[j].vel.x = 0;//(rand()%max_vel) - max_vel/2;
		bodies[j].vel.y = 0;//(rand()%max_vel) - max_vel/2;
		
		bodies[j].exists = 1;
	}
	*/

	
	body_t bodies[] = { 
						{400000, 1, {ox, oy}, {0, 0}},
						
						{200, 1, {ox+300, oy}, {0, +65}},
						{5, 1, {ox+300, oy+10}, {+10, +65}},
						
						{10, 1, {ox+50, oy}, {0, +200}},
						
						
						{10, 1, {ox+150, oy}, {0, +100}},
						
					};

	
	int count = sizeof(bodies)/sizeof(bodies[0]);
	
	//printf("count = %d   randmax=%d\n", count, RAND_MAX);

	
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	int i=0;
	unsigned long long int iter = 0;
	
	while(1)
	{
		//printf("%llu\n", ++iter);
		
		
		//if(iter %100 == 0)
		{
			//printf("DISPNOW\n");
			//XClearWindow(dpy, w);
			for(i=0; i<count; i++)
			{
				if(bodies[i].exists==1)
				{
					XDrawPoint(dpy, w, gc, bodies[i].pos.x, bodies[i].pos.y);
				}
				else
				{
					//printf("not exists");
				}
			}
			
			XFlush(dpy);
		}
		usleep(1000);
		update(bodies, count);
		
		/*
		iter++;
		if(iter == 500)
		{
			gettimeofday(&end, NULL);
			break;
		}
		*/
	
	}
	
	int millisec = (end.tv_sec*1000 + end.tv_usec/1000)-(start.tv_sec*1000 + start.tv_usec/1000);
	printf("execution time = %d ms\n", millisec);
	
}
