// --------------------------------------------------------------------//
// standard library code
// --------------------------------------------------------------------//

#include "firmware.c"
#include "define.h"
#include "global.h"
#include "heartbeat.c"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "25LC512_wdt.c"
#include "eeprom.c"
#include "messages.c"
#include "sd_min.c"
#include "rtc.c"
#include "max525.c"
#include "adc.c"
#include "interrupts.c"
#include "serial.c"
#include "init_hw.c"
#include "util.c"
#include "stepper.c"
#include "h-bridge.c"
#include "sleep.c"
#include "reset.c"
#include "memory.c"
#include "init_vars.c"
#include "detector.c"
#include "colorimeter.c"
#include "aws.c"
#include "data.c"
#include "macros.c"
#include "macro_wms.c"
#include "macro_aws.c"
#include "auto.c"
#include "command.c"
