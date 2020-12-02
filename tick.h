#ifndef _TICK_H_
#define _TICK_H_

#define TICK_IS_RESETTABLE 1


// Tick initialization
void tickInit(void);

// Tick reset
// Should be used with particular care
// May cause inconsistencies if the system tick
// is used to implement events (see next example)
void tickReset(void);

// Tick read
// Returns the number of ticks since last reset
unsigned long int tickGet(void);
#endif
