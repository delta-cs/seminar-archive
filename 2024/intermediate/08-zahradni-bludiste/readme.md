# Zahradní bludiste
Zahradník zámecké zahrady má spoustu práce, mezi kterou patří i údržba zahradních bludišť. Keře, které je tvoří,  se musí pravidelně stříhat aby vypadaly hezky a nezasahovaly do cesty.

Zahradník ale onemocněl a musel dlouho zůstat doma. Když se vrátil, vylezl na kopeček nad zahradou a všiml si že některá bludiště zarostla tak moc, že se stala neprůchozími.

Zahradník je už starší a zrak mu neslouží tak dobře jako za mlada, takže si není jistý, zda nějaké zarostlé bludiště nepřehlédl. 

**Napište program, kterým mu pomůžete zjistit jaká bludiště jsou průchozí a která ne, aby nemusel svůj zrak moc namáhat.**

## Popis problému
Dostanete ascii art bludiště, o kterém máte zjistit, zda lze projít.

Bludiště se skládá ze znaků:
- `.` - cesta
- `#` - keř
- `S` - start bludiště
- `E` - konec bludiště

Musíte zjistit, zda se lze po cestách `.` dostat z políčka `S` do políčka `E`
\
Chodit po cestách je možné pouze nahoru-dolů a doleva-doprava, **ne diagonálně**

Pokud je bludiště průchozí, vypište `Pruchozi`
\
Pokud ne a musí se opravit, vypiste `Opravit`

## Popis vstupu
- na 1. řádku dostanete 2 celá kladná čísla `X` a `Y` **oddělená mezerou**
- bude následovat `Y` řádků reprezentujících bludiště
    - na každém z nich bude `X` znaků **oddělených mezerou**
    - znaky mohou být: `.`, `#`, `S`, `E` 
> Pozor, začátek i konec bludiště mohou být kdekoli v bludišti, ne jen na okrajích (vstup do bludiště může být z katakomb)


## Vstupy

### př 1:
Vstup:
```
5 4
# S # E #
# . # . #
# . . . #
# # # # #
```
Výstup:
```
Pruchozi
```

### př 2:
Vstup:
```
5 4
# S # E #
# . # . #
# . # . #
# # # # #
```
Výstup:
```
Opravit
```


## Nápověda
tip 1:

Představte si, že do bludiště vylijete na startu vodu a ta se postupně rozleje do všech napojených políček.
Pokud zaplaví i cíl, bludiště lze projít.
\
(nebo si zkuste nakreslit v malování bludiště a kliknout do něj pomocí paint bucketu)

tip 2:

V některých bludištích nemusí fungovat pravidlo pravé ruky.