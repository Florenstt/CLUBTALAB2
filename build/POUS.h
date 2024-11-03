#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(BOOL,BOTON)
  CTU CTU0;
  __DECLARE_VAR(BOOL,M1)
  __DECLARE_VAR(BOOL,M2)
  __DECLARE_VAR(BOOL,M3)
  __DECLARE_VAR(BOOL,M4)
  __DECLARE_VAR(BOOL,M5)
  __DECLARE_VAR(BOOL,M6)
  __DECLARE_VAR(BOOL,M7)
  __DECLARE_VAR(BOOL,M8)
  __DECLARE_VAR(BOOL,M9)
  __DECLARE_VAR(BOOL,SEMAFORO1)
  __DECLARE_VAR(BOOL,SEMAFORO2)
  __DECLARE_VAR(BOOL,SEMAFORO3)
  __DECLARE_VAR(BOOL,P1)
  __DECLARE_VAR(BOOL,P2)
  __DECLARE_VAR(BOOL,P3)
  __DECLARE_VAR(BOOL,P4)
  __DECLARE_VAR(BOOL,P5)
  __DECLARE_VAR(BOOL,P6)
  __DECLARE_VAR(BOOL,P7)
  __DECLARE_LOCATED(BOOL,L1)
  __DECLARE_LOCATED(BOOL,L2)
  __DECLARE_LOCATED(BOOL,L3)
  TON TON0;
  TON TON1;
  CTU CTU1;
  CTU CTU2;
  TON TON2;
  SR SR1;
  TON TON3;
  TON TON4;
  TON TON5;
  SR SR2;
  SR SR3;
  TON TON6;
  CTU CTU3;
  TON TON7;
  SR SR4;
  CTU CTU4;
  TON TON8;
  SR SR5;
  CTU CTU5;
  TON TON9;
  R_TRIG R_TRIG1;
  R_TRIG R_TRIG2;
  R_TRIG R_TRIG3;
  R_TRIG R_TRIG4;
  R_TRIG R_TRIG5;
  R_TRIG R_TRIG6;

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
