# Brainf*ck interpreter
Brainfuck (někdy je také eufemisticky nazýván Brainf\*ck nebo dokonce Brainf\*\*\*) je extrémně minimalistický ezoterický programovací jazyk.
\
Byl vytvořen pro pobavení a jako výzva programátorům, pro praktické účely není vhodný. 

Váš úkol je napsat interpretér tohoto jazyka

## Jak jazyk funguje
- Provádění kódu si lze představit jako operace nad polem buněk, každá buňka je 1 byte velká.

- Hodnoty buněk jsou před spuštěním programu nastaveny na 0 a každá buňka může obsahovat hodnoty 0 - 255. 

- Nad těmito buňkami se „pohybuje“ ukazatel, který označuje aktuální buňku, se kterou jsou prováděny operace. Tento ukazatel je při spuštění programu nastaven nad první buňku a lze ho posouvat doleva či doprava.

- Vaše pole buňek by mělo být alespoň **3000 buňek** dlouhé.


### Brainf\*ck má 8 příkazů:
Jiné znaky níže uvedené příkazy má program ignorovat.
Příkaz | Popis
-------|------
\> | Posune ukazovatel o 1 do prava
<  | Posune ukazovatel o 1 doleva
\+ | Přičte 1 do aktivní buňky (ta, na které je právě ukazovatel)
\- | Odečte 1 z aktivní buňky
.  | Vypíše hodnotu aktivní buňky v podobě ASCII znaku s kódem korespondujícím hodnotě
,  | Zapíše na aktivní buňku ASCII kód znaku z uživatelského vstupu *(jak vstup funguje je vysvětleno níže)*
[  | Pokud je hodnota aktivní buňky rovna nule, přesune ukazatele doprava za odpovídající `]`
]  | pokud je hodnota aktivní buňky různá od nuly, přesune ukazatele doleva na odpovídající `[`

- Pokud se pokusíme příčítat k buňce o hodnotě 255, buňka by měla "přetéct" na hodnotu 0 (`255 + 1 = 0`)
\
To samé platí při odečítání od 0 (`0 - 1 = 255`)
- Přetékání platí i pro pohyb ukazovatele: pokud jsme na kraji pole a pokusíme se posouvat ukazovatel dál, měl by se přemístit na opačnou stranu pole

- **Pro naši verzi přidáme ještě jeden speciální znak navíc - `|`**
\
Znak `|` označuje konec kódu a začátek případných uživatelských vstupů *(`.`)*

- **Po skončení BF. progamu vždy vypište nový řádek (`\n`)**

<!-- - Váš program by měl číst standardní vstup až po konec (`EOF`) a veškeré znaky, které nejsou příkazy ignorovat -->

- Zadání budou vždy validní formát a kód *(nikdy nebude chybět `|`, ke každé otevírací závorce `[` bude právě 1 uzavírající `]`, ...)*

### Užitečné zdroje:
- wiki: https://en.wikipedia.org/wiki/Brainfuck
- další wiki: https://esolangs.org/wiki/Brainfuck
- interpretér: https://sange.fi/esoteric/brainfuck/impl/interp/i.html
- generátor: https://copy.sh/brainfuck/text.html
> zkuste si něco v BF. napsat ve funkčním interpreteru a potom testujte se svým vlastním.

## Příklady
1)
vstup:
```
>++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.
------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.|
```

výstup:
```
Hello, World!
```
BF. program vypsal Hello, World! \
Pozor na poslední znak (`|`), označuje nám konec kódu a žádný vstup po něm není potřeba, protože tento BF. program nic ze vstupu nenačítá.\
Po `Hello, World!` má program vypsat prázdný nový řádek `\n` a poté skončit.


2)
vstup:
```
,. ,. ,. ,. ,. ,.|parrot
```

výstup:
```
parrot
```

vysvětlení:

Na vstupu je BF. program, který 6x za sebou načte znak ze vstupu a ihned potom ho vypíše.\
Po kódu následuje `|` oddělující kód a uživatelský vstup, poté samotný text vstupu `parrot`