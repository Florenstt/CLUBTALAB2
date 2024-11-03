void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_0,data__->BOTON,retain)
  __INIT_LOCATED_VALUE(data__->BOTON,__BOOL_LITERAL(FALSE))
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->M1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M8,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M9,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEMAFORO1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEMAFORO2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEMAFORO3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P7,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__QX0_0,data__->L1,retain)
  __INIT_LOCATED_VALUE(data__->L1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->L2,retain)
  __INIT_LOCATED_VALUE(data__->L2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->L3,retain)
  __INIT_LOCATED_VALUE(data__->L3,__BOOL_LITERAL(FALSE))
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  CTU_init__(&data__->CTU1,retain);
  CTU_init__(&data__->CTU2,retain);
  TON_init__(&data__->TON2,retain);
  SR_init__(&data__->SR1,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  TON_init__(&data__->TON5,retain);
  SR_init__(&data__->SR2,retain);
  SR_init__(&data__->SR3,retain);
  TON_init__(&data__->TON6,retain);
  CTU_init__(&data__->CTU3,retain);
  TON_init__(&data__->TON7,retain);
  SR_init__(&data__->SR4,retain);
  CTU_init__(&data__->CTU4,retain);
  TON_init__(&data__->TON8,retain);
  SR_init__(&data__->SR5,retain);
  CTU_init__(&data__->CTU5,retain);
  TON_init__(&data__->TON9,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  R_TRIG_init__(&data__->R_TRIG6,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_LOCATED(data__->BOTON,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->TON6.,IN,,__GET_VAR(data__->M9,));
  __SET_VAR(data__->TON6.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TON_body__(&data__->TON6);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->CTU1.,PV,,2);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,M2,,__GET_VAR(data__->CTU1.Q,));
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_LOCATED(data__->BOTON,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU2.,R,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->CTU2.,PV,,5);
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,M5,,__GET_VAR(data__->CTU2.Q,));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->CTU2.Q,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 8, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->SR1.,S1,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->SR1.,R,,(((((__GET_VAR(data__->P1,) || __GET_VAR(data__->P2,)) || __GET_VAR(data__->P3,)) || __GET_VAR(data__->P4,)) || __GET_VAR(data__->P6,)) || __GET_VAR(data__->P7,)));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->TON4.,IN,,(__GET_VAR(data__->SEMAFORO1,) && __GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON4);
  __SET_VAR(data__->,SEMAFORO2,,__GET_VAR(data__->TON4.Q,));
  __SET_VAR(data__->TON5.,IN,,(__GET_VAR(data__->SEMAFORO2,) && __GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->TON5.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON5);
  __SET_VAR(data__->,SEMAFORO3,,__GET_VAR(data__->TON5.Q,));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_LOCATED(data__->BOTON,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->CTU0.,PV,,1);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 8, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,P1,,((((!(__GET_VAR(data__->M5,)) && !(__GET_VAR(data__->M4,))) && !(__GET_VAR(data__->M3,))) && !(__GET_VAR(data__->M2,))) && __GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->CTU1.Q,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 8, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,P2,,(((!(__GET_VAR(data__->M3,)) && !(__GET_VAR(data__->M5,))) && !(__GET_VAR(data__->M4,))) && __GET_VAR(data__->TON1.Q,)));
  __SET_VAR(data__->,P5,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_LOCATED(data__->BOTON,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->CTU3.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTU3.,R,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->CTU3.,PV,,3);
  CTU_body__(&data__->CTU3);
  __SET_VAR(data__->,M3,,__GET_VAR(data__->CTU3.Q,));
  __SET_VAR(data__->TON7.,IN,,__GET_VAR(data__->CTU3.Q,));
  __SET_VAR(data__->TON7.,PT,,__time_to_timespec(1, 0, 8, 0, 0, 0));
  TON_body__(&data__->TON7);
  __SET_VAR(data__->,P3,,((!(__GET_VAR(data__->M4,)) && !(__GET_VAR(data__->M5,))) && __GET_VAR(data__->TON7.Q,)));
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_LOCATED(data__->BOTON,));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->CTU4.,CU,,__GET_VAR(data__->R_TRIG5.Q,));
  __SET_VAR(data__->CTU4.,R,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->CTU4.,PV,,4);
  CTU_body__(&data__->CTU4);
  __SET_VAR(data__->,M4,,__GET_VAR(data__->CTU4.Q,));
  __SET_VAR(data__->TON8.,IN,,__GET_VAR(data__->CTU4.Q,));
  __SET_VAR(data__->TON8.,PT,,__time_to_timespec(1, 0, 8, 0, 0, 0));
  TON_body__(&data__->TON8);
  __SET_VAR(data__->,P4,,(!(__GET_VAR(data__->M5,)) && __GET_VAR(data__->TON8.Q,)));
  __SET_VAR(data__->R_TRIG6.,CLK,,__GET_LOCATED(data__->BOTON,));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->CTU5.,CU,,__GET_VAR(data__->R_TRIG6.Q,));
  __SET_VAR(data__->CTU5.,R,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->CTU5.,PV,,6);
  CTU_body__(&data__->CTU5);
  __SET_VAR(data__->,P6,,__GET_VAR(data__->CTU5.Q,));
  __SET_VAR(data__->TON9.,IN,,__GET_VAR(data__->SR1.Q1,));
  __SET_VAR(data__->TON9.,PT,,__time_to_timespec(1, 0, 20, 0, 0, 0));
  TON_body__(&data__->TON9);
  __SET_VAR(data__->,P7,,__GET_VAR(data__->TON9.Q,));
  __SET_VAR(data__->SR2.,S1,,((((!(__GET_VAR(data__->M5,)) && !(__GET_VAR(data__->M4,))) && !(__GET_VAR(data__->M3,))) && !(__GET_VAR(data__->M2,))) && __GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->SR2.,R,,((((__GET_VAR(data__->P2,) || __GET_VAR(data__->P3,)) || __GET_VAR(data__->P4,)) || __GET_VAR(data__->P5,)) || __GET_VAR(data__->P6,)));
  SR_body__(&data__->SR2);
  __SET_VAR(data__->SR4.,S1,,((!(__GET_VAR(data__->M4,)) && !(__GET_VAR(data__->M5,))) && __GET_VAR(data__->TON7.Q,)));
  __SET_VAR(data__->SR4.,R,,((((__GET_VAR(data__->P1,) || __GET_VAR(data__->P2,)) || __GET_VAR(data__->P4,)) || __GET_VAR(data__->P5,)) || __GET_VAR(data__->P6,)));
  SR_body__(&data__->SR4);
  __SET_LOCATED(data__->,L1,,((__GET_VAR(data__->SR2.Q1,) || __GET_VAR(data__->SR4.Q1,)) || (!(__GET_VAR(data__->SEMAFORO1,)) && __GET_VAR(data__->SR1.Q1,))));
  __SET_VAR(data__->SR5.,S1,,(!(__GET_VAR(data__->M5,)) && __GET_VAR(data__->TON8.Q,)));
  __SET_VAR(data__->SR5.,R,,((((__GET_VAR(data__->P1,) || __GET_VAR(data__->P2,)) || __GET_VAR(data__->P3,)) || __GET_VAR(data__->P5,)) || __GET_VAR(data__->P6,)));
  SR_body__(&data__->SR5);
  __SET_LOCATED(data__->,L2,,((__GET_VAR(data__->SR2.Q1,) || __GET_VAR(data__->SR5.Q1,)) || ((!(__GET_VAR(data__->SEMAFORO2,)) && __GET_VAR(data__->SEMAFORO1,)) && __GET_VAR(data__->SR1.Q1,))));
  __SET_VAR(data__->SR3.,S1,,(((!(__GET_VAR(data__->M3,)) && !(__GET_VAR(data__->M5,))) && !(__GET_VAR(data__->M4,))) && __GET_VAR(data__->TON1.Q,)));
  __SET_VAR(data__->SR3.,R,,((((__GET_VAR(data__->P1,) || __GET_VAR(data__->P3,)) || __GET_VAR(data__->P4,)) || __GET_VAR(data__->P5,)) || __GET_VAR(data__->P6,)));
  SR_body__(&data__->SR3);
  __SET_LOCATED(data__->,L3,,((((__GET_VAR(data__->SR2.Q1,) || __GET_VAR(data__->SR3.Q1,)) || __GET_VAR(data__->SR4.Q1,)) || __GET_VAR(data__->SR5.Q1,)) || (__GET_VAR(data__->SEMAFORO2,) && __GET_VAR(data__->SR1.Q1,))));
  __SET_VAR(data__->TON3.,IN,,(!(__GET_VAR(data__->SEMAFORO3,)) && __GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON3);
  __SET_VAR(data__->,SEMAFORO1,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->,M9,,(((((__GET_VAR(data__->CTU5.Q,) || __GET_VAR(data__->TON2.Q,)) || ((!(__GET_VAR(data__->M4,)) && !(__GET_VAR(data__->M5,))) && __GET_VAR(data__->TON7.Q,))) || ((((!(__GET_VAR(data__->M5,)) && !(__GET_VAR(data__->M4,))) && !(__GET_VAR(data__->M3,))) && !(__GET_VAR(data__->M2,))) && __GET_VAR(data__->TON0.Q,))) || (!(__GET_VAR(data__->M5,)) && __GET_VAR(data__->TON8.Q,))) || (((!(__GET_VAR(data__->M3,)) && !(__GET_VAR(data__->M5,))) && !(__GET_VAR(data__->M4,))) && __GET_VAR(data__->TON1.Q,))));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





