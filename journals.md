# Github Stats PUller Build Journal

## Jul 10, 2026, 3:23 AM

Ok so for now just adding the required  items for my stats puller but lets see cause i forgot how to use the breadboard so i need to see its config first 

nowww just looked up the esp32 and display connection and tried connecting it and added some setup code and now  i am checking for it if it is working or not

---

## Jul 10, 2026, 3:44 AM

justtt checking if its working or not but the code is not doing anything its literally not checking the if condition whyyyy is displayyy giving some error

---

## Jul 10, 2026, 6:59 AM

Nowww itsss showwss the text now i just need to configure how to fetch data from the github api lets seee

Now i am just gonna learn how to fetch data so might pause the timing for a little bit

---

## Jul 10, 2026, 8:03 AM

Now the query is good but i dont know whats the error i thought it was due to secure client but it is not thattt

---

## Jul 10, 2026, 12:12 PM

maannn forgot to record but just setup arduino ide and tried running the code and its verified via the ide 

whyyy is it not working here ig the simulator is different here and ther but how do i access wifi in thisss thinggg


Now itss wqorking alll thanks to tom and he helped me solve the secret issue thanksss man

---

## Jul 10, 2026, 12:29 PM

i just forgot about the x and y axis and tried to setup the display and the text over lapped badly

---

## Jul 10, 2026, 12:59 PM

i tried to get instagram api to fetch my profile stats but i guess its hard to get officially but i will try to scrape it through some third party way but for now lets see we can get the image to load or not but we need to get an api for that also

---

## Jul 10, 2026, 1:28 PM

now trying to debug an error but i dont know whats the error the api returns 200 but the doc or arduinojson is throwing an error

now i have an idea i will hookup an n8n workflow and then add some stats there and use graphql to easily access them here

---

## Jul 11, 2026, 3:12 AM

so i am finally back with a lot of support from claude and my choice of getting instagram stats dead now i am trying to get hackatime stats and use it to show my total coding time and my most hours on a single project for now i guess

---

## Jul 11, 2026, 4:07 AM

fixed the hackatime stats issue and now i am doing a qr code view for my social profile i will add different button that will trigger different workflow with a pull stats button and qrbutton but for now i am configuring this qr thing

---

## Jul 11, 2026, 5:22 AM

maannnn my heart just came out. I randomly deleted my board and all the code was just gone but hopefully i have saved it to in my notepad.

hopefully it works but i just forgot my pin config but i am trusting my instincts

---

## Jul 11, 2026, 10:38 AM

ok so connected pins to 4 different gpios port now i will do other things in code later on

---

## Jul 11, 2026, 11:15 AM

Noww my push button won't work its just giving 0 or low which it should give then button is not pressed but its just giving that but when i press the button its not doing any thing


will do this later on now time for a break

---

## Jul 11, 2026, 11:36 AM

so i cant configure the buttons to work so made use of different sensors like Obstacle avoidance and PIR motion sensor

---

## Jul 11, 2026, 11:53 AM

Wires (14)
1. ESP32 DevKit V1 · 3V3 -> PIR Motion Sensor · VCC
2. ESP32 DevKit V1 · 3V3 -> SSD1306 OLED (I2C) · VCC
3. ESP32 DevKit V1 · D19 -> PIR Motion Sensor · OUT
4. ESP32 DevKit V1 · D21 -> SSD1306 OLED (I2C) · SDA
5. ESP32 DevKit V1 · D22 -> SSD1306 OLED (I2C) · SCL
6. ESP32 DevKit V1 · D32 -> Obstacle Avoidance Module · OUT
7. ESP32 DevKit V1 · GND -> SSD1306 OLED (I2C) · GND
8. Full Breadboard · BN32 -> Pushbutton 4 · 1.r
9. Full Breadboard · BN38 -> Full Breadboard · G38
10. Full Breadboard · BN44 -> Pushbutton 3 · 1.r
11. Full Breadboard · BN48 -> Pushbutton 1 · 2.r
12. Full Breadboard · TN55 -> PIR Motion Sensor · GND
13. Obstacle Avoidance Module · GND -> PIR Motion Sensor · GND
14. Obstacle Avoidance Module · VCC -> PIR Motion Sensor · VCC

Breadboard plugs (16)
1. Pushbutton 1 · 1.l -> Full Breadboard · C50
2. Pushbutton 1 · 1.r -> Full Breadboard · G50
3. Pushbutton 1 · 2.l -> Full Breadboard · C48
4. Pushbutton 1 · 2.r -> Full Breadboard · G48
5. Pushbutton 2 · 1.l -> Full Breadboard · C38
6. Pushbutton 2 · 1.r -> Full Breadboard · G38
7. Pushbutton 2 · 2.l -> Full Breadboard · C36
8. Pushbutton 2 · 2.r -> Full Breadboard · G36
9. Pushbutton 3 · 1.l -> Full Breadboard · C44
10. Pushbutton 3 · 1.r -> Full Breadboard · G44
11. Pushbutton 3 · 2.l -> Full Breadboard · C42
12. Pushbutton 3 · 2.r -> Full Breadboard · G42
13. Pushbutton 4 · 1.l -> Full Breadboard · C32
14. Pushbutton 4 · 1.r -> Full Breadboard · G32
15. Pushbutton 4 · 2.l -> Full Breadboard · C30
16. Pushbutton 4 · 2.r -> Full Breadboard · G30

---

## Jul 11, 2026, 12:19 PM

Now it shows an error saying GND ISSUE FOR BOTH OF MY SENSORS WHYYYY I DONT EVEN KNOW NOW I AM JUST FIGURING IT OUTTT (sorryyy for all caps i am just confused )

ahh it was just i didnot connect the breadboard to the main pcb and also now i dont know why my buzzer is not working i am just confused i will try to look into it and make it work

---

## Jul 11, 2026, 12:44 PM

ok so now i think the buzzer wont work but now i am configuring it to be fetching stats when it senses the motion and then i need to something for the display to turn on and off according to button push or soemthing like that and then figure out things to animate and other things accordingly

---

## Jul 11, 2026, 1:02 PM

uusing this library https://github.com/styropyr0/oled.h

for the better screen animation cause it makes things look better on screen.

---

## Jul 11, 2026, 3:06 PM

Now my code doesnt work let me try to fix that but after a break

ahh it was just i forgot to remove old one 

now modifing the code to support new oled library and managing it to be more efficient with better function call and easier to use

---

## Jul 11, 2026, 3:27 PM

running it after a long writing session hope fully it works but i think i have changed mostly how we write code on screen noting more that that


maannn i make too may spelling misktakes i think i jusr corrected around 10 typos

and also i forgot to add new infront of TEXT so it was giving an error and also missed a semi collon 

and made the object two times causing it to throw an error 

then also i forgot to change the TEXT to Text so it again gave an error

---

## Jul 11, 2026, 3:38 PM

copy and pasting from one part of code to another is not a good idea you sometimes forget to many things and they give to many errorrrsss like the * i placed on the new part but it should only be used when i am changing the text

---

## Jul 12, 2026, 6:38 AM

it is compiling on local arduino ide so i think its good and i guess this sim has error running the oled library