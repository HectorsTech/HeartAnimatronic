# Realistic Silicone Animatronic Heart

Welcome to the repository for the Realistic Silicone Animatronic Heart project! This project details the construction of a highly realistic, beating animatronic heart.

Compared to simpler designs, this version features a more complex mechanism with three independently moving servos. Controlled by an Arduino Micro and a potentiometer, the heart uses step functions to create a natural-looking motion—gradually filling and then quickly contracting in sequence. The speed of the heartbeat is fully adjustable via the potentiometer.

This is an advanced project that involves intricate mechanical assembly and silicone casting.

## ⚠️ Important Considerations

*   **Complexity:** This project involves tricky assembly, soldering in tight spaces, and intermediate-to-advanced 3D printing and casting techniques.
*   **Hardware Variants:** The code provided is specific to the type of servos used. Please read the assembly instructions carefully to ensure you use the correct Arduino sketch.

## 🛠️ Supplies & Bill of Materials

### Mechanism Components

*   **Microcontroller:** Arduino Micro
*   **Servo Driver:** PCA9685 16-channel servo driver board (or equivalent)
*   **Servos (x3):** DS-843MG servos are *highly recommended* for their strength, which is necessary to stretch the silicone skin. (MG90s servos are supported, but less ideal).
*   **Control:** 10K Potentiometer
*   **Power Input:** 5.5mm DC panel input jack
*   **Power Supply:** 5V DC power supply (must be capable of handling the current draw of 3 high-torque servos)
*   **Hardware:** Various metric screws (M1 to M3)
*   **Wiring:** Jumper cables, slightly thicker wire for the power lines

### Casting Materials

*   **Skin:** 500g Platsil Gel 00 (or equivalent ultra-soft silicone)
*   **Mold:** 2kg Tinsil 7025 (or equivalent mold-making silicone)
*   **Release Agent:** Ease Release 205 (or equivalent)
*   **Coloring:** Silicone pigment in dark red
*   **Mold Box:** A suitable container (can be constructed using hot glue and styrene or similar materials)

### Other Tools & Materials

*   3D Printer and filament (PLA/PETG)
*   Airbrush and acrylic paints (for detailing)
*   Pin vice hand drill
*   Soldering Iron & solder
*   Electrical tape / Heat shrink tubing
*   Fake blood (for final presentation)

## 🖨️ Step 1: 3D Printing

There are no strict material requirements for the prints, only that the structural components be reasonably high-resolution and high-strength.

*   **Layer Height:** ~0.2mm is recommended for most structural parts. The outer shell parts can be printed at a lower resolution.
*   **Supports:** The only parts that typically require supports are the outer shell components.
*   **Base Assembly:** The main base is split into two parts for easier printing. They should be glued together and aligned using two M2 x 10mm screws.

*(Refer to the `.stl` files in the repository for all printable components).*

## ⚙️ Step 2: Assembly Guide

The assembly is compact and can be fiddly. It is highly recommended to reference the project video and images throughout this process.

### 1. Servo Installation

Start by inserting the three servos into the base.
*   **Bottom Pair:** Feed the wires through the slots in the base component (you may need to temporarily remove the plastic connector housing on the end of the wire). Secure the servos with M2 x 10mm screws. If using DS-843MG servos, use the small plastic adaptors to fit the M2 screws into the M3 mounting holes.
*   **Top Servo:** This is a tighter fit. You will need to carefully remove the base plate of the servo (where the wire protrudes) to maneuver it into place. Once seated, screw the base plate back on. The design allows for one screw to secure this top servo, but the friction fit should hold it securely.

### 2. Construct the Arm Linkages

1.  Take a standard servo horn and cut it down so only two holes remain.
2.  Attach two "long link" components to the second hole (furthest from the center) of the horn and screw them in.
3.  Take an opposing pair of "arm" components and screw the "long links" to their flat sides.
4.  **Crucial:** Leave these joints loose enough to move freely without binding.
5.  Create two of these sub-assemblies and attach them to the base using an M3 x 10mm screw for each arm.

### 3. Construct the Top Servo Linkage

1.  Use a two-sided servo horn, cutting it down to leave only two holes per side.
2.  Attach a "short link" on the outermost holes, screwing upwards from the bottom using two M2 x 4mm screws. Leave these joints loose enough to pivot.
3.  Use two more M2 x 4mm screws inserted in the opposite direction through the short links to connect to the "rocker" component later.
4.  Attach the "rocker" component to the top of the base using an M3 x 20mm screw.

### 4. Prepare the Servo Driver Board (PCA9685)

Due to space constraints, you cannot use the standard screw terminal block on the PCA9685.
1.  Solder a positive and negative wire (roughly 40cm long) directly to the power input pads on the driver board.
2.  Mount the board to the base. Use M3 screws on the left side (it will be tight) or M2 screws with nuts. On the right side, use ~12mm M2 screws extending up from the bottom of the base, through the board, and into the "micro standoff" component.
3.  Plug the servos into the appropriate channels on the board (refer to project images for the specific channel layout).

### 5. Assemble the Back-Plate

1.  Mount the potentiometer and the DC power input jack into the holes on the back-plate (use washers if necessary for the potentiometer).
2.  Solder the positive and negative power wires originating from the PCA9685 directly to the terminals of the DC input jack.
3.  Wire the potentiometer: Solder two positive and two negative wires (to share power/ground with the Arduino), and one wire for the signal pin. Using jumper cables with one female end and one stripped end makes connecting to the Arduino and driver board easier.
4.  Attach the back-plate to the main base using three M3 x 20mm screws. *Take care not to pinch any wires.* Ensure the DC input is on the right side, and carefully tuck the top servo wires between the DC input and the servo body.

### 6. Program the Microcontroller

The Arduino Micro generates the heartbeat cycle. The code uses a step function with a sine-wave interval to create a slow expansion and rapid contraction. The speed is modulated by reading the potentiometer.

> [!CAUTION]
> **Code Versions:** Ensure you upload the correct code for your hardware:
> *   `Heart_Beater_Inverted.ino`: Use this if you are using the recommended **DS-843MG** servos.
> *   `Heart_Beater.ino`: Use this if you are using standard **MG90s** servos.

*Recommendation:* Before installing the Arduino into the model, wire everything up on a breadboard to verify the circuit and code logic. It is very difficult to troubleshoot once fully assembled.

### 7. Calibrate and Attach the Servo Horns

This is a delicate but crucial step to ensure the mechanism moves correctly without destroying itself.

1.  Power up the system and ensure the servos are moving based on the code.
2.  Turn the potentiometer to slow the motion down to the absolute minimum speed.
3.  **The Catch:** Unplug the power at the exact moment the servos pause *immediately after* the quick contraction phase.
4.  At this point, the bottom servos are in their "contracted" state. Carefully attach the bottom servo horns so that the arms are pulled close together, almost touching.
5.  The top servo will be in its most counter-clockwise position. Attach its horn so that the "rocker" component is also at its most counter-clockwise limit.
6.  *Note:* You will likely need to test, power off, adjust the horns, and re-test several times to get the alignment perfect.

### 8. Wire the Microcontroller

1.  Attach the insulating plate to the bottom of the Arduino Micro using tiny M1 screws (or electrical tape).
2.  Mount the Arduino to the standoff above the servo driver board using M1 screws. **Note that the Arduino mounts upside down in this design.**
3.  Wire the Arduino to the PCA9685 and the potentiometer according to the circuit diagram.
4.  If using standard jumper wires, you may need to remove the plastic housings from the SDA and SCL pins so they can be bent cleanly out of the way of the moving parts. Insulate them with heat shrink or tape.
5.  Carefully pack all wiring into the space between the Arduino and the servo board.
6.  Power it on and test the potentiometer control!

### 9. Final Structural Assembly

Once the mechanics are tested and working perfectly, attach the outer side panels to the model using M2 x 6mm screws.
