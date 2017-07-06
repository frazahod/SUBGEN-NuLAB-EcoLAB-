//

// non-volatile

// user settings
int16 nv_report_mode;               // verbose / debug feedback
int16 nv_sample;                    // sample counter
int16 nv_interval;                  // sample interval (mins)
int16 nv_serial;                    // unit serial number
int16 nv_max_samples;               // max number of samples
int16 nv_macro_mode;                // WMS hard/user macros
int16 nv_volume;                    // WMS syringe steps per sample
int16 nv_port;                       // WMS port
// code settings
int16 nv_product;                   // type of product (EcoLAB, etc.)
int16 nv_cmd_mode;                  // command mode or sampling mode
int16 MaxSamples;                   // Max Sample counter flag
int16 nv_elapsed;                   // time elapsed since last sample
int16 nv_macro_step;                // step counter for master macro
int16 valve_align_timeout = -1;
int16 valve_align_counter = -1;
// stepper
int16 nv_com_err;                    // invalid comm response counter 
// sd card
int16 nv_sd_status;
int16 nv_d1_temp;
int16 nv_d2_temp;
int16 nv_det_type = 1;                  // 1=RS232 / 2=ATD(SIMPLE) / 3=MCL(SAR) 

// volatile

char cmd;
int32 arg;
int8 com_echo = TRUE;
int1 rtc_alarm = FALSE;
int8 busy_status;
int1 sleep_mode = FALSE;
int1 RTC_read_flags_running = FALSE;
int8 RTCfmt;
int8 user_quit;
int8 cmd_set;
//int8 wakeup_mode;  // Mo previously removed with new RTC interrupt code

char sub_string[20];
int8 buffer_select = 0;                 // indicates buffer to SD card append
char data_buffer[BUFFER_LEN];           // buffer_select = 0
char event_buffer[BUFFER_LEN];          // buffer select = 1
char event_str[BUFFER_LEN]; 
char slave_reply[SLAVE_REPLY_CHARS];
int8 string_pos;
char time_stmp_str[30];
char proc_time_stmp_str[30];

int8 detector;
int8 detector_ch;
int16 detector_li;
int8 LightTargetFlag=1;


// WMS
int8 start_even_port;
int8 end_even_port;

// sd card
int8 sd_status;
char file_ptr_raw_all[14] = DATA_RAW_ALL;
char file_ptr_raw_new[14] = DATA_RAW_NEW;
char file_ptr_rel_all[14] = DATA_REL_ALL;
char file_ptr_rel_new[14] = DATA_REL_NEW;  
char file_ptr_events[14]  = EVENT_FILE; 

// volatile
int16 macro_flag;
char flag_str[20];
char comma[2] ={',','\0'};
int8 data_available = FALSE;

// chem, analysis & reading type vars
int8 channel;
char chem[5];
char anal[4];
char read_t[4];
int8 read_i;
// data arrays for Abs/Conc.
// Br,Rr,Bs,Rs,Bt,Rt,Bu,Ru
int16 NO3_array[9];
int16 NO2_array[9];
int16 PO4_array[9];
int16 NH4_array[9];
int16 SiO_array[9];
// calculated data arrays
float NO3_abs_array[4];
float NO2_abs_array[4];
float PO4_abs_array[4];
float NH4_abs_array[4];
float SiO_abs_array[4];
// coeffs
float NO3_slope;
float NO3_inter;
float PO4_slope;
float PO4_inter;
float NH4_slope;
float NH4_inter;
float SiO_slope;
float SiO_inter;
// concentrations
float NO3_smp_conc;
float PO4_smp_conc;
float NH4_smp_conc;
float SiO_smp_conc;
// strings for "rel" data file
char abs_str[68];
char coeff_str[30];
char real_str[30];

int16 ADC_val[8];                     // ADC result
int8  heater_stat;

// AWS
int8 bus_pwr_status;
int8 valve_status[33];


