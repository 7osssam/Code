#ifndef timer_config
#define timer_config

/*
TMR0_NORMAL_MODE
TMR0_PHASE_CORRECT_MODE
TMR0_CTC_MODE
TMR0_FAST_PWM_MODE
*/
#define TMR0_MODE TMR0_NORMAL_MODE
/*
TMR0_NON_INVERTING
TMR0_INVERTING
*/
#define TMR0_PWM_MODE TMR0_NON_INVERTING

// Select Preload Value if needed
#define TMR0_PRELOAD_VALUE 25
// Select CTC Value
#define TMR0_CTC_VALUE 0
/*
TMR0_CASE_1
TMR0_CASE_2
TMR0_CASE_3
*/
#define TMR0_CASE TMR0_CASE_3
// Select ISR Calculated Value for case 3
#define TMR0_ISR_VALUE 4
// Select ISR Calculated Preload Value for case 3
#define TMR0_ISR_PRELOAD_VALUE 25

/*Configuration for timer1*/

#define TMR1_MODE TMR1_FAST_PWM_MODE
#define TMR1_PWM_MODE TMR1_NON_INVERTING
#define TMR1_CHANNAL TMR1_CHANNAL_A
#endif
