#include<stdio.h>
#include<stdlib.h>
#define ENGINE_TEMP_CONTROLLER 1


struct specification{
		char traffic_light;
		short vehicle_speed;
		short ac_temperature;
		short room_temperature;
		short engine_temperature;
		short engine_controller;
	}s1;

enum Engine_temperature_controller etc;
enum system_start state;
enum ac ac_state;

enum Engine_temperature_controller{
	offf,onn
};
enum system_start{
	quit=0,turn_on=1,turn_off=2
};
enum ac{
	off,on
};

int system_state();
void check_state(int check);
void display_menu();
void set_traffic_light();
void set_room_temperature();
void display();
#if ENGINE_TEMP_CONTROLLER==1
void set_engine_temperature();
void check_speed();
#endif
int main()
{
	state=system_state();
	display_menu();
	return 0;
}
int system_state()
{
	int result;
	printf("Turn on press: 1 \n");
	fflush(stdout);
	printf("Turn off press: 2 \n");
	fflush(stdout);
	printf("Quit the system press: 0 \n");
	fflush(stdout);
	scanf("%d",&result);
	check_state(result);
	return result;
}
void check_state(int check)
{
	switch(check)
	{
	case 0:
		printf("system status: quit system \n");
		exit(0);
		break;
	case 1:
		printf("system status: system on \n");
		break;
	case 2:
		printf("system status: system off \n");
		do
		{
			check=system_state();
		}while(check ==turn_off);
		check_state(check);
		break;
	}
}
void display_menu()
{
	char res;
	for(;;)
	{
	printf("a.Turn off the engine \n");
	fflush(stdout);
	printf("b.Set the traffic light \n");
	fflush(stdout);
	printf("c.Set the room temperature \n");
	fflush(stdout);
#if ENGINE_TEMP_CONTROLLER==1
	printf("d.Set the engine temperature \n \n");
	fflush(stdout);
#endif
	scanf(" %c",&res);
	fflush(stdin);
	switch(res)
	{
		case('a'):
			system_state();
			break;
		case('b'):
			set_traffic_light();
			break;
		case('c'):
			set_room_temperature();
			break;
#if ENGINE_TEMP_CONTROLLER==1
		case('d'):
			set_engine_temperature();
			break;
#endif
	}
	}
}
void set_traffic_light()
{
	printf("Enter traffic light");
	fflush(stdout);
	scanf(" %c",&s1.traffic_light);
	switch(s1.traffic_light){
		case('g'):
				s1.vehicle_speed=100;
				break;
		case('o'):
				s1.vehicle_speed=30;
				break;
		case('r'):
				s1.vehicle_speed=0;
				break;
	}
#if ENGINE_TEMP_CONTROLLER==1
	check_speed();
#endif
	display();
}
void set_room_temperature()
{
	printf("Enter temperature");
	fflush(stdout);
	scanf("%hd",&s1.room_temperature);
	if(s1.room_temperature <10)
	{
		ac_state=on;
		s1.ac_temperature=20;
	}
	else if(s1.room_temperature >30)
	{
		ac_state=on;
		s1.ac_temperature=20;
	}
	else
	{
		ac_state=off;
	}
#if ENGINE_TEMP_CONTROLLER==1
	check_speed();
#endif
	display();
}
#if ENGINE_TEMP_CONTROLLER==1
void set_engine_temperature()
{
	printf("Enter temperature");
	fflush(stdout);
	scanf("%hd",&s1.engine_temperature);
	if(s1.engine_temperature <100)
	{
		etc=onn;
		s1.engine_controller=20;
	}
	else if(s1.room_temperature >150)
	{
		etc=onn;
		s1.engine_controller=20;
	}
	else
	{
		etc=off;
	}
	check_speed();
	display();
}
#endif
void display()
{
	if(state==quit)
	{
		printf("Engine state is off. \n");
		fflush(stdout);
	}
	else if(state==turn_on)
	{
		printf("Engine state is on. \n");
		fflush(stdout);
	}
	if(ac_state==off)
	{
		printf("AC: off. \n");
		fflush(stdout);
	}
	else if(ac_state==on)
	{
		printf("AC: on. \n");
		fflush(stdout);
	}

	printf("Vehicle speed = %d kM/HR \n",s1.vehicle_speed);
	fflush(stdout);
	printf("Room temperature = %d C \n",s1.room_temperature);
	fflush(stdout);
#if ENGINE_TEMP_CONTROLLER==1
	if(etc==offf)
	{
		printf("Engine controller state: off. \n");
		fflush(stdout);
	}
	else if(etc==onn)
	{
		printf("Engine controller state: on. \n");
		fflush(stdout);
	}
	fflush(stdout);
	printf("Engine temperature = %d C \n \n",s1.engine_temperature);
	fflush(stdout);
#endif
}
#if ENGINE_TEMP_CONTROLLER==1
void check_speed()
{
	if(s1.vehicle_speed==30)
	{
		ac_state=on;
		s1.room_temperature=s1.room_temperature*(5/4)+1;
		etc=onn;
		s1.engine_temperature=s1.engine_temperature*(5/4)+1;
	}
}
#endif
