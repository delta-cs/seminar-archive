# Žába
Kdesi v lese zhruba někde mezi Pardubicemi a Hradcem Králové se nachází malý rybník. Rybník je ale na "menším kopečku" a proto k němu vedou ne až tak malé schody, konkrétně zhruba $\infty$ schodů dlouhé.

Jednoho dne se na $x$-tém schodu ocitla žába, která by se ráda dostala zpátky domů do rybníka, tedy na $1.$ schod, kde schody končí (schody číslujeme od 1 od zhora dolů).

## Pohyb žáby
Žába se snaží vyskákat nahoru, podle toho, na kolikátém schodu zrovna je se jí to ale nemusí tak úplně podařit.

Číslo schodu, na kterém se žába právě nachazí označme jako $x$ 

- Je li $x$ **liché**, podaří se jí vyskočit na schod číslo $3x+1$
- Je li $x$ **sudé**, pak se žábě skouzne noha a spadne na $\frac{1}{2}x$

## Váš úkol?
Vaším úkolem je zjistit, kolikrát musí žába skočit, než se dostane domů na první schod (kde $x=1$)
> **Pro $x>=1$ vždy na 1. schod dojde.** \
> Neexistuje pro to matematematický důkaz, nikdo ale zatím na číslo pro které my toto neplatilo nenašel. (a pokud by se vám ho podařilo najít, budete nejspíš ve světě matematiky slavní) \
> *více najdete zde: https://cs.wikipedia.org/wiki/Collatz%C5%AFv_probl%C3%A9m*

## Vstup
- na 1. řádku dostanete číslo momentálního schodu $x$
> $x$ bude vždy kladné celé číslo $>=1$

> **POZOR: pokud nepracujete v pythonu nebo Js, $x$ se nemusí vejít do 32-bitového intiegeru, použijte 64-bitový int** *(ve většině jazyků označovaný jako long)*

## Výstup
- vypište počet skoků, který žába udělá než se dostane na schod 1

## Příklady

1)
input
```
10
```
output
```
6
```

2)
input
```
1
```
output
```
0
```