#int_ext
void rtc_wakeup_isr()
{
//   delay_cycles(10);       // mo ???
   rtc_alarm = TRUE;
   sleep_mode = FALSE;

   while (TRUE == RTC_read_flags_running)
   {
      ;
   }
   RTC_read_flags_running = TRUE;
   RTC_read_flags();
   ++nv_elapsed;
}

#int_RDA
void RDA_isr()
{
   int8 c;

   clear_interrupt(INT_RDA);

   if (FALSE == sleep_mode)
   {
      if (kbhit(COM_A))
      {
         c = getc(COM_A);
         switch (c)
         {
            case QUESTION_MRK:
            {
               if (busy_status == TRUE) fprintf(COM_A, "?@BSY\r\n");
               else fprintf(COM_A, "@RDY\r\n");
               break;
            }
            case DEVICE_CNTRL_1:
            {
               user_quit = TRUE;
               break;         
            }
            case ESCAPE:
            {
               nv_cmd_mode = TRUE;
               break;                
            }
         }
      }
   }
   // if asleep and char received
   else
   {
      // signal that wake-up was serial (not positive wake-up yet)
      bit_clear(INTCON,PEIE);    // Disable Peripheral Interrupt Enable bit
      bit_clear(PIR1,RC1IF);     // Clear USART Receive Interrupt Flag bit
   }
}

void busy_clear()
{
   disable_interrupts(INT_RDA);
   clear_interrupt(INT_RDA);
   busy_status = FALSE;
}

void busy_set()
{
   busy_status = TRUE;
   clear_interrupt(INT_RDA);
   enable_interrupts(INT_RDA);
}

/*#int_rda2
void serial2_isr()
{
   int t;

   buffer[next_in] = fgetc(COM_B);
   t=next_in;
   next_in = (next_in+1) % BUFFER_SIZE;
   if(next_in == next_out)
   {
      next_in = t;           // Buffer full !!
   }
}
*/

/*
   This interrupt should fire before the WDT barks
   .. it will reset the timer and the WDT
*/
#int_timer0
void timer0_isr()
{
//   heartbeat(TRUE);

   set_timer0(TIMER0_PRESET);
   restart_wdt();
   clear_interrupt(INT_TIMER0);
   enable_interrupts(INT_TIMER0);

   set_timer1(0);
   output_high(BOARD_LED);                // LED is turned OFF by timer1_isr()
   if(nv_product==AWS)output_high(PANEL_LED); 
   clear_interrupt(INT_TIMER1);
   enable_interrupts(INT_TIMER1);
   
  // fprintf(COM_A, "*");

}

#int_timer1
void timer1_isr()
{
   // disables timer1 ints, LED OFF (to end "blink")
   // this ISR is triggered ~105 ms after LED ON by timer0_isr()
   disable_interrupts(INT_TIMER1);
   output_low(BOARD_LED);
   if(nv_product==AWS)output_low(PANEL_LED);  
}

//!#int_timer4
//!void tick_interrupt(void) { 
//!   if (tick) --tick; 
//!   else {
//!      timeout=TRUE;
//!      exit=TRUE;
//!   }      
//!}

