# 3. Domeček

_Zvířátka si postavila domeček z kamenů…_

Domeček má trojúhelníkovou střechu s mezerami mezi kameny a obdélníkový základ bez mezer. 
Střecha vždy přesahuje základnu domečku o délku jednoho kamene (na každé straně), například takto:

```
   *
  * *
 * * *
* * * *
 *****
 *****
 *****
```

Základna domu musí mít minimnální šířku 3 kameny a minimální výšku 3 kameny.

Program ve vstupu obdrží počet kamenů které jsou k dispozici a do výstupu vykreslí všechny domečky,
které se z tohoto počtu kamenů dají postavit tak, aby žádný nezbyl.
Jako symbol pro kámen bude použita hvězdička `*`.

Pokud lze postavit více domů, budou nejprve vykresleny domy s nižší střechou.
Mezi jednotlivými domy ve výstupu bude jeden prázdný řádek.

Pokud úloha nemá řešení, nevypisujte nic (ani prázdný řádek `\n`).

## Příklad

### Vstup
```
50
```

### Výstup
```
   *
  * *
 * * *
* * * *
 *****
 *****
 *****
 *****
 *****
 *****
 *****
 *****

    *
   * *
  * * *
 * * * *
* * * * *
 *******
 *******
 *******
 *******
 *******
```
