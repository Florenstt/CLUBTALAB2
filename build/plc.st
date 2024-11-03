TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR
    boton AT %IX0.0 : BOOL;
  END_VAR
  VAR
    CTU0 : CTU;
    M1 : BOOL;
    M2 : BOOL;
    M3 : BOOL;
    M4 : BOOL;
    M5 : BOOL;
    m6 : BOOL;
    m7 : BOOL;
    m8 : BOOL;
    M9 : BOOL;
    Semaforo1 : BOOL;
    Semaforo2 : BOOL;
    Semaforo3 : BOOL;
    P1 : BOOL;
    P2 : BOOL;
    P3 : BOOL;
    P4 : BOOL;
    P5 : BOOL;
    P6 : BOOL;
    P7 : BOOL;
  END_VAR
  VAR
    L1 AT %QX0.0 : BOOL;
    L2 AT %QX0.1 : BOOL;
    L3 AT %QX0.2 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    TON1 : TON;
    CTU1 : CTU;
    CTU2 : CTU;
    TON2 : TON;
    SR1 : SR;
    TON3 : TON;
    TON4 : TON;
    TON5 : TON;
    SR2 : SR;
    SR3 : SR;
    TON6 : TON;
    CTU3 : CTU;
    TON7 : TON;
    SR4 : SR;
    CTU4 : CTU;
    TON8 : TON;
    SR5 : SR;
    CTU5 : CTU;
    TON9 : TON;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    R_TRIG5 : R_TRIG;
    R_TRIG6 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := boton);
  TON6(IN := M9, PT := T#3s);
  CTU1(CU := R_TRIG1.Q, R := TON6.Q, PV := 2);
  M2 := CTU1.Q;
  R_TRIG2(CLK := boton);
  CTU2(CU := R_TRIG2.Q, R := TON6.Q, PV := 5);
  M5 := CTU2.Q;
  TON2(IN := CTU2.Q, PT := T#8s);
  SR1(S1 := TON2.Q, R := P1 OR P2 OR P3 OR P4 OR P6 OR P7);
  TON4(IN := Semaforo1 AND SR1.Q1, PT := T#2s);
  Semaforo2 := TON4.Q;
  TON5(IN := Semaforo2 AND SR1.Q1, PT := T#2s);
  Semaforo3 := TON5.Q;
  R_TRIG3(CLK := boton);
  CTU0(CU := R_TRIG3.Q, R := TON6.Q, PV := 1);
  TON0(IN := CTU0.Q, PT := T#8s);
  P1 := NOT(M5) AND NOT(M4) AND NOT(M3) AND NOT(M2) AND TON0.Q;
  TON1(IN := CTU1.Q, PT := T#8s);
  P2 := NOT(M3) AND NOT(M5) AND NOT(M4) AND TON1.Q;
  P5 := TON2.Q;
  R_TRIG4(CLK := boton);
  CTU3(CU := R_TRIG4.Q, R := TON6.Q, PV := 3);
  M3 := CTU3.Q;
  TON7(IN := CTU3.Q, PT := T#8s);
  P3 := NOT(M4) AND NOT(M5) AND TON7.Q;
  R_TRIG5(CLK := boton);
  CTU4(CU := R_TRIG5.Q, R := TON6.Q, PV := 4);
  M4 := CTU4.Q;
  TON8(IN := CTU4.Q, PT := T#8s);
  P4 := NOT(M5) AND TON8.Q;
  R_TRIG6(CLK := boton);
  CTU5(CU := R_TRIG6.Q, R := TON6.Q, PV := 6);
  P6 := CTU5.Q;
  TON9(IN := SR1.Q1, PT := T#20s);
  P7 := TON9.Q;
  SR2(S1 := NOT(M5) AND NOT(M4) AND NOT(M3) AND NOT(M2) AND TON0.Q, R := P2 OR P3 OR P4 OR P5 OR P6);
  SR4(S1 := NOT(M4) AND NOT(M5) AND TON7.Q, R := P1 OR P2 OR P4 OR P5 OR P6);
  L1 := SR2.Q1 OR SR4.Q1 OR NOT(Semaforo1) AND SR1.Q1;
  SR5(S1 := NOT(M5) AND TON8.Q, R := P1 OR P2 OR P3 OR P5 OR P6);
  L2 := SR2.Q1 OR SR5.Q1 OR NOT(Semaforo2) AND Semaforo1 AND SR1.Q1;
  SR3(S1 := NOT(M3) AND NOT(M5) AND NOT(M4) AND TON1.Q, R := P1 OR P3 OR P4 OR P5 OR P6);
  L3 := SR2.Q1 OR SR3.Q1 OR SR4.Q1 OR SR5.Q1 OR Semaforo2 AND SR1.Q1;
  TON3(IN := NOT(Semaforo3) AND SR1.Q1, PT := T#2s);
  Semaforo1 := TON3.Q;
  M9 := CTU5.Q OR TON2.Q OR NOT(M4) AND NOT(M5) AND TON7.Q OR NOT(M5) AND NOT(M4) AND NOT(M3) AND NOT(M2) AND TON0.Q OR NOT(M5) AND TON8.Q OR NOT(M3) AND NOT(M5) AND NOT(M4) AND TON1.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
