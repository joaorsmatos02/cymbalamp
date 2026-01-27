# cymbalamp

A C program for a cymbal lamp. Made for the Raspberry Pi Pico.

Here goes a diagram for the circuit: 


POWER SIDE (24V)

   +24V
     |
     |
  [  LOAD  ]   (lamp / solenoid / etc.)
     |
     |
   DRAIN
  +-------+
  | NMOS  |   Low-side switch
  +-------+
   SOURCE
     |
    GND
     |
-------------------------------------------------
     |
    GND (COMMON)
     |
-------------------------------------------------


LOGIC / CONTROL SIDE (5V)

   +24V
     |
  [ 7805 ]
     |
    +5V
     |
  +--------+
  |  PICO  |
  |        |
  | GPIO --+--[R]--|>|--+---- Gate
  +--------+              |
                            |
                          [R] (pull-down)
                            |
                           GND


PROGRAM / MODE SELECT

   +5V
    |
   [R]
    |
 o--+--o    Switch position A
    |
 o--+--o    Switch position B
    |
   GND


