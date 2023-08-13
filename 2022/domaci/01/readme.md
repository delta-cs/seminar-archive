# Opatovický písník

Na blízkém Opatovickém písníku je ostrov, 
na který je nutné převést tajný náklad, 
který je natolik těžký, že ho nelze převážet loďkou. 

Jediná možná doprava je po zamrzlé hladině. 
K písníku jsme umístili vysílač teplotních dat. 

Z dodaných dat je nutné zjistit, kdy je nejvhodnější doba převozu (nejsilnější led), 
a vytvořit program, který upozorní na ideální datum převozu. 

Hledáme po sobě jdoucí tři dny, které se vyznačují nejnižší teplotou.

Program dostává na standardním vstupu (**stdin**) sekvenci celých čísel a na standardní výstup (**stdout**) generuje odpověď na výše popsaný problém.

Výstupem programu je výpis tří po sobě jdoucích nejnižších teplot oddělených novou řádkou (`\n`).
Posledni hodnota také musí být ukončena  novou řádkou (`\n`).

Program musí skončit s návratovým kódem 0.

## Ukázkové zadání

Vstupní data

```
10
12
14
8
6
3
0
-2
-2
-3
-3
0
5
8

```

Očekávaný výstup

```
-2
-3
-3

```