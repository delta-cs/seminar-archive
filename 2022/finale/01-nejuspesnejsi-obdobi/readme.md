# 1. Nejúspěšnější období

_Naše firma má své zlaté období růstu za sebou. Jak dlouho trvalo?_

Ve vstupu programu bude zadáno:
1. počet měsíců `m`, které jsou uvedeny v účetnictví
2. prázdný řádek
3. `m` řádků, na každém jedno celé číslo, které znamená zisk v tomto měsíci (třeba ve stotisících Kč).

Vaším úkolem je vypsat, kolik měsíců trvalo nejdelší období růstu, to znamená, že každý následující měsíc byl zisk vyšší než předchozí.

Výstup musí být ukončen znakem nové řádky (`\n`).

## Příklad

### Vstup
```
8

23
31
12
14
15
17
11
16
```

### Výstup
```
3
```

### Vysvětlení
Nejdelší období růstu trvalo tři měsíce:

1. měsíc ze 12 na 14
2. měsíc ze 14 na 15
3. měsíc z 15 na 17

Pak zisk zase klesl.
