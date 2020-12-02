#include "lever.h"
#include <stm32f10x.h>  

void set_acc_3(){
	GPIOC->ODR = ACCELERATION_3;
}

void set_acc_2(){
	GPIOC->ODR = ACCELERATION_2;
}

void set_acc_1(){
	GPIOC->ODR = ACCELERATION_1;
}

void idle(){
	GPIOC->ODR = IDLE;
}

void set_brake_1(){
	GPIOC->ODR = BRAKE_1;
}

void set_brake_2(){
	GPIOC->ODR = BRAKE_2;
}

void set_brake_3(){
	GPIOC->ODR = BRAKE_3;
}

void emergency_brake(){
	GPIOC->ODR = EMERGENCY_BRAKE;
}
