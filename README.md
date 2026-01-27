# cymbalamp

A C program for a cymbal lamp. Made for the Raspberry Pi Pico.

Here goes a diagram for the circuit: 


                          +24V SUPPLY
                              |
                              |
                        +-------------+
                        |   24V LOAD                          +24V SUPPLY
                              |
                              |
                        +-------------+
                        |   24V LOAD  |
                        | (Lamp/etc.) |
                        +-------------+
                              |
                              |
                           [DRAIN]
                        +-------------+
                        |  N-MOSFET   |
                        | (Low-side)  |
                        +-------------+
                           [SOURCE]
                              |
                             GND
                              |
   ---------------------------------------------------------
                              |
                             GND (Common)
                              |
   ---------------------------------------------------------

                      LOGIC / CONTROL SIDE

+24V -----> [7805 REGULATOR] -----> +5V
                                      |
                                      |
                                  +--------+
                                  |  PICO  |
                                  |        |
                                  | GPIO x |----[R]---->|----+
                                  +--------+     (gate)      |
                                                             |
                                                   (Gate pull
                                                    down / ref)
                                                             |
                                                            GND

                     PROGRAM / MODE SELECT

        +5V
         |
        [R]
         |
      o--+--o   <--- Switch A
         |
      o--+--o   <--- Switch B
         |
        GND

      (Switch feeds Pico input pins)

  |
                        | (Lamp/etc.) |
                        +-------------+
                              |
                              |
                           [DRAIN]
                        +-------------+
                        |  N-MOSFET   |
                        | (Low-side)  |
                        +-------------+
                           [SOURCE]
                              |
                             GND
                              |
   ---------------------------------------------------------
                              |
                             GND (Common)
                              |
   ---------------------------------------------------------

                      LOGIC / CONTROL SIDE

+24V -----> [7805 REGULATOR] -----> +5V
                                      |
                                      |
                                  +--------+
                                  |  PICO  |
                                  |        |
                                  | GPIO x |----[R]---->|----+
                                  +--------+     (gate)      |
                                                             |
                                                   (Gate pull
                                                    down / ref)
                                                             |
                                                            GND

                     PROGRAM / MODE SELECT

        +5V
         |
        [R]
         |
      o--+--o   <--- Switch A
         |
      o--+--o   <--- Switch B
         |
        GND

      (Switch feeds Pico input pins)

