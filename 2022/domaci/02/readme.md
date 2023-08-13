# Nic není náhoda

Peněz není nikdy dost, a proto se se vám dostává do rukou tajný soubor s taženými čísly ve sportce.

Vaším úkolem je zjistit tři nejčastěji tažená čísla v **prvním** tahu v daném období hry.
V případě, kdy je více čísel stejně častých, vypisují se ve **vzestupném** pořadí.

Program dostává na standardním vstupu (**stdin**) sekvencí tahů sportky v následujícím formátu

```
Rok;tyden;<7 čísel pro 1 tah>;<7 čísel pro 2 tah>
...

```

a na standardní výstup (**stdout**) generuje odpověď na výše popsaný problém.

Výstupem programu je výpis tří po sobě jdoucích nejčastějších čísel v prvním tahu oddělených novou řádkou (`\n`).
Posledni hodnota také musí být ukončena novou řádkou (`\n`).

Program musí skončít s návratovým kódem 0.

## Ukázkové zadání

Vstupní data

```
1980;1;32;44;24;41;37;47;30;38;19;36;17;37;27;44
1980;2;20;13;19;31;28;4;43;34;36;8;27;20;43;12
1980;3;27;3;11;2;1;48;38;8;24;26;25;29;33;6
1980;4;42;10;45;23;11;1;21;36;7;48;32;26;14;45
1980;5;30;40;38;39;37;12;3;13;38;7;30;3;27;2

```

Čísla tažená v prvním tahu jsou tedy

```
32 44 24 41 37 47 30
20 13 19 31 28 4 43
27 3 11 2 1 48 38
42 10 45 23 11 1 21
30 40 38 39 37 12 3

```

Očekávaný výstup

```
1
3
11

```
