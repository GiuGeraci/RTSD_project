#define EMERGENCY_BRAKE 1<<11
#define BRAKE_3 1<<10
#define BRAKE_2 1<<9
#define BRAKE_1 1<<8
#define ACCELERATION_3 1<<2
#define ACCELERATION_2 1<<1
#define ACCELERATION_1 1<<0
#define IDLE 0<<0;

// imposta l'accelerazione a 3
void set_acc_3(void);

// imposta l'accelerazione a 2
void set_acc_2(void);

// imposta l'accelerazione a 1
void set_acc_1(void);

// imposta il treno ad idle
void idle(void);

// imposta la frenata a 1
void set_brake_1(void);

// imposta la frenata a 2
void set_brake_2(void);

// imposta la frenata a 3
void set_brake_3(void);

// imposta la frenata di emergenza
void emergency_brake(void);
